CC = gcc
CDFLAGS = -g -Wall -Werror -pedantic-errors -Iinclude
SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./build
CFLAGS = -Wall -Werror -pedantic-errors -Iinclude -O3

.PHONY: all clean debug lowercase sortargs lowercase_d sortargs_d
all: build	

build: lowercase sortargs

lowercase: $(BUILD_DIR)/release $(BUILD_DIR)/release/lowercase.o $(BUILD_DIR)/release/mystring.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/release/lowercase.o $(BUILD_DIR)/release/mystring.o -o $(BUILD_DIR)/release/lowercase

sortargs: $(BUILD_DIR)/release $(BUILD_DIR)/release/linked_list.o $(BUILD_DIR)/release/node.o $(BUILD_DIR)/release/sortargs.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/release/linked_list.o $(BUILD_DIR)/release/node.o $(BUILD_DIR)/release/sortargs.o -o $(BUILD_DIR)/release/sortargs

$(BUILD_DIR)/release:
	mkdir -p $(BUILD_DIR)/release

$(BUILD_DIR)/release/linked_list.o: $(SRC_DIR)/linked_list.c $(INCLUDE_DIR)/linked_list.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/linked_list.c -o $(BUILD_DIR)/release/linked_list.o

$(BUILD_DIR)/release/lowercase.o: $(SRC_DIR)/lowercase.c $(INCLUDE_DIR)/mystring.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/lowercase.c -o $(BUILD_DIR)/release/lowercase.o

$(BUILD_DIR)/release/mystring.o: $(SRC_DIR)/mystring.c $(INCLUDE_DIR)/mystring.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/mystring.c -o $(BUILD_DIR)/release/mystring.o

$(BUILD_DIR)/release/node.o: $(SRC_DIR)/node.c $(INCLUDE_DIR)/node.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/node.c -o $(BUILD_DIR)/release/node.o

$(BUILD_DIR)/release/sortargs.o: $(SRC_DIR)/sortargs.c $(INCLUDE_DIR)/linked_list.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/sortargs.c -o $(BUILD_DIR)/release/sortargs.o


debud: lowercase_d sortargs_d

lowercase_d: $(BUILD_DIR)/debug $(BUILD_DIR)/debug/lowercase.o $(BUILD_DIR)/debug/mystring.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/debug/lowercase.o $(BUILD_DIR)/debug/mystring.o -o $(BUILD_DIR)/debug/lowercase

sortargs_d: $(BUILD_DIR)/debug $(BUILD_DIR)/debug/linked_list.o $(BUILD_DIR)/debug/node.o $(BUILD_DIR)/debug/sortargs.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/debug/linked_list.o $(BUILD_DIR)/debug/node.o $(BUILD_DIR)/debug/sortargs.o -o $(BUILD_DIR)/debug/sortargs

$(BUILD_DIR)/debug:
	mkdir -p $(BUILD_DIR)/debug

$(BUILD_DIR)/debug/linked_list.o: $(SRC_DIR)/linked_list.c $(INCLUDE_DIR)/linked_list.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/linked_list.c -o $(BUILD_DIR)/debug/linked_list.o

$(BUILD_DIR)/debug/lowercase.o: $(SRC_DIR)/lowercase.c $(INCLUDE_DIR)/mystring.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/lowercase.c -o $(BUILD_DIR)/debug/lowercase.o

$(BUILD_DIR)/debug/mystring.o: $(SRC_DIR)/mystring.c $(INCLUDE_DIR)/mystring.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/mystring.c -o $(BUILD_DIR)/debug/mystring.o

$(BUILD_DIR)/debug/node.o: $(SRC_DIR)/node.c $(INCLUDE_DIR)/node.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/node.c -o $(BUILD_DIR)/debug/node.o

$(BUILD_DIR)/debug/sortargs.o: $(SRC_DIR)/sortargs.c $(INCLUDE_DIR)/linked_list.h
	$(CC) -c $(CFLAGS) $(SRC_DIR)/sortargs.c -o $(BUILD_DIR)/debug/sortargs.o

clean:
	rm -rf $(BUILD_DIR)
