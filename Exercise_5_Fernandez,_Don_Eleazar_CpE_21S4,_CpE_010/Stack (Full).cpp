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

void fullS (stack<string>pl){
        if(pl.size() < max_s){
        cout << pl.top() << endl;
        pl.pop();
        }
        else{
            cout << "It is full!";
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
    pl.push("ReactJS");
    cout << endl;
    fullS(pl);
    return 0;
}
