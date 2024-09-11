#include <iostream>
using namespace std;

int main() {
  int x, y, z;

  cout << "Enter the first number: ";
  cin >> x;
  cout << "Enter the second number: ";
  cin >> y;

  z = x;
  x = y;
  y = z;

  cout << "After swapping, the numbers are: ";
  cout << "First number: " << x;
  cout << "Second number: " << y;
  return 0;
}
