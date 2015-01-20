#ifndef _CREATEMODETABLE_H
#define _CREATEMODETABLE_H

#include "book.pb.h"
#include <iostream>
#include <string>
#include <vector>
extern "C"
{
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
}

//这个是创建模式表里面的内容需要的各种接口需要的各种接口

/**
 * 在modetable里面添加一个code与index映射的项
 * @param modeTable 模式表
 * @param code      对应的码值
 * @param indexList 对应的各个index，可能一个code对应对个index
 */
void appendCreateModeTableItem(ddBook::ModeTable *modeTable,\
							   const unsigned int & code,\
							   const std::vector<unsigned int> & indexList);

#endif