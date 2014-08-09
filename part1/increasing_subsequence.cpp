#include "Array.h"

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

int main () {
  Array<int> arr1 ({1,5,8,9,78,100,999,10000,2,4,6,8,10,2,3,5,7,42,98,2,1});
  Array<int> arr2 ({1,4,2,5,8,9,2,3,4});

  cout << "Longest increasing continuous subsequence in " << arr1 << " is:" << endl;
  cout << longest_increasing_continuous_subsequence(arr1) << endl;

  cout << "Longest increasing continuous subsequence in " << arr2 << " is:" << endl;
  cout << longest_increasing_continuous_subsequence(arr2) << endl;
}
