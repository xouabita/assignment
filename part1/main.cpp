#include <iostream>

using namespace std;

template <class T> struct Node {
  T data;
  Node * next;
  Node (T data, Node * next = NULL) {
    this->data = data;
    this->next = next;
  }
};



int main () {
  // TESTS HERE
}
