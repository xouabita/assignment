#include "List.h"

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
