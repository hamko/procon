CXXFLAGS=-std=c++11 -g -Wall  -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration
CXX=clang++-3.5
SRC := $(wildcard *.cpp)
OUT := $(SRC:.cpp=)

all: $(OUT)

.PHONY: clean
clean:
	$(RM) $(OUT)
