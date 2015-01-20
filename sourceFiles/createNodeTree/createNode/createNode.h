#ifndef _CREATENODE_H
#define _CREATENODE_H


#include "book.pb.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * 设置一个节点的信息
 * @param node        目标节点
 * @param startCode   开始的播放码值
 * @param endCode     结束时候播放码值
 * @param previous    上一个节点位置（父亲节点，只可以有一个，一般用不到）
 * @param nextList    下一个节点（儿子节点，可以有多个）
 * @param defaultList 默认或者独自循环的时候默认码值
 */
void setNodeInfo(ddBook::Node * node,\
	             const unsigned int & startCode,\
	             const unsigned int & endCode,\
	             const unsigned int & previous,\
	             const std::vector<unsigned int>  & nextList=std::vector<unsigned int>(),\
	             const std::vector<unsigned int>  & defaultList=std::vector<unsigned int>());

void setNodeInfo(ddBook::Node * node,\
	             const unsigned int & startCode,\
	             const unsigned int & endCode,\
	             const unsigned int & previous,\
	             const unsigned int & next,\
	             const unsigned int & defaultCode);
#endif