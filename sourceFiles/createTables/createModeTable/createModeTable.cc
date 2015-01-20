#include "createModeTable.h"

void appendCreateModeTableItem(ddBook::ModeTable *modeTable,\
							   const unsigned int & code,\
							   const std::vector<unsigned int> & indexList)
{
	if(modeTable==NULL)
	{
		perror("ModeTable can not be null");
		return;
	}
	//添加一项
	ddBook::ModeTable_CodeIndexMapPair * pair = modeTable->add_codeindexmappair();
	pair->set_code(code);
	for (std::vector<unsigned int>::const_iterator i = indexList.begin(); i != indexList.end(); ++i)
	{
		pair->add_indexlist(*i);
	}
	return;
}