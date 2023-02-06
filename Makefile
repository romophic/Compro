main: src/main.cpp
	@g++ ./src/main.cpp -o main -std=c++17 -Og -g -D DEBUG -fsanitize=address,undefined,float-divide-by-zero,bounds,float-cast-overflow,alignment,object-size,vptr,bounds-strict,signed-integer-overflow,builtin,pointer-overflow,pointer-compare,pointer-subtract

run:
	@make && ./main

clean:
	rm -f main