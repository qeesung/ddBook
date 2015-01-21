#include "createTree.h"

void addChild(ddBook::Node * node ,\
              const unsigned int & childIndex,\
              const unsigned int & transCode)
{
	if(node == NULL)
	{
		fprintf(stderr, "%s\n","parent node can not be null");
		return;
	}
	node->add_next(childIndex);
	node->add_transcode(transCode);
}

void addDefaultAudio(ddBook::Node * node , const unsigned int & defaultCode)
{
	if(node == NULL)
	{
		fprintf(stderr, "%s\n","Node can not be null" );
		return;
	}
	node->add_defaultcode(defaultCode);
}

void addTreeNode(ddBook::NodeTree* nodeTree , const ddBook::Node & node)
{
		ddBook::Node * newNode = nodeTree->add_treenode();
		newNode->set_startcode(node.startcode());
		newNode->set_endcode(node.endcode());
		newNode->set_previous(node.previous());
		for (int i = 0; i < node.next_size(); ++i)
		{
			newNode->add_next(node.next(i));
		}

		for (int i = 0; i < node.transcode_size(); ++i)
		{
			newNode->add_transcode(node.transcode(i));
		}

		for (int i = 0; i < node.defaultcode_size(); ++i)
		{
			newNode->add_defaultcode(node.defaultcode(i));
		}
}