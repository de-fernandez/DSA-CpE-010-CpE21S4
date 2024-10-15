#include "searching.h"
#include <iostream>
using namespace std;

int binarySearch(char arr[], char no, int n) {
  int low = 0;
  int up = n - 1;

  while (low <= up) {
    int mid = (low + up) / 2;

    if (arr[mid] == no) {
      cout << "Search element is found" << endl;
      return mid;
    } else if (arr[mid] > no) {
      up = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << "Search element is not found" << endl;
  return -1;
}

int main() {
  char arr[] = {'R', 'o', 'm', 'a', 'n'};
  int n = sizeof(arr) / sizeof(arr[0]);
  char no = 'n';

  int result = binarySearch(arr, no, n);

  return 0;
}