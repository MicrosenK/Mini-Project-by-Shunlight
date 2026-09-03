#include <iostream> 
#include <stack>
#include <string>

using namespace std;

bool cekValid(string eq) {

stack<char> stack;
for (int i = 0 ; i < eq.length() ; i++) {
    char s = eq[i];
    
if (s == '[' || s == '{' || s == '(') {
    stack.push(s);
} else if (s == '}' || s == ')' || s == ']') {
    if (stack.empty()) {
        return false;
    }
    // cek kesesuaian 
    if ((stack.top() == '(' && s == ')') || 
    (stack.top() == '{' && s == '}') ||
    (stack.top() == '[' && s == ']')) {
        stack.pop();
    }else {
        return false;
    }
        }
    }
    return stack.empty();
}

int main() {
    string masukan = "[{()}]";
    if (cekValid(masukan)) {
        cout << "OKE BENER" << endl;
    }



}