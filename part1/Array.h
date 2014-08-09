#include <iostream>
#include <initializer_list>

using namespace std;

template <class T> class Array {
  T * data;
  int m_size;

  public:
  Array (std::initializer_list<T> args) : m_size (args.size()) {
    data = new T[m_size];
    int i = 0;
    for (auto item: args) {
      data[i] = item;
      i++;
    }
  }

  Array (int size) : m_size (size) {
    data = new T[m_size];
  }

  Array (Array & arr) : m_size(arr.size()) {
    data = new T[m_size];
    for (int i = 0; i < m_size; i++) data[i] = arr[i];
  }

  Array (Array && arr) {
    data = new T[m_size];
    for (int i = 0; i < m_size; i++) data[i] = arr[i];
  }

  Array operator= (const Array & arr) {
    if (&arr != this) {
      delete[] this->data;
      this->m_size = arr.size();
      data = new T[m_size];
      for (int i = 0; i < m_size; i++) data[i] = arr[i];
    }
    return *this;
  }

  ~Array () { delete[] this->data; }

  int size() { return m_size; }

  friend ostream & operator << (ostream & os, Array arr) {
    os << "[ ";
    for (int i=0; i < arr.size()-1; i++) {
      os << arr[i] << ", ";
    }

    if (arr.size() > 0) { os << arr[arr.size()-1]; }
    os << " ]";
    return os;
  }

  T operator[] (int i) const { return this->data[i]; }

  T& operator[] (int i) { return this->data[i]; }
};
