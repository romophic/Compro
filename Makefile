main:
	ccache g++ main.cpp -o main -std=c++14
	./main
	rm -f main

raw:
	ccache g++ main.cpp -o main
	./main
	rm -f main

sm:
	cat main.cpp | pbcopy
