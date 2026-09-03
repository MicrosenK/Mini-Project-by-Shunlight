#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

string f(string s) {
    bool c = true;
    while (c) {
        c = false;
        for (int i = 0; i < (int)s.length(); ) {
            int j = i;
            while (j < s.length() && s[j] == s[i]) j++;
            
            if (j - i >= 3) {
                s.erase(i, j - i);
                c = true;
                break;
            } else {
                i = j;
            }
        }
    }
    return s;
}

struct S {
    string tk;
    string hd;
    int d;
};

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    string l, t;
    if (!(cin >> l >> t)) return 0;

    queue<S> Q;
    unordered_set<string> vis;

    Q.push({l, t, 0});
    vis.insert(l + "|" + t);

    while (!Q.empty()) {
        S u = Q.front();
        Q.pop();

        if (u.tk.empty()) {
            cout << u.d << "\n";
            return 0;
        }

        if (u.hd.empty()) continue;

        vector<pair<char, string>> ch;
        ch.push_back({u.hd[0], u.hd.substr(1)});
        
        if (u.hd.length() > 1) {
            ch.push_back({u.hd[1], string(1, u.hd[0]) + u.hd.substr(2)});
        }

        for (auto p : ch) {
            char b = p.first;
            string nh = p.second;

            for (int i = 0; i < u.tk.length(); ) {
                int j = i;
                while (j < u.tk.length() && u.tk[j] == u.tk[i]) j++;
                
                char c = u.tk[i];
                
                if (b == c || b == 'X') {
                    string nt = u.tk.substr(0, i) + c + u.tk.substr(i);
                    nt = f(nt);
                    
                    if (nt.empty()) {
                        cout << u.d + 1 << "\n";
                        return 0;
                    }

                    string key = nt + "|" + nh;
                    if (vis.find(key) == vis.end()) {
                        vis.insert(key);
                        Q.push({nt, nh, u.d + 1});
                    }
                }
                i = j;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}