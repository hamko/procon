PROD = ./a.out
HEADS = mypng.hpp 
CFLAGS = -std=c++11 -Wall -g
LFLAGS = -lpng
OBJS = main.o mypng.o

all: $(PROD)

$(PROD): $(OBJS)
	g++ $(CFLAGS) $^ -o $@ $(LFLAGS)
	
.SUFFIXES: .cpp .o
.cpp.o:
	g++ -c $(CFLAGS) $^ -o $@ $(LFLAGS)

.PHONY: clean
clean:
	-rm $(OBJS) $(PROD)
