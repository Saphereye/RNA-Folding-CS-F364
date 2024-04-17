all: build run

build:
	@g++ main.cpp -o main.o

run:
	@./main.o

test:
	@g++ test.cpp -o test.o
	@./test.o

clean:
	@rm -rf *.o