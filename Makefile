.PHONY : callgrind
HEADERS = $(wildcard *.h)

default: test.cpp $(HEADERS)
	@g++ -std=c++11 -g -Wall -O0 -Ieigen_3.3.3 -I. autodiff.cpp -o autodiff
