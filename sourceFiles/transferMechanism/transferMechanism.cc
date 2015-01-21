#include "transferMechanism.h"
#include <iostream>

void stateTransfer(ddBook::Book * book , const unsigned int & startNode)
{
	if(book==NULL)
	{
		std::cerr<<"input book can not be null"<<std::endl;
		return;
	}
	/** 设置三个预先设定的模式码值 */
	const unsigned int & studyCode = 111;
	const unsigned int & storyCode = 222;
	const unsigned int & gameCode = 333;

	/** 获得书本的基本信息 */
	ddBook::Book_ModeType MODE = book->curmode();
	ddBook::NodeTree nodeTree = book->nodetree();
	ddBook::ModeTable modeTable = book->modetabellist(MODE);
	ddBook::IndexDataMapTable indexDataMapTable = book->indexdatamaptable();
	ddBook::BasicDataTable basicDataTale = book->basicdatatale();
	/** 取得树里的起始节点*/
	ddBook::Node curNode = nodeTree.treenode(startNode);
	bool ifTransfered =true;//用来标注时候发生了转移
	while(1)
	{
		printNodeInfo(curNode);
		/** 播放节点的入口音频 */
		if(ifTransfered)
		{
			nodeAudioPlay(curNode.startcode(),\
				          modeTable,\
				          indexDataMapTable,\
				          basicDataTale);
			ifTransfered = false;
		}
		/** 等待用户输入 */
		std::cout<<"input code>";
		unsigned int inputCode=0;
		std::cin>>inputCode;
		/** 下面判断用户的输入 */

		/** 首先检查是不是模式码值 */
		if(inputCode == studyCode)
			MODE = ddBook::Book::STUDY;
		else if (inputCode == storyCode)
			MODE = ddBook::Book::STORY;
		else if(inputCode == gameCode)
			MODE = ddBook::Book::GAME;
		/** 获得对应的mode表 */
		ddBook::ModeTable modeTable = book->modetabellist(MODE);

		/** 检查在transCode里面时候有匹配的转移码值 */
		for (int i = 0; i < curNode.transcode_size(); ++i)
		{
			if(curNode.transcode(i) == inputCode)
			{
				//播放节点退出码
				nodeAudioPlay(curNode.endcode(),\
				          modeTable,\
				          indexDataMapTable,\
				          basicDataTale);
				//开始节点转移
				curNode = nodeTree.treenode(curNode.next(i));
				ifTransfered = true;
			}
		}
		if(ifTransfered)
			continue;
		/** 在transCode里面没有找到转移码，下面随机播放预先设定好的defaultAudio */
		unsigned int defaultPlayCode = curNode.defaultcode(random(curNode.defaultcode_size()));
		/** 播放默认的音频码 */
		nodeAudioPlay(defaultPlayCode,\
				          modeTable,\
				          indexDataMapTable,\
				          basicDataTale);

	}



}

void printNodeInfo(ddBook::Book & book , const int curNodePos)
{
	ddBook::NodeTree nodeTree = book.nodetree();
	if(curNodePos >= nodeTree.treenode_size())
	{
		std::cerr<<"curNodePos is greater than treeNodeSize"<<std::endl;		
		return;
	}
	std::cout<<"=======Node"<<curNodePos<<"======"<<std::endl;
	std::cout<<"startCode:\t"<<nodeTree.treenode(curNodePos).startcode()<<std::endl;
	std::cout<<"endCode:\t"<<nodeTree.treenode(curNodePos).endcode()<<std::endl;
	std::cout<<"previous:\t"<<nodeTree.treenode(curNodePos).previous()<<std::endl;

	for (int i = 0; i < nodeTree.treenode(curNodePos).next_size(); ++i)
	{
		std::cout<<"next   :\t"<<nodeTree.treenode(curNodePos).next(i)<<std::endl;
	}
	for (int i = 0; i < nodeTree.treenode(curNodePos).transcode_size(); ++i)
	{
		std::cout<<"transCode:\t"<<nodeTree.treenode(curNodePos).transcode(i)<<std::endl;
	}

	for (int i = 0; i < nodeTree.treenode(curNodePos).defaultcode_size(); ++i)
	{
	std::cout<<"defaultcode:\t"<<nodeTree.treenode(curNodePos).defaultcode(i)<<std::endl;
	}
	std::cout<<"++++++Node"<<curNodePos<<"++++++"<<std::endl;
}

void printNodeInfo(ddBook::Node & node)
{
	std::cout<<"=======Node"<<"======"<<std::endl;
	std::cout<<"startCode:\t"<<node.startcode()<<std::endl;
	std::cout<<"endCode:\t"<<node.endcode()<<std::endl;
	std::cout<<"previous:\t"<<node.previous()<<std::endl;
	for (int i = 0; i < node.next_size(); ++i)
	{
		std::cout<<"next   :\t"<<node.next(i)<<std::endl;
	}
	for (int i = 0; i < node.transcode_size(); ++i)
	{
		std::cout<<"transCode:\t"<<node.transcode(i)<<std::endl;
	}
	for (int i = 0; i < node.defaultcode_size(); ++i)
	{
	std::cout<<"defaultcode:\t"<<node.defaultcode(i)<<std::endl;
	}
	std::cout<<"++++++Node"<<"++++++"<<std::endl;
}


void nodeAudioPlay(const unsigned int & playCode,\
				   const ddBook::ModeTable & modeTable,\
				   const ddBook::IndexDataMapTable & indexDataMapTable,\
				   const ddBook::BasicDataTable & basicDataTable)
{
	//如果playcode是0，表明没有对应的音频
	if(playCode == 0)
		return;
	int offset=0;
	int index=0;
	//种下随机数的种子
	srand((int)time(0));
	//搜寻索引表里面的code匹配项目
    for (int i = 0; i <modeTable.codeindexmappair_size(); ++i)
	{
		ddBook::ModeTable_CodeIndexMapPair pair = modeTable.codeindexmappair(i);
		if(pair.code() == playCode)
		{
			//这里或者多个index里面中的一个，随机的
			index = pair.indexlist(random(pair.indexlist_size()));
			break;
		}
	}
	/** 取得index对应的偏移量 */
	ddBook::IndexDataMapTable_IndexDataMapPair indexDataPair = indexDataMapTable.indexdatamappair(index);
	offset = indexDataPair.offset();

	/** 取得播放资源 */
	std::string str = basicDataTable.audiodata(index);
	/** 播放对应的资源 */
	audioPlay(str.c_str() , 0 , offset);

}