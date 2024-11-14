src/main: src/main.cpp
	clang++ -std=gnu++2b -include-pch src/stdc++.h.pch -Wall -Wno-unused-variable -Wno-unused-pragmas -fsanitize=address -g src/main.cpp -o src/main

run: src/main
	./src/main
