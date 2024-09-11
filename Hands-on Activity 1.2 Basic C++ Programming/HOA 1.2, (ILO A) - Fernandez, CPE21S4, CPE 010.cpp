#include <iostream>
using namespace std;

bool logOperator(bool A, bool B) {
  cout << "A AND B: " << (A && B) << endl;
  cout << "A OR B: " << (A || B) << endl;
  cout << "A XOR B: " << (A != B) << endl;
  cout << "NOT A: " << (!A) << endl;
  cout << "NOT B: " << (!B) << endl;
  return true;
}

int main(){
  int num1,num2;
  bool A = true;
  bool B = false;

  cout << "Enter the first number: ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;
  cout << "The sum of the first and second number is: "<< num1 + num2 << endl;

  if (num1 > num2) {
    cout << "The first number is greater than the second number." << endl;
  } else {
    cout << "The first number is less than the second number." << endl;
  }

  if(logOperator(A, B)) {
    cout << "Done." << endl;
  }

  return 0;
}
