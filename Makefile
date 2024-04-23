all: build run

build:
	@g++ main.cpp -lglfw -lGL -lGLU -lglut -lX11 -lpthread -lXrandr -lXi -ldl -o main.o

run:
	@./main.o

test:
	@g++ test.cpp -o test.o
	@./test.o

clean:
	@rm -rf *.o