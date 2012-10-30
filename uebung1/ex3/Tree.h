/* 
 * File:   Tree.h
 * Author: Markus Deutschl
 *
 * Created on October 30, 2012, 2:18 PM
 */

#include <algorithm>

#ifndef TREE_H
#define	TREE_H

template<typename T>
class Tree {
public:
  Tree() : root(0) {
  }

  void insert(T d) {
    if (!root) root = new Node(d);
    else insert(root, d);
  }

  void print() const {
    print(root);
  }
  
  unsigned height() const{ return height(root); }
  
private:

  struct Node {
    Node(T d) : data(d), left(0), right(0) {}
    T data;
    Node *left, *right;
  };

  void print(Node *node) const {
    if (!node) return;
    print(node->left);
    printf("%.2f (%d)\n", node->data, height(node));
    print(node->right);
  }

  unsigned height(Node *node) const {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
  }

  void insert(Node* &node, T d) {
    if (!node) node = new Node(d);
    if (d < node->data)insert(node->left, d);
    else if (d > node->data) insert(node->right, d);
  }
  
  Node *root;
};

#endif	/* TREE_H */

