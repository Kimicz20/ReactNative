SHELL = /bin/bash
CC=g++                                                                                                         
DIR=src
SUBDIRS=src/Main\
	src/Copter\
	src/RCInput\
	src/Parameter\
	src/Semaphone\
	src/Socket\
	src/SupportClass\
	obj
BIN=Server
OBJS_DIR=obj
BIN_DIR=bin

all:$(SUBDIRS)

$(SUBDIRS): ECHO
	make -C $@
ECHO:
	@echo "所有的需要进入的文件"
	@echo $(SUBDIRS)
	@echo "############开始循环编译cpp文件############"
exec:
	@echo "############执行服务端程序############"
	@./$(BIN_DIR)/$(BIN)
clean:
	@$(RM) $(OBJS_DIR)/*.o

.PHONY: all clean
