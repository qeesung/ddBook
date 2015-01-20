#include "createBasicDataTable.h"

bool appendBasicData(ddBook::BasicDataTable * basicDataTale ,\
				     const std::string & audioFilename)
{
	if(basicDataTale == NULL)
	{
		std::cerr<<"Basic data table can not be null"<<std::endl;
		return false;
	}
	char buf[BufSize];
	std::string dataStr;//从缓存里面取出数据追加到dataStr后面

	//打开文件
	int fd ;
	if((fd = open(audioFilename.c_str() , O_RDONLY))==-1)
	{
		perror("Open the audio file failed");
		return false;
	}
	int size;
	//读取文件
	while(1)
	{
		if((size = read(fd , buf , BufSize))<=0)
			break;
		std::string tempData(buf , buf+size);
		dataStr+=tempData;
	}
	//写入到表里面
	basicDataTale->add_audiodata(dataStr.c_str() , dataStr.size());
	return true;
}


bool assignBasicData(ddBook::BasicDataTable * basicDataTale ,\
					 const std::string & audioFilename,\
					 const int & index)
{
	if(basicDataTale == NULL)
	{
		std::cerr<<"Basic data table can not be null"<<std::endl;
		return false;
	}
	if(index >= basicDataTale->audiodata_size())
	{
		std::cerr<<"The index should less than "<<basicDataTale->audiodata_size()<<std::endl;
		return false;
	}
	//打开文件
	int fd ;
	char buf[BufSize];
	std::string dataStr;
	if((fd = open(audioFilename.c_str() , O_RDONLY))==-1)
	{
		perror("Open the audio file failed");
		return false;
	}
	int size;
	//读取文件
	while(1)
	{
		if((size = read(fd , buf , BufSize))<=0)
			break;
		std::string tempData(buf , buf+size);
		dataStr+=tempData;
	}
	//赋值到表里面
	basicDataTale->set_audiodata(index  , dataStr.c_str() , dataStr.size());
	return true;
}