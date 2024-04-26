CXX = g++
CXXFLAGS = -lglfw -lGL -lGLU -lglut -lX11 -lpthread -lXrandr -lXi -ldl -lGLEW -lGLU -lGL -lglut -lm -std=c++20

all: build run

build:
	@$(CXX) main.cpp $(CXXFLAGS) -o main.o 

run:
	@./main.o

test:
	@g++ test.cpp -o test.o
	@./test.o

clean:
	@rm -rf *.o

docs:
	@rm -rf docs
	@doxygen Doxyfile
	@mv html docs

.PHONY: all build run test clean docs