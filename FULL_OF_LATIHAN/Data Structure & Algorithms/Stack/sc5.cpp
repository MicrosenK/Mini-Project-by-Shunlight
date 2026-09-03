#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
    stack<string> stUndo;
    stack<string> stRedo;
    
    stUndo.push("Saya");
    stUndo.push("Belajar");
    stUndo.push("Coding");

    string top = stUndo.top();
    stUndo.pop(); 
    stUndo.push("C++");

    while(!stUndo.empty()) {
    cout << stUndo.top() << endl;
    stUndo.pop();
    }


}