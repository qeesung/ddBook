/**
 * 测试audioPlay()的main函数,测试成功
 */
#include <stdio.h>
#include "audioPlay.h"
#define BufferSize 50000

int main(int argc, char const *argv[])
{
	char source[BufferSize];		
	int i=0;
	int fd ;
	if((fd = open("../../res/all.mp3",O_RDONLY))==-1)
	{
		perror("Open the mp3 file failed");		
		return -1;
	}
	if(read(fd , source , BufferSize)==-1)
	{
		perror("read the file failed");
		return -1;
	}
	audioPlay(source , 16318, 12452);
	return 0;
}