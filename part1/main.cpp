#include <iostream>
#include <initializer_list>

using namespace std;


/* ===================================================================
 * =                    Classes for the task                         =
 * =================================================================== */

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

  // Use Merge Sort for sorting the list
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

/* ===================================================================
 * =                           Solution                              =
 * ===================================================================
 * =                                                                 =
 * = I used the merge sort algorithm to sort the two lists and then  =
 * = I compare the two lists.                                        =
 * =                                                                 =
 * ===================================================================
 */


template<class T> List<T> intersection (List<T> l1, List<T> l2) {
  l1.sort();
  l2.sort();

  List<T> res;
  int i = 0, j = 0;
  while (i < l1.getSize() && j < l2.getSize()) {
    if (l1[i] == l2[j]) {
      res.push_back(l1[i]);
      i++; j++;
    }
    else if (l1[i] < l2[j]) i++;
    else j++;
  }

  return res;
}

int main () {
  // TESTS
  List<int> l1 ({12,89,24,42,9,2,4,6,7});
  List<int> l2 ({26,56,69,12,4,7,24,112,45,38});
  List<int> l3 ({90,89,56,4,7,2,7,42,24});
  List<int> l4 ({1});
  List<int> l5 ({48,89,12});

  List<int> l6 ({1,7,9,3,5});
  List<int> l7 ({2,4,6,7,9});

  cout << "intersection of:" << endl;
  cout << "l1: " << l1 << endl;
  cout << "l2: " << l2 << endl;
  cout << "result: " << intersection(l1,l2) << endl << endl;




  cout << "intersection of:" << endl;
  cout << "l3: " << l3 << endl;
  cout << "l4: " << l4 << endl;
  cout << "result: " << intersection(l3,l4) << endl << endl;

  cout << "intersection of:" << endl;
  cout << "l6: " << l6 << endl;
  cout << "l7: " << l7 << endl;
  cout << "result: " << intersection(l6,l7) << endl << endl;

  cout << "intersection of:" << endl;
  cout << "l1: " << l1 << endl;
  cout << "l3: " << l3 << endl;
  cout << "result: " << intersection(l1,l3) << endl << endl;

  cout << "intersection of:" << endl;
  cout << "l4: " << l4 << endl;
  cout << "l5: " << l5 << endl;
  cout << "result: " << intersection(l4,l5) << endl << endl;
}
