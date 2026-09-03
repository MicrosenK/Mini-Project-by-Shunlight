#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> st;
    cout << "IMPLEMENTASI STACK" << endl;
    st.push("Pizza");
    st.push("Matcha");
    st.push("Vegetables");
    st.push("Donut");

    int var = 1;
    while(!st.empty()) {
        cout << var << ".";
        cout << st.top() << endl;
        st.pop();

        var++;
    }
    return 0;

}