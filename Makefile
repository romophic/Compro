.PHONY: all
CC = clang++
INCLUDE = -I /usr/local/include
DEFINE = -D DEBUG
CPPFLAGS = -std=c++17 -O2 -Wall -g -v $(INCLUDE) $(DEFINE)
SRCPATH = src/
BUILDPATH = build/
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
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	cat main.cpp | xclip -in -sel clip
	@echo 👍

clean:
	rm $(BUILDPATH)*

check:
	sh checker.sh
