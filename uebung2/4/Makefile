EXEC = skiplist

all: $(EXEC)

$(EXEC): $(EXEC).cpp $(EXEC).h
	$(CXX) -Wall -g -o $@ $(EXEC).cpp

test: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
