EXEC = CircularBuffer

all: $(EXEC)

$(EXEC): main.cpp $(EXEC).h
	$(CXX) -Wall -g -o $@ main.cpp

test: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
