.PHONY: all
CC = clang++
INCLUDE = -I /usr/local/include
DEFINE = -D DEBUG
CPPFLAGS = -std=c++17 -O2 -Wall -g $(INCLUDE) $(DEFINE)
SRCPATH = src
BUILDPATH = build
SCRIPTPATH = script
SRC = $(SRCPATH)/main.cpp
TARGET = $(BUILDPATH)/main

$(TARGET): $(SRC)
	-mkdir $(BUILDPATH)
	$(CC) $(CPPFLAGS) $(SRC) -o $(TARGET)

run: $(SRC)
	make $(TARGET)
	@echo /////////////////////////////////
	@./$(TARGET)
	@echo //////////////// ///////////////

cp: $(SRC)
	cat $(SRC) | $(SCRIPTPATH)/copi.sh

clean:
	rm $(BUILDPATH)/*
