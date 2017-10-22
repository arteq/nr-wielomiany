CXX=g++

all:
	$(CXX) -g -o wiel wiel.cpp

clean:
	rm -rf wiel
