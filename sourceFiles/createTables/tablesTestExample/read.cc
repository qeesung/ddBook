#include <iostream>
#include <fstream>
#include "book.pb.h"
extern "C"
{
	#include "audioPlay.h"
}

using namespace std;

void printNodeInfo(ddBook::Book & book , const int curNodePos)
{
	ddBook::NodeTree nodeTree = book.nodetree();
	if(curNodePos >= nodeTree.treenode_size())
	{
		cerr<<"curNodePos is greater than treeNodeSize"<<endl;		
		return;
	}
	cout<<"=======Node"<<curNodePos<<"======"<<endl;
	cout<<"startCode:\t"<<nodeTree.treenode(curNodePos).startcode()<<endl;
	cout<<"endCode:\t"<<nodeTree.treenode(curNodePos).endcode()<<endl;
	cout<<"previous:\t"<<nodeTree.treenode(curNodePos).previous()<<endl;
	cout<<"next   :\t"<<nodeTree.treenode(curNodePos).next(0)<<endl;
	cout<<"defaultcode:\t"<<nodeTree.treenode(curNodePos).defaultcode(0)<<endl;
	cout<<"++++++Node"<<curNodePos<<"++++++"<<endl;
}

int main(int argc, char const *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	if (argc != 2) {
	    cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
	    return -1;
	}
	ddBook::Book book;

	{
	    fstream input(argv[1], ios::in | ios::binary);
	    if (!book.ParseFromIstream(&input)) {
	      cerr << "Failed to parse address book." << endl;
	      return -1;
	    }
    }

	int offset=0;
	int index=0;
	int code=0;//节点码
	int curNodePos=0;//当前节点位置
	while(1)
	{
		index =0;
		printNodeInfo(book , curNodePos);
		cout<<"Enter Code>"<<flush;
		cin>>code;
		if(code == -1)
			break;
		// 取得index
		ddBook::ModeTable modeTable = book.modetabellist(0);//第一场就是STUDY表
		for (int i = 0; i <modeTable.codeindexmappair_size(); ++i)
		{
			ddBook::ModeTable_CodeIndexMapPair pair = modeTable.codeindexmappair(i);
			if(pair.code() == code)
			{
				index = pair.indexlist(0);
				break;
			}
		}
		cerr<<"index is "<<index<<endl;
		// 取得index的偏移量
		ddBook::IndexDataMapTable indexDataTable = book.indexdatamaptable();
		ddBook::IndexDataMapTable_IndexDataMapPair indexDataPair = indexDataTable.indexdatamappair(index);
		offset = indexDataPair.offset();

		//取得资源位置
		ddBook::BasicDataTable basicDataTable = book.basicdatatale();
		string str = basicDataTable.audiodata(index);
		//播放资源
		audioPlay(str.c_str() , 0 , offset);
	}
    google::protobuf::ShutdownProtobufLibrary();
	return 0;
}