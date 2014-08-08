#include <iostream>
#include <initializer_list>

using namespace std;

// Node into a linked list
template <class T> struct Node {
  T data;
  Node * next;
  Node (T data, Node * next = NULL) {
    this->data = data;
    this->next = next;
  }
};

// Linked List
template <class T> class List {
  int size;
  Node<T> * head;
  Node<T> * tail; // Tail to access the last element of the list

  // Return a node at the specified index
  Node<T> * getNode (int i) {
    Node<T> * res = NULL;
    if (i < size && i >= 0) {
      res = head;
      while (i > 0) {
        res= res->next;
        i--;
      }
    }
    return res;
  }

  // copy a list
  void cp (List & l) {
    for (int i=0; i < l.getSize(); i++) {
      this->push_back(l[i]);
    }
  }

  // Free the memory
  void del() {
    Node<T> * n;
    while (head != NULL) {
      n = head;
      head = head->next;
      delete n;
    }
    head = tail = NULL;
    size = 0;
  }

  public:
  // Initialize an empty list
  List (): size (0), head (NULL), tail (NULL) {}

  // Copy initialization with deep copy
  List (List & l): size (0), head (NULL), tail (NULL) {
    cp (l);
  }

  // Initialize a list with {} list elements
  List (std::initializer_list<T> args): size (0), head (NULL), tail (NULL) {
    for (auto item: args) this->push_back(item);
  }

  // Assign operator
  List operator= (List & l) {
    this->del();
    head = tail = NULL;
    size = 0;
    cp (l);
    return *this;
  }

  // Deletion of the List
  ~List () {
    del();
  }

  // Push an element at the front of the list
  void push_front (T e) {
    head = new Node<T> (e, head);
    if (tail == NULL) {
      tail = head;
    }
    size++;
  }

  // Push an element at the back of the list
  void push_back (T e) {
    if (tail == NULL) {
      head = tail = new Node<T> (e);
    }
    else {
      tail->next = new Node<T> (e);
      tail = tail->next;
    }
    size++;
  }

  // Return the size of the list
  int getSize() { return size; }

  // Display list into ostream
  friend ostream & operator << (ostream & os, List l) {
    if (l.head != NULL) {
      Node<T> * n = l.head;
      while (n != l.tail) {
       os << n->data << " -> ";
       n = n->next;
      }
      os << l.tail->data;
    } else { os << "Empty List."; }
    return os;
  }

  // Get an element in the list as for an array
  T operator [] (int i) {
    return getNode(i)->data;
  }

};

int main () {
  List<int> l4 ({2,7,8,9,2,6});
  cout << l4 << endl;
}
