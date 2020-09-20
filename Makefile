.PHONY: all
CC = clang++
INCLUDE = -I/usr/local/include
DEFINE = -D DEBUG
CFLAGS = -std=c++17 -O2 -Wall -g -v $(INCLUDE) $(DEFINE)
BUILDPATH = build/
SRC = main.cpp
OBJS = $(BUILDPATH)main.o
TARGET = $(BUILDPATH)main

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJS)

run: $(SRC)
	make $(TARGET)
	@echo /////////////////////////////////
	@./$(TARGET)
	@echo //////////////// ///////////////

cp: $(SRC)
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip
	bat -pp $(SRC)
	@echo 👆 👍

clean:
	rm $(BUILDPATH)*
