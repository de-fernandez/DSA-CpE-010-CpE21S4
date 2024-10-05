#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}

bool check(string expression) {
    stack<char> stack;
    for (char symbol : expression) {
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            stack.push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (stack.empty()) {
                cout << "Error: Closing Symbol Without A Match of Opening Symbol" << endl;
                return false;
            }
            char opening = stack.top();
            stack.pop();
            if (!isPair(opening, symbol)) {
                cout << "Error: Not Matched of Symbols" << endl;
                return false;
            }
        }
    }
    if (!stack.empty()) {
        cout << "Error: Not Balanced Symbols" << endl;
        return false;
    }
    return true;
}

int main() {
    string expression = "((A+B]+[C-D]}";
    if (check(expression)) {
        cout << "Balanced Symbols" << endl;
    } else {
        cout << "Not Balanced Symbols" << endl;
    }
    return 0;
}
