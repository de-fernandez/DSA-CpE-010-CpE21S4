#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int max_size = 50;
int main() {
    
    srand(time(0));
    int dataset[max_size];
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }
    for (int i = 0; i < max_size; i++) {
        cout << dataset[i] << " ";
    }
    return 0;
}