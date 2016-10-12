CC=g++
BIN=Server
OBJS= Copter.o RCInput.o test.o serverSocket.o mainSem.o parameter.o Socket.o supportClass.o
BIN_DIR=bin

../$(BIN_DIR)/$(BIN):$(OBJS)
	#$(CC) -o $@ $^
	$(CC) -lpthread -o $@ $^
