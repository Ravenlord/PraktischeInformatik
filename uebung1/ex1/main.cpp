/* 
 * File:   main.cpp
 * Author: Markus Deutschl
 *
 * Created on October 29, 2012, 3:54 PM
 */

#include <cstdlib>
#include <iostream>
#include "Heap.h"
#include "StringContainer.h"

using namespace std;

void print_delimiter(){
  cout << "\n----------\n";
}

/*
 * Test case for template Heap with double numbers
 */
void test_double_numbers() {
  cout << "Constructing a heap with double numbers\n";
  Heap<double> h(10);
  h.print();
  cout << "Pushing double numbers: 4.3, 3.7, 10.5, 66.33, 44.3\n";
  h.push(4.3);
  h.push(3.7);
  h.push(10.5);
  h.push(66.33);
  h.push(44.3);
  h.print();
  cout << "Pushing number 20\n";
  h.push(20);
  h.print();
  cout << "Performing pop operation\n";
  double num = h.pop();
  cout << "Got number: " << num << "\n";
  h.print();
}

void test_string_container() {
  cout << "Constructing a heap with StringContainer data type (overloads compare operators)\n";
  Heap<StringContainer> h(10);
  h.print();
  cout << "Pushing strings 'm', 'LongJohn', 'bla', 'test', 'void'\n";
  h.push(StringContainer("m"));
  h.push(StringContainer("LongJohn"));
  h.push(StringContainer("bla"));
  h.push(StringContainer("test"));
  h.push(StringContainer("void"));
  h.print();
  cout << "Pushing string 'another'\n";
  h.push(StringContainer("another"));
  h.print();
  cout << "Performing pop operation\n";
  StringContainer sc_popped = h.pop();
  cout << "Got string: " << sc_popped.get_value() << "\n";
  h.print();
}

/*
 * 
 */
int main(int argc, char** argv) {
  //ex1
  cout << "Heap example with templates\n";
  print_delimiter();
  // perform test with double numbers
  test_double_numbers();
  print_delimiter();
  // perform test with StringContainer
  test_string_container();
  print_delimiter();
  
  //ex2
  
  return 0;
}

