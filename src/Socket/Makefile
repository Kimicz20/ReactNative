OBJS_DIR=../obj
CC=g++
all:../$(OBJS_DIR)/serverSocket.o ../$(OBJS_DIR)/Socket.o
../$(OBJS_DIR)/serverSocket.o:ServerSocket.cpp
	$(CC) -c $^ -o $@
../$(OBJS_DIR)/Socket.o: Socket.cpp
	$(CC) -c $^ -o $@
