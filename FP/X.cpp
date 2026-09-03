#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, q, tmr = 0;
vector<vector<int>> e;
vector<int> s, p, d, h, ps, rp, t;
vector<bool> b;

void f1(int u, int par, int dep) {
    s[u] = 1; p[u] = par; d[u] = dep;
    if (par != 0) {
        auto it = find(e[u].begin(), e[u].end(), par);
        if (it != e[u].end()) e[u].erase(it);
    }
    for (int &v : e[u]) {
        f1(v, u, dep + 1);
        s[u] += s[v];
        if (s[v] > s[e[u][0]]) swap(v, e[u][0]);
    }
}

void f2(int u, int hd) {
    h[u] = hd;
    ps[u] = ++tmr;
    rp[tmr] = u;
    if (e[u].empty()) return;
    f2(e[u][0], hd);
    for (int i = 1; i < e[u].size(); ++i) f2(e[u][i], e[u][i]);
}

void up(int nd, int l, int r, int i, int v) {
    if (l == r) { t[nd] = v; return; }
    int m = l + (r - l) / 2;
    if (i <= m) up(2 * nd, l, m, i, v);
    else up(2 * nd + 1, m + 1, r, i, v);
    t[nd] = min(t[2 * nd], t[2 * nd + 1]);
}

int qu(int nd, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[nd];
    if (qr < l || ql > r) return INF;
    int m = l + (r - l) / 2;
    return min(qu(2 * nd, l, m, ql, qr), qu(2 * nd + 1, m + 1, r, ql, qr));
}

int sq(int v) {
    int ans = INF;
    while (v != 0) {
        int hd = h[v];
        int res = qu(1, 1, n, ps[hd], ps[v]);
        if (res != INF) ans = res;
        v = p[hd];
    }
    return ans == INF ? -1 : rp[ans];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (cin >> n >> q) {
        e.resize(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        s.resize(n + 1); p.resize(n + 1); d.resize(n + 1);
        h.resize(n + 1); ps.resize(n + 1); rp.resize(n + 1);
        
        f1(1, 0, 0);
        f2(1, 1);
        
        t.assign(4 * n + 1, INF);
        b.assign(n + 1, false);
        
        for (int i = 0; i < q; ++i) {
            int ty, v; cin >> ty >> v;
            if (ty == 0) {
                b[v] = !b[v];
                up(1, 1, n, ps[v], b[v] ? ps[v] : INF);
            } else {
                cout << sq(v) << "\n";
            }
        }
    }
    return 0;
}