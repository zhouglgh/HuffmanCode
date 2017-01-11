
FILE_CPP=DoubleLink.cpp Arrays.cpp Hman.cpp Tree.cpp
FILE_H=Doublink.h Arrays.h Hman.h Tree.h
FILE_M=main.cpp

PARA=-std=c++11
CC=g++


target:
	${CC} ${PARA} ${FILE_CPP} ${FILE_M} -o app
gdb:
	${CC} ${PARA} -g ${FILE_CPP} ${FILE_M} -o app.gdb
