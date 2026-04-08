#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    stack<char> s; //char = 'A'
    string n;

    while(true) {
        cin >> n; //akan meminta input an dari user

        if (n == "WRITE") { 
            char x;
            cin >> x;
            s.push(x);
        }
        else if (n == "BACKSPACE") {
            if(!s.empty()) {
                s.pop();
            }
        }
        else if (n == "PRINT") {
            stack<char> temp = s;
            string hasil = "";

            while(!temp.empty()) {
                hasil.push_back(temp.top());
                temp.pop();
            }
            reverse(hasil.begin(), hasil.end());
            cout << hasil << endl;
            break;
        }
    }
}