/* 
 * File:   main.cpp
 * Author: Markus Deutschl
 *
 * Created on October 29, 2012, 3:54 PM
 */

#include <cstdlib>
#include <iostream>
#include "Tree.h"
#include "AvlTree.h"

using namespace std;

void print_delimiter() {
  cout << "\n----------\n";
}

void test_trees(unsigned n) {
  Tree<unsigned> tree;
  AvlTree<unsigned> avl_tree;
  for(unsigned i = 0; i < n; i++){
    unsigned num = (unsigned) (rand() % n + 1);
    tree.insert(num);
    avl_tree.insert(num);
  }
  cout << "Constructing trees with " << n << " values.\n";
  cout << "Binary tree height:\t" << tree.height() << "\n";
  cout << "AVL tree height:\t" << avl_tree.height() << "\n";
}

/*
 * 
 */
int main(int argc, char** argv) {
  cout << "Exercise 3: Trees\n";
  print_delimiter();
  for(unsigned i = 1; i <= 10; i++){
    test_trees(100*i);
    print_delimiter();
    break;
  }

  return 0;
}

