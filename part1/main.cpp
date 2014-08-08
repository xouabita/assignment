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

  List (List && l): size (0), head (NULL), tail (NULL) {
    cp (l);
  }

  // Initialize a list with {} list elements
  List (std::initializer_list<T> args): size (0), head (NULL), tail (NULL) {
    for (auto item: args) this->push_back(item);
  }

  // Assign operator
  List operator= (const List & l) {
    if (&l != this) {
      this->del();
      head = tail = NULL;
      size = 0;
      cp (l);
      return *this;
    }
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

  List sub (int index, int length) {
    if (index < 0 || index >= size) throw "Index is out of bounds";
    if (length <= 0 || index+length > size) throw "Length is invalid";
    List res;
    int limit = index+length;
    for (int i=index; i < limit; i++) {
      res.push_back((*this)[i]);
    }
    return res;
  }

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
  List<int> l ({2,7,8,9,2,6,10,67,23});
  cout << l << endl;

  List<int> sl1 = l.sub(0,2); // Expect 2 -> 7
  List<int> sl2 = l.sub(2,4); // Expect 8 -> 9 -> 2 -> 6

  cout << sl1 << endl;
  cout << sl2 << endl;

  List<int> l_part1 = l.sub(0,(l.getSize()/2));
  List<int> l_part2 = l.sub((l.getSize()/2),(l.getSize()-(l.getSize()/2)));

  cout << "part 1: " << l_part1 << endl;
  cout << "part 2: " << l_part2 << endl;
}
