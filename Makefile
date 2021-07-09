.PHONY: build
all: clean build

build:
	g++ -o main.out -std=c++11 -O2 -Wall main.cpp

run: build
	./main.out

clean:
	rm -rf ./main.out
