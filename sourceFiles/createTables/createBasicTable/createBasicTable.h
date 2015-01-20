#ifndef _CREATEBASICTABLE_H
#define _CREATEBASICTABLE_H

#include "book.pb.h"
#include <iostream>
#include <string>
#include <fstream>

extern "C"
{
	#include <stdio.h>
	#include <stdlib.h>
	#include <fcntl.h>
	#include <unistd.h>
}

#define BufSize 1024
////////////////
//创建最底层数据表的一些函数 //
//////////////////

//这一层表的接口主要职责就是将文件数据写入到表中对应的index里面

/**
 * 在basicDataTable后面追加相应的音乐音频文件资源
 * @param  basicDataTale 目标表
 * @param  audioFilename 资源文件名
 * @return               创建成功返回true 失败false
 */
bool appendBasicData(ddBook::BasicDataTable * basicDataTale ,\
				     const std::string & audioFilename);

/**
 * 赋值给基础表index位置的数据
 * @param basicDataTale 目标表
 * @param audioFilename 文件名字
 * @param index         目标位置
 * @return              赋值成功返回true 失败false
 */
bool assignBasicData(ddBook::BasicDataTable * basicDataTale ,\
					 const std::string & audioFilename,\
					 const int & index);




#endif