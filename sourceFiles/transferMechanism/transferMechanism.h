#ifndef _TRANSFERMECHANISM_H
#define _TRANSFERMECHANISM_H

#include "book.pb.h"
#include <iostream>
#include <string>
extern "C"
{
	#include "audioPlay.h"
	#include <stdio.h>
	#include <stdlib.h>
}

/** 产生一个随机数的宏 */
#define random(x) (rand()%x)

/**
 * C++状态转移机制
 * @param book        目标的转移点读书
 * @param startCode   在树里面开始的那个节点
 */
void stateTransfer(ddBook::Book * book , const unsigned int & startNode);

/**
 * 打印一个节点的详细信息
 * @param book       目标书
 * @param curNodePos 当前节点的索引
 */
void printNodeInfo(ddBook::Book & book , const int curNodePos);
void printNodeInfo(ddBook::Node & node);

/**
 * 播放一个节点playCode对应的音频
 * @param playCode          播放码值
 * @param modeTable         模式表
 * @param indexDataMapTable 索引数据映射表
 * @param basicDataTale     基本数据表
 */
void nodeAudioPlay(const unsigned int & playCode,\
				   const ddBook::ModeTable & modeTable,\
				   const ddBook::IndexDataMapTable & indexDataMapTable,\
				   const ddBook::BasicDataTable & basicDataTale);

#endif