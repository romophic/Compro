build/main: src/main.cpp
	mkdir -p build
	clang++ -std=gnu++20 -O2 -I ./ac-library/ -Wall -o build/main src/main.cpp

run:
	@make && echo "build complete" && ./build/main

clean:
	rm -rf build
