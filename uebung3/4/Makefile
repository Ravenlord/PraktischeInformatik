EXEC = skiplist

all: $(EXEC)

$(EXEC): test.cpp $(EXEC).h
	$(CXX) -Wall -g -o $@ test.cpp

test: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
