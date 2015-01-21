#include "createNode.h"

void setNodeInfo(ddBook::Node * node,\
	             const unsigned int & startCode,\
	             const unsigned int & endCode,\
	             const unsigned int & previous,\
	             const std::vector<unsigned int>  & nextList,\
	             const std::vector<unsigned int>  & transList,\
	             const std::vector<unsigned int>  & defaultList)
{
	node->set_startcode(startCode);
	node->set_endcode(endCode);
	node->set_previous(previous);
	for (std::vector<unsigned int>::const_iterator i = nextList.begin(); i != nextList.end(); ++i)
	{
		node->add_next(*i);
	}
	for (std::vector<unsigned int>::const_iterator i = transList.begin(); i != transList.end(); ++i)
	{
		node->add_transcode(*i);
	}
	for (std::vector<unsigned int>::const_iterator i = defaultList.begin(); i != defaultList.end(); ++i)
	{
		node->add_defaultcode(*i);
	}
	return;
}


void setNodeInfo(ddBook::Node * node,\
	             const unsigned int & startCode,\
	             const unsigned int & endCode,\
	             const unsigned int & previous,\
	             const unsigned int & next,\
	             const unsigned int & transCode,\
	             const unsigned int & defaultCode)
{
	node->set_startcode(startCode);
	node->set_endcode(endCode);
	node->set_previous(previous);
	node->add_next(next);
	node->add_transcode(transCode);
	node->add_defaultcode(defaultCode);
}