main:
	ccache clang++ -std=c++17 -g main.cpp -o main
	./main
	rm -f main

db:
	ccache clang++ -std=c++17 -g main.cpp -o main
	lldb main
	rm -f main
	rm -rf -f main.dSYM

cp:
	#for pbcopy
	#cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip

clear:
	rm -f main a.out
	rm -rf -f main.dSYM
