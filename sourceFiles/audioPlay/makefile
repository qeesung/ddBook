play:main.o audioPlay.o
	gcc main.o audioPlay.o -o play

main.o:audioPlay.h
audioPlay.o:audioPlay.h

.PHONY:clean

clean:
	rm -f *.o