#ifndef _AUDIOPLAY_H
#define _AUDIOPLAY_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define AudioPlayFifoFile ".audioPlay.fifo"

extern int audioPlayPid;//播放进程的ID

/**
 * 基本播放MP3的数据（最底层的表）
 * @param audioSource 音乐文件开始的地址
 * @param offset      偏移量
 * @param length      需要播放长度
 */
void audioPlay(const char * audioSource , const int offset , const int length);
#endif
