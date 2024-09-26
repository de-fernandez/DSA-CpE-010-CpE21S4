#include <iostream>
#include <stack>
using namespace std;

int max_s = 4;

void display (stack<string>pl){
    while(true){
        if(!pl.empty()){
        cout << pl.top() << endl;
        pl.pop();
        }
        else{
            break;
        }
    }
}

void emptyS (stack<string> pl) {
    cout << "Deleting..." << endl;
    while (!pl.empty()) {
        pl.pop();
            if (pl.empty()) {
            cout << "The stack is empty." << endl;
    }
    }
}

int main(){
    stack<string>pl;
    cout << "Push elements into Stack:" << endl;
    //add items to the stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout << "Initial Stack: " << endl;
    display(pl);
    cout << endl;
    cout << "Final Stack: " << endl;
    display(pl);
    cout << endl;
    emptyS(pl);
    return 0;
}