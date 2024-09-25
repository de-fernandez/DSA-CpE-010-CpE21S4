#include <iostream>
#include <stack>
using namespace std;

void display (stack<string>pl){
    while(!pl.empty()){
        cout << pl.top() << endl;
        pl.pop();
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
    
    pl.pop();
    display(pl);
    return 0;
}
