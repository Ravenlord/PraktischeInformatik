EXEC = CacheSimulator
INPUT = trace-ls.txt

all: $(EXEC)

$(EXEC): main.cpp $(EXEC).h
	$(CXX) -Wall -g -o $@ main.cpp

test: $(EXEC) $(INPUT)
	./$(EXEC) $(INPUT)

clean:
	rm -f $(EXEC)
