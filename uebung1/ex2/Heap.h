/* 
 * File:   Heap.h
 * Author: Markus Deutschl
 *
 * Created on October 29, 2012, 3:57 PM
 */
#include <algorithm>
#include <iostream>
#ifndef HEAP_H
#define	HEAP_H

template <class T>
class Heap {
public:

  static const int ERROR_CODE_TOP_ERROR = -1;
  static const int ERROR_CODE_PUSH_ERROR = -2;
  static const int ERROR_CODE_POP_ERROR = -3;
  
  Heap<T>(unsigned n) : elements(0), size(n), data(new T[n]) {
  }

  virtual ~Heap() {
    delete [] data;
  }

  bool empty() const {
    return elements;
  }

  T top() const {
    if (elements <= 0) {
      throw ERROR_CODE_TOP_ERROR;
    }
    return data[0];
  }

  void push(T d) {
    if (elements >= size) throw ERROR_CODE_PUSH_ERROR;
    data[elements++] = d;
    unsigned idx = elements - 1;
    while (idx != 0) {
      unsigned pidx = parent_index(idx);
      if (data[pidx] < d)
        std::swap(data[idx], data[pidx]);
      else break;
      idx = pidx;

    }
  }

  T pop() {
    if(elements <= 0) throw ERROR_CODE_POP_ERROR;
    T popped_element = data[0];
    data[0] = data[--elements];
    unsigned idx = 0;
    do {
      unsigned childs = children(idx);
      if (childs == 0) break;
      unsigned max_idx = left_index(idx);
      if (childs == 2) {
        if (data[max_idx] < data[max_idx + 1])
          max_idx++;
      }
      if (data[idx] < data[max_idx]) {
        std::swap(data[idx], data[max_idx]);
        idx = max_idx;
      } else break;
    } while (true);
    return popped_element;
  }
  
  /*
   * Heap sort algorithm for descending order
   * truncates the heap
   */
  T* heap_sort_desc(){
    T* sorted_pointer = new T[elements];
    unsigned curr_size = elements;
    for(unsigned i = 0; i < curr_size; i++){
      sorted_pointer[i] = pop();
    }
    return sorted_pointer;
  }
  
  /*
   * Heap sort algorithm for ascending order
   * truncates the heap
   */
  T* heap_sort_asc(){
    T* sorted_pointer = new T[elements];
    unsigned curr_size = elements;
    for(int i = curr_size - 1; i >= 0; i--){
      sorted_pointer[i] = pop();
    }
    return sorted_pointer;
  }
  
  void print() const{
    std::cout << "The Heap contains:\n" << "| ";
    for (int i = 0; i < elements; i++) {
      std::cout << data[i] << " | ";
    }
    std::cout << "\n\n";
  }
private:
  unsigned elements;
  unsigned size;
  T *data;

  unsigned left_index(unsigned idx) const {
    return 2 * idx + 1;
  }

  unsigned right_index(unsigned idx) const {
    return 2 * idx + 2;
  }

  unsigned parent_index(unsigned idx) const {
    return (idx - 1) / 2;
  }

  unsigned children(unsigned idx) const {
    if (elements <= left_index(idx)) return 0;
    else if (elements > right_index(idx)) return 2;
    else return 1;
  }
};

#endif	/* HEAP_H */

