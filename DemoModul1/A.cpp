#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack <char> st;
    bool valid = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                valid = false;
                break;
                }
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{'))
            {
                st.pop();
            } else {
                valid = false;
                break;}
        }}
    if (valid && st.empty()) {
        cout << "COMBO" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    return 0;
}
