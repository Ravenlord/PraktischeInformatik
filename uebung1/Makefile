all: 
	@echo "Please specify a target!"
	@echo "Clean: clean-ex01, clean-ex02, clean-ex03"
	@echo "Build: ex01, ex02, ex03"
	@echo "Run (includes clean and build): test-ex01, test-ex02, test-ex03"

clean-ex01:
	rm -f ex1/ex01

clean-ex02:
	rm -f ex2/ex02

clean-ex03:
	rm -f ex3/ex03

ex01: ex1/main.cpp
	g++ -Wall -g -o ex1/$@ ex1/main.cpp

ex02: ex2/main.cpp
	g++ -Wall -g -o ex2/$@ ex2/main.cpp

ex03: ex3/main.cpp
	g++ -Wall -g -o ex3/$@ ex3/main.cpp

test-ex01: clean-ex01 ex01
	ex1/ex01

test-ex02: clean-ex02 ex02
	ex2/ex02

test-ex03: clean-ex03 ex03
	ex3/ex03

