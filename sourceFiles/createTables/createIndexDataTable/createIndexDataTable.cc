#include "createIndexDataTable.h"
extern "C"
{
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
}

extern "C" unsigned int audioFileSize(const std::string & audioFilename)
{
	struct stat buf;
	if(stat(audioFilename.c_str() , &buf)==-1)
	{
		perror("Get the audio file stat failed");
		return 0;
	}
	return buf.st_size;
}


bool appendIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const unsigned int & fileLength,\
						 const int & index)
{
	if(indexDataMapTable == NULL)
	{
		fprintf(stderr, "%s\n","indexDataMapTable can not be null" );
		return false;
	}
	ddBook::IndexDataMapTable_IndexDataMapPair * pair = indexDataMapTable->add_indexdatamappair();
	pair->set_index(index);	
	pair->set_offset(fileLength);
	return true;
}


bool appendIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const std::string & audioFilename ,\
						 const int & index)
{
	int length = audioFileSize(audioFilename);
	if(length == 0)
		return false;
	appendIndexDataItem(indexDataMapTable , length , index);
}


bool assignIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const int & index,\
						 const unsigned int & fileLength,\
						 const int & fileIndex)
{
	if(indexDataMapTable == NULL)
	{
		fprintf(stderr, "%s\n","indexDataMapTable can not be null" );
		return false;
	}
	if(index >= indexDataMapTable->indexdatamappair_size())
	{
		fprintf(stderr, "%s%d\n","index should less than ",indexDataMapTable->indexdatamappair_size() );
		return false;
	}
	ddBook::IndexDataMapTable_IndexDataMapPair * pair = indexDataMapTable->mutable_indexdatamappair(index);
	pair->set_index(fileIndex);	
	pair->set_offset(fileLength);
	return true;
}

bool assignIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const int & index,\
						 const std::string & audioFilename,\
						 const int & fileIndex)
{
	unsigned int length = audioFileSize(audioFilename);
	if(length ==0)
		return false;
	assignIndexDataItem(indexDataMapTable ,index ,  length , fileIndex);
}