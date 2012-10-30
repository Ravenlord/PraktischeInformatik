/* 
 * File:   main.cpp
 * Author: Markus Deutschl
 *
 * Created on October 29, 2012, 3:54 PM
 */

#include <cstdlib>
#include <iostream>
#include "Heap.h"

using namespace std;

void print_delimiter(){
  cout << "\n----------\n";
}


void test_heap_sort(){
  unsigned heap_size = 10;
  Heap<unsigned> h1(heap_size);
  // Descending
  cout << "Constructing a heap with unsigned numbers 1...10\n";
  for (unsigned i = 1; i <= heap_size; i++) {
    h1.push(i);
  }
  h1.print();
  print_delimiter();
  cout << "Descending sort with the heap sort algorithm\n";
  print_delimiter();
  h1.heap_sort_desc();
  print_delimiter();
  print_delimiter();
  // Ascending
  cout << "Constructing a heap with unsigned numbers 1...10\n";
  for (unsigned i = 1; i <= heap_size; i++) {
    h1.push(i);
  }
  h1.print();
  print_delimiter();
  cout << "Ascending sort with the heap sort algorithm\n";
  print_delimiter();
  h1.heap_sort_asc();
}
/*
 * 
 */
int main(int argc, char** argv) { 
  //ex2 - Heap sort
  cout << "Exercise 2: Heap sort\n";
  print_delimiter();
  test_heap_sort();
  
  return 0;
}

