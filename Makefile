CC = g++
FLAGS = -Wall -std=c++17 -O2 -g -D DEBUG

SRCPATH = src
BUILDPATH = build
SCRIPTPATH = Copi

SRC = $(SRCPATH)/main.cpp
TARGET = $(BUILDPATH)/main

./$(TARGET): ./$(SRC)
	-mkdir ./$(BUILDPATH)
	$(CC) $(FLAGS) ./$(SRC) -o ./$(TARGET)

run: ./$(SRC)
	make ./$(TARGET)
	@echo /////////////////////////////////
	@./$(TARGET)
	@echo //////////////// ///////////////

cp: ./$(SRC)
	./$(SCRIPTPATH)/copi.sh < ./$(SRC)

clean:
	rm -rf ./$(BUILDPATH)