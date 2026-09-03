#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    priority_queue<long long, vector<long long>, greater<long long>> q;

    while (n--) {
        string s;
        cin >> s;

        if (s == "ADD") {
            long long v;
            cin >> v;
            q.push(v);
        } else if (s == "BUY") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}