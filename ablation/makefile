all:
	g++ -O3 src/tables.c src/hash.c src/main.cpp src/sbox.c src/state.c -o main

ori:
	g++ src/tables.c src/hash.c src/main.cpp src/sbox.c src/state.c -o main
	./main
o1:
	g++ -O1 src/tables.c src/hash.c src/main.cpp src/sbox.c src/state.c -o main
	./main
o2:
	g++ -O2 src/tables.c src/hash.c src/main.cpp src/sbox.c src/state.c -o main
	./main
o3:
	g++ -O3 src/tables.c src/hash.c src/main.cpp src/sbox.c src/state.c -w -o main
	./main

clean:
	rm -rf ./main