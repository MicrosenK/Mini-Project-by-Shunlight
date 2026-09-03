#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    deque<string> ya;

    while (q--) {
        string komen;
        cin >> komen;

        if (komen == "PUSH_FRONT") {
            string mainan;
            cin >> mainan;
            ya.push_front(mainan);

        } else if (komen == "PUSH_BACK") {
            string mainan;
            cin >> mainan;
            ya.push_back(mainan);

        } else if (komen == "POP_FRONT") {
            if (!ya.empty()) {
                ya.pop_front();
            }
        } else if (komen == "POP_BACK") {
            if (!ya.empty()) {
                ya.pop_back();
            }
        }
    }

    if (ya.empty()) {
        cout << "KOSONG\n";
    } else {
        bool first = true;
        for (const string& mainan : ya) {
            if (!first) cout << " ";
            cout << mainan;
            first = false;
        }
        cout << "\n";
    }

    return 0;
}