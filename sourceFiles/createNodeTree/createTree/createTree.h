#ifndef _CREATETREE_H
#define _CREATETREE_H

#include "book.pb.h"
#include <iostream>
#include <string>

/** 创建节点树的基本通用接口 */

/**
 * 为一个父亲节点添加一个孩子节点
 * @param node       父亲节点
 * @param childIndex 孩子节点的索引值
 */
void addChild(ddBook::Node * node , const unsigned int & childIndex);


/**
 * 为一个节点设置添加默认的语音
 * @param node        目标节点
 * @param defaultCode 新的默认码值
 */
void addDefaultAudio(ddBook::Node * node , const unsigned int & defaultCode);

/**
 * 为逻辑树添加一个孩子节点
 * @param nodeTree 目标树
 * @param node     目标节点
 */
void addTreeNode(ddBook::NodeTree* nodeTree , const ddBook::Node & node);


#endif