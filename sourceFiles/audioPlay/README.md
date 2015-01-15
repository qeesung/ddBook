#audioPlay

---

##基于C语言编写的 mpg123 音乐播放器来实现对一个总和的音乐文件的播放 
- audioPlay.h audioPlay.c 接口及其实现
- main.c makefile 测试audPlay接口的测试文件,可删除

```
/**
 * 基本播放MP3的数据（最底层的表）
 * @param audioSource 音乐文件开始的地址
 * @param offset      偏移量
 * @param length      需要播放长度
 */
void audioPlay(const char * audioSource , const int offset , const int length);
```