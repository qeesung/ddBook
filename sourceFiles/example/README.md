#C++编写的状态转移机

##write
编译方法：make -f writeMakefile  
执行方法：./write,此处会自动生成bookfile目标文件  

---
##read
编译方法：make -f readMakefile  
执行方法：./read bookfile  

---
##在这个例子中节点之间的逻辑关系
```
	节点信息：
	节点---入口音频---结束音频---默认音频---转移码值---转移节点
	0      0	  1	     8		1315,1316  1,2
	1      2	  3	     8		1317       3
	2      4	  5	     8		1317       3
	3      6	  7	     8		1314       0

	逻辑关系：	
	节点0--->输入1315--->节点1
	节点0--->输入1316--->节点2
	节点1--->输入1317--->节点3
	节点2--->输入1317--->节点3
	节点3--->输入1314--->节点0
```

