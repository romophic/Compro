main: src/main.cpp
	@g++ -std=gnu++20 -O2 -DONLINE_JUDGE -DATCODER \
	-Wall -Wextra \
	-mtune=native -march=native \
	-fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
	-o main.out src/main.cpp

run:
	@make && ./main

clean:
	rm -f main
