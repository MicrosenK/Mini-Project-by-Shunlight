#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menentukan prioritas operator
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Fungsi konversi Infix ke Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Operand langsung ke output
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Buang '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Keluarkan sisa operator dalam stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a+(2*b^3)/(f-g)+d*h";
    string postfix = infixToPostfix(infix);
    
    cout << "=== Eksekusi Konversi Infix ke Postfix ===" << endl;
    cout << "Ekspresi Infix   : " << infix << endl;
    cout << "Ekspresi Postfix : " << postfix << endl;
    return 0;
}