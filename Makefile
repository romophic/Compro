.PHONY: all
CC = clang++
INCLUDE = -I/usr/local/include
CFLAGS = -std=c++17 -O2 -Wall -g -v $(INCLUDE)
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
	./$(TARGET)

cp: $(SRC)
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip

clean:
	rm $(BUILDPATH)*
