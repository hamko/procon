CC = clang++-3.5

CSRCS = $(shell ls *.c 2> /dev/null)
CXXSRCS = $(shell ls *.cpp 2> /dev/null)
OBJS = $(CSRCS:.c=.o) $(CXXSRCS:.cpp=.o)
HEADS = $(shell ls *.h 2> /dev/null) $(shell ls *.hpp 2> /dev/null)

CFLAGS = -std=c++11 -g -Wall  -fsanitize=undefined -Wno-deprecated -Wno-unneeded-internal-declaration -DLOCAL -pg
LFLAGS = -lm

PROD = brutal ga input greedy skip_greedy context_greedy annealing large_change feature_experiment statistics sort prune bridge duplicate game s4 s10 e12

all: $(PROD)

brutal: brutal.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

ga: ga.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

greedy: greedy.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

skip_greedy: skip_greedy.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

context_greedy: context_greedy.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

annealing: annealing.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

large_change: large_change.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

feature_experiment: feature_experiment.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

statistics: statistics.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

sort: sort.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

prune: prune.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

bridge: bridge.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

duplicate: duplicate.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	
game: game.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

s4: s4.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

s10: s10.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

e12: e12.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

input: input.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

.SUFFIXES: .c .cpp .o
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<
.cpp.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS): $(HEADS)

.PHONY: clean install
clean:
	rm -f $(PROD) $(OBJS)
