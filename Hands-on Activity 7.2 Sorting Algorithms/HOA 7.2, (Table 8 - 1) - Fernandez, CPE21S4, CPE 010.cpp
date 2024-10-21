#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int size = 100;
    int randomArray[size];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; ++i) {
        randomArray[i] = rand() % 1000 + 1;
    }

    for (int i = 0; i < size; ++i) {
        cout << randomArray[i] << " ";
    }
    cout << endl;

    return 0;
}