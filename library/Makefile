TARGETS = BellmanFordList BellmanFordMatrix WarshallFloydMatrix DijkstraList
CFLAGS = -g -O2 -std=c++0x

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

BellmanFordList: BellmanFordList.cpp
	g++ $(CFLAGS) -o $@ $<
BellmanFordMatrix: BellmanFordMatrix.cpp
	g++ $(CFLAGS) -o $@ $<
WarshallFloydMatrix: WarshallFloydMatrix.cpp
	g++ $(CFLAGS) -o $@ $<
DijkstraList: DijkstraList.cpp
	g++ $(CFLAGS) -o $@ $<
