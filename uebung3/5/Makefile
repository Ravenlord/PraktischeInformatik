CG = codegen
ASFILE = calc_expr.s
plus = plus
minus = minus
mult = mult
pow = pow
max = max
EXEC = calc

all:
	echo "Usage:\nCorrect order is important!\n\tmake plus|minus|mult|pow|max\n\tmake test\nor\n\tmake clean"

$(CG): $(CG).cpp
	$(CXX) -Wall -o $@ $(CG).cpp

$(plus): $(CG)
	./$(CG) $(plus) > $(ASFILE)

$(minus): $(CG)
	./$(CG) $(minus) > $(ASFILE)

$(mult): $(CG)
	./$(CG) $(mult) > $(ASFILE)

$(pow): $(CG)
	./$(CG) $(pow) > $(ASFILE)

$(max): $(CG)
	./$(CG) $(max) > $(ASFILE)

compile: $(ASFILE) codelink.cpp
	as -c -o calc_expr.o $(ASFILE)
	$(CXX) -c -o codelink.o codelink.cpp

link: compile
	$(CXX) -o $(EXEC) codelink.o calc_expr.o

test: link
	./$(EXEC)

clean:
	rm -f $(CG)
	rm -f $(ASFILE)
	rm -f calc_expr.o
	rm -f codelink.o
	rm -f $(EXEC)
