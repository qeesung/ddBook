#include <iostream>
#include <vector>
#include <string>
#include "book.pb.h"
#include "createBasicDataTable.h"
#include "createModeTable.h"
#include "createIndexDataTable.h"
#include "createNode.h"
#include "createTree.h"
#include "transferMechanism.h"

using namespace std;

int main(int argc, char const *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	ddBook::Book book;
	/** 资源文件名 */
	std::vector<string> audioFileList;
	audioFileList.push_back("../../res/0.mp3");
	audioFileList.push_back("../../res/1.mp3");
	audioFileList.push_back("../../res/2.mp3");
	audioFileList.push_back("../../res/3.mp3");
	audioFileList.push_back("../../res/4.mp3");
	audioFileList.push_back("../../res/5.mp3");
	audioFileList.push_back("../../res/6.mp3");
	audioFileList.push_back("../../res/7.mp3");
	audioFileList.push_back("../../res/8.mp3");

	int j;
	for (std::vector<string>::iterator i = audioFileList.begin(); i != audioFileList.end(); ++i)
	{
		/** 构建底层数据表 */
		appendBasicData(book.mutable_basicdatatale() , *i);//把文件资源添加到基础数据表里面去
		/** 构建索引数据映射表 */
		appendIndexDataItem(book.mutable_indexdatamaptable(),*i,j++);
	}

	/** 构建模式表 */
	std::vector<std::vector<unsigned int> > nextLists;
	for (int i = 0; i < 9; ++i)
	{
		std::vector<unsigned int> tempV;
		tempV.push_back(i);
		nextLists.push_back(tempV);
	}

	/** 测试200 - 209这段码值的映射情况 */
	ddBook::ModeTable * modeTable = book.add_modetabellist();
	for (int i = 200; i < 209 ; ++i)
	{
		appendCreateModeTableItem(modeTable , i , nextLists[i-200]);
	}


	ddBook::NodeTree *nodeTree = book.mutable_nodetree();
	/** 下面开始建立节点之间的关系 */
	std::vector<unsigned int> defaultV;
	defaultV.push_back(208);
	//1
	{
		ddBook::Node * node1 = nodeTree->add_treenode();
		std::vector<unsigned int> nextV;
		nextV.push_back(1);
		nextV.push_back(2);
		std::vector<unsigned int> transV;
		transV.push_back(1315);
		transV.push_back(1316);
		setNodeInfo(node1,200,201,-1,nextV,transV,defaultV);
	}
	//2
	{
		ddBook::Node * node2 = nodeTree->add_treenode();
		std::vector<unsigned int> nextV;
		nextV.push_back(3);
		std::vector<unsigned int> transV;
		transV.push_back(1317);
		setNodeInfo(node2,202,203,0,nextV,transV,defaultV);
	}
	//3
	{
		ddBook::Node * node3 = nodeTree->add_treenode();
		std::vector<unsigned int> nextV;
		nextV.push_back(3);
		std::vector<unsigned int> transV;
		transV.push_back(1317);
		setNodeInfo(node3,204,205,0,nextV,transV,defaultV);
	}
	//4
	{
		ddBook::Node * node4 = nodeTree->add_treenode();
		std::vector<unsigned int> nextV;
		nextV.push_back(0);
		std::vector<unsigned int> transV;
		transV.push_back(1314);
		setNodeInfo(node4,206,207,0,nextV,transV,defaultV);
	}

	book.set_curmode(ddBook::Book::GAME);
	//写入到文件里面

    {
    // Write the new address book back to disk.
	    fstream output("bookfile", ios::out | ios::trunc | ios::binary);
	    if (!book.SerializeToOstream(&output)) {
	      cerr << "Failed to write address book." << endl;
	      return -1;
	    }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
 	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}