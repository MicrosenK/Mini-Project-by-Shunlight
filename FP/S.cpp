#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

pair<int, int> f(int i) {
    if (i > n || v[i] == -1) return {0, 0};
    
    pair<int, int> l = f(2 * i);
    pair<int, int> r = f(2 * i + 1);
    
    int in = v[i] + l.second + r.second;
    int ex = max(l.first, l.second) + max(r.first, r.second);
    
    return {in, ex};
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    if (cin >> n) {
        v.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        pair<int, int> ans = f(1);
        cout << max(ans.first, ans.second) << "\n";
    }
    
    return 0;
}