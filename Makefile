.PHONY: all
CC = clang++
INCLUDE = -I /usr/local/include
DEFINE = -D DEBUG
CPPFLAGS = -std=c++17 -O2 -g $(INCLUDE) $(DEFINE)
SRCPATH = src
BUILDPATH = build
SCRIPTPATH = Copi
HISTORYPATH = history
SRC = $(SRCPATH)/main.cpp
TARGET = $(BUILDPATH)/main
HISTORY = $(HISTORYPATH)/out.log

$(TARGET): $(SRC)
	-mkdir $(BUILDPATH)
	$(CC) $(CPPFLAGS) $(SRC) -o $(TARGET)

run: $(SRC)
	make $(TARGET)
	-mkdir $(HISTORYPATH)
	@echo '//--------------------------------' >>$(HISTORY)
	@date -R >>$(HISTORY)
	@echo /////////////////////////////////
	@./$(TARGET) | tee -a $(HISTORY)
	@echo //////////////// ///////////////

cp: $(SRC)
	cat $(SRC) | $(SCRIPTPATH)/copi.sh

clean:
	rm $(BUILDPATH)/*
