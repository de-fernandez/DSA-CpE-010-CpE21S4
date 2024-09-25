#include <iostream>
#include <queue>
using namespace std;

void display (queue<string>pl){
    while(true){
        if(!pl.empty()){
        cout << pl.front() << endl;
        pl.pop();
        }
        else{
            break;
        }
    }
}

int main(){
    queue<string>pl;
    cout << "Push elements into Queue:" << endl;
    //add items to the stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout << "Initial Queue: " << endl;
    display(pl);
    cout << endl;
    cout << "Final Queue: " << endl;
    display(pl);
    return 0;
}
