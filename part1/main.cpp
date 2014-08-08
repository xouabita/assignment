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

template <class T> class List {
  Node<T> * head;
  Node<T> * queue;
  int size;

  public:
  List () {
    head = queue = NULL;
    size = 0;
  }

  void push_front (T e) {
    head = new Node<T> (e, head);
    if (queue == NULL) {
      queue = head;
    }
  }

  friend ostream & operator << (ostream & os, List l) {
    if (l.head != NULL) {
      Node<T> * n = l.head;
      while (n != l.queue) {
       os << n->data << " -> ";
       n = n->next;
      }
      os << l.queue->data;
    } else { os << "Empty List."; }
    return os;
  }
};

int main () {
  List<int> l;
  cout << l << endl;
  l.push_front(8);
  cout << l << endl;
  l.push_front(6);
  l.push_front(9);
  l.push_front(3);
  l.push_front(7);

  cout << l << endl;
}
