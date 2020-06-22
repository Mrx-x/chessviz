g = g++
CFLAGS = -Wall -Werror -MP -MMD -std=c++14

.PHONY: clean run all

all: ./bin/chess.exe

-include build/src/*.d

./bin/chess.exe: ./build/main.o ./build/draw.o ./build/code.o
	$(g) $(CFLAGS) -o ./bin/chess.exe ./build/main.o ./build/code.o ./build/draw.o -lm

./build/main.o: ./src/main.cpp ./src/title.h
	$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/draw.o: ./src/draw.cpp ./src/title.h
	$(g) $(CFLAGS) -o ./build/draw.o -c ./src/draw.cpp -lm

./build/code.o: ./src/code.cpp ./src/title.h
	$(g) $(CFLAGS) -o ./build/code.o -c ./src/code.cpp -lm


clean:
	rm -rf build/*.o build/*.d 

run:
	./bin/chess.exe
