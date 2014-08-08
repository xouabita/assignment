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

  // Return a sub list
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

  void sort() {
    if (size > 2) {
      int demi_size = size/2;
      List part1 = this->sub(0,(demi_size));
      List part2 = this->sub(demi_size,size-demi_size);
      part1.sort(); part2.sort();

      // Apply Merge Sort
      Node<T> * a  = head;
      Node<T> * a1 = part1.head;
      Node<T> * a2 = part2.head;

      while (a && a1 && a2) {
        if (a1->data <= a2->data) {
          a->data = a1->data;
          a1 = a1->next;
        } else {
          a->data = a2->data;
          a2 = a2->next;
        }
        a = a->next;
      }

      if (!a1) a1 = a2;

      while (a1 && a) {
        a->data = a1->data;
        a = a->next;
        a1 = a1->next;
      }

    } else if (size == 2) {
      if (head->data > head->next->data) {
        T temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;
      }
    }
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
  List<int> l1 ({9,8,7,6,5,4,3,2,1,0});
  List<int> l2 ({1,2,3,4,5,6,7,8,9,10,11});
  List<int> l3 ({7,89,2,67,2,78,10010,2,-10,78});

  cout << l1 << endl;
  l1.sort();
  cout << l1 << endl << endl;

  cout << l2 << endl;
  l2.sort();
  cout << l2 << endl << endl;

  cout << l3 << endl;
  l3.sort();
  cout << l3 << endl << endl;
}
