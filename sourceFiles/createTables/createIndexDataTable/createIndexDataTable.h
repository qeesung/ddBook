#ifndef _CREATEINDEXDATATABLE_H
#define _CREATEINDEXDATATABLE_H

#include "book.pb.h"
#include <iostream>
#include <string>

extern "C"
{
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
}

/**
 * 得到一个音频文件的长度		
 * @param  audioFilename 音频文件名字	
 * @return               文件长度
 */
extern "C" unsigned int audioFileSize(const std::string & audioFilename);

/**
 * 在indexDataMpa映射表里面添加一个项
 * @param  indexDataMapTable 目标表
 * @param  audioFilename     文件名字
 * @param  index 		     索引值
 * @return                   插入成功true ， 插入失败false
 */
bool appendIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const std::string & audioFilename ,\
						 const int & index);

/**
 * 在indexDataMpa映射表里面添加一个项
 * @param  indexDataMapTable 目标表
 * @param  fileLength        文件长度
 * @param  index             索引值
 * @return                   插入成功true ， 插入失败false
 */
bool appendIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const unsigned int & fileLength,\
						 const int & index);

/**
 * 将index位置的文件替换为audioFilename的索引
 * @param  indexDataMapTable 目标表
 * @param  index             表内索引
 * @param  audioFilename     文件名
 * @param  fileIndex         文件索引
 * @return                   赋值成功true ， 失败false
 */
bool assignIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const int & index,\
						 const std::string & audioFilename,\
						 const int & fileIndex);

/**
 * 将index位置的文件替换为audioFilename的索引
 * @param  indexDataMapTable 目标表
 * @param  index             目标索引
 * @param  fileLength        文件长度
 * @param  fileIndex         文件索引
 * @return                   赋值成功true ， 失败false
 */
bool assignIndexDataItem(ddBook::IndexDataMapTable * indexDataMapTable ,\
						 const int & index,\
						 const unsigned int & fileLength,\
						 const int & fileIndex);
#endif