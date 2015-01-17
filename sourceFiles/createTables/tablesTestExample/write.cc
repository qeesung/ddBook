#include <iostream>
#include <fstream>
#include <vector>
#include "book.pb.h"
#include "audioPlay.h"
extern "C"
{
	#include <stdio.h>
	#include <stdlib.h>
}

using namespace std;


void createNodeTree(ddBook::NodeTree* nodeTree)
{
	//////////////
	//创建节点树的函数
	//这里测试的节点有三个
	//互相之间为链表 
	//////////////
	ddBook::Node * node1 = nodeTree->add_treenode();
	ddBook::Node * node2 = nodeTree->add_treenode();
	ddBook::Node * node3 = nodeTree->add_treenode();
	node1->set_startcode(200);
	node1->set_endcode(201);
	node1->set_previous(-1);
	node1->add_next(2);
	node1->add_defaultcode(100);

	node2->set_startcode(300);
	node2->set_endcode(301);
	node2->set_previous(2);
	node2->add_next(-1);
	node2->add_defaultcode(100);
	
	node3->set_startcode(400);
	node3->set_endcode(401);
	node3->set_previous(0);
	node3->add_next(1);
	node3->add_defaultcode(100);
}


void createModeTable(ddBook::ModeTable *modeTable)
{
	ddBook::ModeTable_CodeIndexMapPair * pair1 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair2 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair3 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair4 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair5 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair6 = modeTable->add_codeindexmappair();
	ddBook::ModeTable_CodeIndexMapPair * pair7 = modeTable->add_codeindexmappair();

	pair1->set_code(200);
	pair1->add_indexlist(1);

	pair2->set_code(201);
	pair2->add_indexlist(2);

	pair3->set_code(300);
	pair3->add_indexlist(2);

	pair4->set_code(301);
	pair4->add_indexlist(3);

	pair5->set_code(400);
	pair5->add_indexlist(3);

	pair6->set_code(401);
	pair6->add_indexlist(1);

	pair7->set_code(100);
	pair7->add_indexlist(0);

}

void createIndexDataMapTable(ddBook::IndexDataMapTable * indexDataMapTable ,\
							 const unsigned int indexArray[] ,\
							 const int arrayLength)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		ddBook::IndexDataMapTable_IndexDataMapPair * pair = indexDataMapTable->add_indexdatamappair();
		pair->set_index(i);
		pair->set_offset(indexArray[i]);
	}
}

void createBasicDataTable(ddBook::BasicDataTable * basicDataTale , const vector<string> & v1)
{
	const int & bufSize = 50000;
	char buf[bufSize];
	for (int i = 0; i < v1.size(); ++i)
	{
		int fd;
		if((fd = open(v1[i].c_str() , O_RDONLY))==-1)
		{
			perror("Open audio file failed");
			return ;
		}
		int size;
		if((size=read(fd , buf , bufSize))==-1)
		{
			perror("read the audio file failed");
			return;
		}
		basicDataTale->add_audiodata(buf,size);
	}
}

int main(int argc, char const *argv[])
{

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	const unsigned int indexData[]={16318,12452,13288,14438};
	std::vector<string> filenameVector;
	filenameVector.push_back("../../../res/1.mp3");
	filenameVector.push_back("../../../res/2.mp3");
	filenameVector.push_back("../../../res/3.mp3");
	filenameVector.push_back("../../../res/4.mp3");

	ddBook::Book book;

	//设置模式
	book.set_curmode(::ddBook::Book::STUDY);
	//获得树的节点
	ddBook::NodeTree *nodeTree = book.mutable_nodetree();
	createNodeTree(nodeTree);
	//创建模式表
	ddBook::ModeTable * modeTable = book.add_modetabellist();
	createModeTable(modeTable);
	//创建索引表
	ddBook::IndexDataMapTable * indexDataMapTable = book.mutable_indexdatamaptable();
	createIndexDataMapTable(indexDataMapTable , indexData , sizeof(indexData)/sizeof(unsigned int));
	//创建基础表
	ddBook::BasicDataTable * basicDataTale = book.mutable_basicdatatale();
	createBasicDataTable(basicDataTale , filenameVector);

    {
    // Write the new address book back to disk.
	    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
	    if (!book.SerializeToOstream(&output)) {
	      cerr << "Failed to write address book." << endl;
	      return -1;
	    }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
 	google::protobuf::ShutdownProtobufLibrary();


	return 0;
}
