main: main.cpp
	rm -f main
	ccache clang++ -std=c++2a -g main.cpp -o main -I /usr/local/include

run: main.cpp
	rm -f main
	ccache clang++ -std=c++2a -g main.cpp -o main -I /usr/local/include
	./main

cp: main.cpp
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip

clean:
	rm -f main a.out
	rm -rf -f main.dSYM
