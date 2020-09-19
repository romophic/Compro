main: main.cpp
	clang++ -std=c++17 -O2 -Wall -g main.cpp -o main -I /usr/local/include

run: main.cpp
	make -j
	./main

cp: main.cpp
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip

clean:
	rm -f main a.out
	rm -rf main.dSYM .clangd
