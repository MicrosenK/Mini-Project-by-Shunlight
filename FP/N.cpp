#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    stack<string> x;

    for (int i = 0; i < n; ++i) {
        string isi;
        cin >> isi;

        if (isi == "PUSH") {
            string item;
            cin >> item;
            x.push(item);
        } 
        else if (isi == "POP") {
            if (!x.empty()) {
                x.pop();
            }
        } 
        else if (isi == "TOP") {
            if (x.empty()) {
                cout << "KOSONG\n";
            } else {
                cout << x.top() << "\n";
            }
        }
    }

    return 0;
}