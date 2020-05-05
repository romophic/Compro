main:
	ccache g++ main.cpp -o main -std=c++14
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
	cat main.cpp | xclip -in -sel clip
