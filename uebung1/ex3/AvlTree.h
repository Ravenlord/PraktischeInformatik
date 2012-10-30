/* 
 * File:   AvlTree.h
 * Author: Markus Deutschl
 *
 * Created on October 30, 2012, 2:33 PM
 */

#include <algorithm>

#ifndef AVLTREE_H
#define	AVLTREE_H

template<typename T>
class AvlTree {
public:

  AvlTree() : root(0) {
  }

  void insert(T d) {
    if (!root) root = new AvlNode(d);
    else insert(root, d);
  }

  void print() const {
    print(root);
  }
  
  unsigned height() const{ return height(root); }
private:

  struct AvlNode {

    AvlNode(T d) : data(d), left(0), right(0) {
    }
    T data;
    AvlNode *left, *right;
  };

  void rotate_right(AvlNode* &node) {
    AvlNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;
  }
  void rotate_right_left(AvlNode* &node) {
    rotate_right(node->right);
    rotate_left(node);
  }
  void rotate_left(AvlNode* &node) {
    AvlNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;
  }
  void rotate_left_right(AvlNode* &node) {
    rotate_left(node->left);
    rotate_right(node);
  }

  void print(AvlNode *node) const {
    if (!node) return;
    print(node->left);
    printf("%.2f (%d)\n", node->data, height(node));
    print(node->right);
  }
  
  unsigned height(AvlNode *node) const {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
  }

  void insert(AvlNode* &node, T d) {
    if (!node) node = new AvlNode(d);
    if (d < node->data) {
      insert(node->left, d);
      if (height(node->left) - height(node->right) == 2) {
        if (d < node->left->data) rotate_right(node);
        else rotate_left_right(node);
      }
    } else if (d > node->data) {
      insert(node->right, d);
      if (height(node->right) - height(node->left) == 2) {
        if (d > node->right->data) rotate_left(node);
        else rotate_right_left(node);
      }
    }
  }
  AvlNode *root;
};

#endif	/* AVLTREE_H */

