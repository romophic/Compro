.PHONY: all
CC = clang++
INCLUDE = -I /usr/local/include
DEFINE = -D DEBUG
CPPFLAGS = -std=c++17 -O2 -Wall -g $(INCLUDE) $(DEFINE)
SRCPATH = src/
BUILDPATH = build/
SCRIPTPATH = script/
SRC = $(SRCPATH)main.cpp
TARGET = $(BUILDPATH)main

$(TARGET): $(SRC)
	$(CC) $(CPPFLAGS) $(SRC) -o $(TARGET)

run: $(SRC)
	make $(TARGET)
	@echo /////////////////////////////////
	@./$(TARGET)
	@echo //////////////// ///////////////

cp: $(SRC)
	bash $(SCRIPTPATH)copy.sh

clean:
	rm $(BUILDPATH)*

check:
	bash $(SCRIPTPATH)checker.sh
