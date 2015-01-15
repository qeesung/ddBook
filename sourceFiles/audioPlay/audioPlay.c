#include "audioPlay.h"

int audioPlayPid=-1;

void audioPlay(const char * audioSource , const int offset , const int length)
{
	if(audioSource == NULL || length ==-1)
	{
		fprintf(stderr, "%s\n","Open source is not exists" );
		return ;
	}
	/** 检测fifo文件存在与否 */
	if(access(AudioPlayFifoFile , F_OK)==-1)
	{
		if(mkfifo(AudioPlayFifoFile , 0777)==-1)
		{
			perror("Create Audio fifo file failed");
			exit(EXIT_FAILURE);
		}
	}
	char buf[512];
	int fifo_fd;
	pid_t pid;
	int i;
	/** 为了防止被阻塞，每次播放音乐之前都要将播放进程kill */
	sprintf(buf ,"%d",audioPlayPid);
	if(audioPlayPid != -1)
		execl("/bin/kill" , "-s" , "9" ,buf,(char *)0);
	////////////////////////
	//创建两个进程 一个负责写 一个负责读 //
	////////////////////////
	if((pid = fork())==-1)
	{
		perror("fork sub process failed");
		exit(EXIT_FAILURE);
	}
	if(pid==0)// child write
	{

		/** 写方式打开fifo文件 */
		fprintf(stderr, "%s\n","Ready to write audio source..." );
		if((fifo_fd = open(AudioPlayFifoFile , O_WRONLY))==-1)
		{
			perror("Open fifo file failed");
			exit(EXIT_FAILURE);
		}
		for(i=offset ; i<offset + length;++i)
		{
			write(fifo_fd , &audioSource[i] , sizeof(char));
		}
	}
	else
	{//father read
		/** 基于mpg123 读方式打开fifo文件 */
		fprintf(stderr, "%s\n","Ready to read audio source..." );
		sprintf(buf, "%s %s","mpg123",AudioPlayFifoFile);
		if((audioPlayPid = system(buf))==-1)
		{
			perror("read audio source ");
			return;
		}
	}
}