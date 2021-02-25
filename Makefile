CC = clang++
INCLUDE =
DEFINE = -D DEBUG
FLAGS = -std=c++17 -O2 -g $(INCLUDE) $(DEFINE)

SRCPATH = src
BUILDPATH = build
SCRIPTPATH = Copi

SRC = $(SRCPATH)/main.cpp
TARGET = $(BUILDPATH)/main

$(TARGET): $(SRC)
	-mkdir $(BUILDPATH)
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)

run: $(SRC)
	make $(TARGET)
	@echo /////////////////////////////////
	@./$(TARGET)
	@echo //////////////// ///////////////

cp: $(SRC)
	cat $(SRC) | $(SCRIPTPATH)/copi.sh

clean:
	rm -r $(BUILDPATH)/*
