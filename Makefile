main:
	ccache clang++ main.cpp -o main
	./main
	rm -f main

db:
	ccache clang++ -g main.cpp -o main
	lldb main
	rm -f main
	rm -rf -f main.dSYM

cp:
	#for pbcopy
	cat main.cpp | pbcopy
	#for xclip
	#cat main.cpp | xclip -in -sel clip
