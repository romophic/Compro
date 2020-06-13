main:
	ccache clang++ main.cpp -o main
	./main
	rm -f main

raw:
	ccache g++ main.cpp -o main

rm:
	rm -f main

cp:
	#for mac
	#cat main.cpp | pbcopy
	#for linux with xclip
	#cat main.cpp | xclip -in -sel clip
