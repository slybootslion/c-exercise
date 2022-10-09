CC := gcc
INCLUDE_DIR := -I ../include
OBJ_DIR := ${shell pwd}/obj
BIN_DIR := ${shell pwd}/bin
SUB_DIR := main fun global obj
TARGET := my_exec

export CC
export INCLUDE_DIR
export BIN_DIR
export OBJ_DIR
export SUB_DIR
export TARGET

all:$(SUB_DIR)

$(SUB_DIR) : MK_BIN
	make -C $@

MK_BIN:
	mkdir -p ${BIN_DIR}

clean:
	rm -rf ./bin ./obj/*.o

install:
	cp $(BIN_DIR)/$(TARGET) /usr/bin

uninstall:
	rm -f /usr/bin/$(TARGET)
