#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> students;
    students.push("Alden");
    students.push("Ben");
    students.push("Charles");
    students.push("Don");

    cout << "The queue after push:\n";
    while (!students.empty()) {
        cout << students.front() << " ";
        students.pop();
    } cout << "\n\n";

    students.push("Ethan");
    students.push("Franco");

    cout << "The queue after more push:\n";
    while (!students.empty()) {
        cout << students.front() << " ";
        students.pop();
    } cout << "\n\n";
    
    cout << "Is the queue empty? " << (students.empty() ? "Yes" : "No") << endl;
    students.push("Alden");
    students.push("Ben");
    cout << "Pushing Alden and Ben... " << endl;
    cout << "The top of the queue: " << students.front() << endl;
    cout << "The size of the queue: " << students.size() << endl;
    return 0;
}