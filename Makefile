CXX = clang++
CXXFLAGS = -pg -O2 -lglfw -lGL -lGLU -lglut -lX11 -lpthread -lXrandr -lXi -ldl -lGLEW -lGLU -lGL -lglut -lm -std=c++20

all: build

build:
	$(CXX) main.cpp $(CXXFLAGS) -o main.o 

clean:
	@rm -rf *.o

docs:
	@rm -rf docs
	@doxygen Doxyfile
	@mv html docs

install:
	sudo apt-get install libglfw3-dev
	sudo apt-get install freeglut3-dev

.PHONY: all build clean docs install