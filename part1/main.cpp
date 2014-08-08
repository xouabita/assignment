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

  void cp (List & l) {
    for (int i=0; i < l.getSize(); i++) {
      this->push_back(l[i]);
    }
  }

  void del() {
    Node<T> * n;
    while (head != NULL) {
      n = head;
      head = head->next;
      delete n;
    }
    head = queue = NULL;
  }

  public:
  List () {
    head = queue = NULL;
    size = 0;
  }

  List (List & l) {
    List ();
    cp (l);
  }

  List operator= (List & l) {
    this->del();
    head = queue = NULL;
    size = 0;
    cp (l);
    return *this;
  }

  ~List () {
    del();
  }

  void push_front (T e) {
    head = new Node<T> (e, head);
    if (queue == NULL) {
      queue = head;
    }
    size++;
  }

  void push_back (T e) {
    if (queue == NULL) {
      head = queue = new Node<T> (e);
    }
    else {
      queue->next = new Node<T> (e);
      queue = queue->next;
    }
    size++;
  }

  int getSize() { return size; }

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

  T operator [] (int i) {
    return getNode(i)->data;
  }
};

int main () {
  // Basic Tests for Linked List
  List<int> l;
  cout << l << endl;
  l.push_front(8);
  cout << l << " | size="<< l.getSize() <<endl;
  l.push_front(6);
  l.push_front(9);
  cout << l << " | size="<< l.getSize() <<endl;
  l.push_back(3);
  l.push_front(7);

  cout << l << " | size="<< l.getSize() <<endl;
  cout << "l[O]: " << l[0] << ", ";
  cout << "l[2]: " << l[2] << ", ";
  cout << "l[4]: " << l[4] << endl;

  List<int> l2;
  l2.push_back(1);
  cout << l2 << endl;
  l2.push_back(2);
  cout << l2 << endl;
  l2.push_front(0);
  cout << l2 << endl;

  // Test copy constructor and delete
  List<int> l3 (l2);
  cout << "l2: " << l2 << endl;
  cout << "l3: " << l3 << endl;

  l2.push_back (-2);
  l3.push_back (3);
  l2.push_front (-1);
  l3.push_front (4);

  cout << "l2: " << l2 << " | size="<< l2.getSize() <<endl;
  cout << "l3: " << l3 << " | size="<< l3.getSize() <<endl;

  l2 = l;
  cout << "l2: " << l2 << " | size="<< l2.getSize() <<endl;
}
