main:
	ccache clang++ -std=c++17 main.cpp -o main -I /usr/local/include
	./main
	rm -f main

db:
	ccache clang++ -std=c++17 -g main.cpp -o main -I /usr/local/include
	lldb main
	rm -f main
	rm -rf -f main.dSYM

cp:
	#for pbcopy
	cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip

clean:
	rm -f main a.out
	rm -rf -f main.dSYM
