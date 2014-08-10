#include "Array.h"
#include "List.h"

template <class T> Array<T> longest_increasing_continuous_subsequence (Array<T> arry) {
  int start = 0;
  int max_start = 0;
  int length = 1;
  int max_length = 1;
  for (int i=0; i < arry.size()-1; i++) {
    if (arry[i] < arry[i+1]) {
      length++;
    } else {
      if (length > max_length) {
        max_start  = start;
        max_length = length;
      }
      start = i+1; length = 1;
    }
  }

  // Return result :
  Array<T> res (max_length);
  int lim = max_start+max_length;
  int i = 0;
  for (; max_start < lim; max_start++ ) {
    res[i] = arry[max_start];
    i++;
  }

  return res;
}

template <class T> Array<T> longest_increasing_subsequence (Array<T> arry) {
  Array<T> P (arry.size());
  Array<T> M (arry.size() + 1);

  int L = 0;
  for (int i = 0; i < arry.size(); i++) {
    int lo = 1, hi = L;
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      if (arry[M[mid]] < arry[i]) lo = mid+1;
      else hi = mid-1;
    }
    int newL = lo;
    P[i] = M[newL-1];

    if (newL > L) {
      M[newL] = i;
      L = newL;
    } else if (arry[i] < arry[M[newL]]){
      M[newL] = i;
    }
  }

  Array<T> result (L);
  int k = M[L];
  for (int i=L-1; i >= 0; i--) {
    result[i] = arry[k];
    k = P[k];
  }
  return result;
}

int main () {

  List<int> l = {5,6,7,8,10};
  cout << l << endl;
  l[2] = 42;
  cout << l << endl << endl;

  Array<int> arr1 ({1,5,8,9,78,100,999,10000,2,4,6,8,10,2,3,5,7,42,98,2,1});
  Array<int> arr2 ({1,4,2,5,8,9,2,3,4});

  cout << "Longest increasing continuous subsequence in " << arr1 << " is:" << endl;
  cout << longest_increasing_continuous_subsequence(arr1) << endl;

  cout << "Longest increasing continuous subsequence in " << arr2 << " is:" << endl;
  cout << longest_increasing_continuous_subsequence(arr2) << endl << endl;

  Array<int> arr3 ({0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15});
  cout << longest_increasing_subsequence(arr3) << endl;
}
