main: src/main.cpp
	@mkdir -p build
	@g++ -std=gnu++20 -O2 -DONLINE_JUDGE -DATCODER \
	-Wall -Wextra \
	-mtune=native -march=native \
	-fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
	-o build/main.out src/main.cpp

run:
	@make && ./build/main.out

clean:
	rm -f main
