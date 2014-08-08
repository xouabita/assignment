#include <iostream>
#include <initializer_list>

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
  int size;
  Node<T> * head;
  Node<T> * queue;

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
    size = 0;
  }

  public:
  List (): size (0), head (NULL), queue (NULL) {}

  List (List & l): size (0), head (NULL), queue (NULL) {
    cp (l);
  }

  List (std::initializer_list<T> args): size (0), head (NULL), queue (NULL) {
    for (auto item: args) this->push_back(item);
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
  List<int> l4 ({2,7,8,9,2,6});
  cout << l4 << endl;
}
