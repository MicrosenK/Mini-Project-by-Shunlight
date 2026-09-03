#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S {
    int t, l, r;
};

bool ov(const S& a, const S& b) {
    if (a.t != b.t) return false;
    return max(a.l, b.l) < min(a.r, b.r);
}

int n;
vector<vector<int>> e;
vector<int> d, l, c, st;
vector<bool> is;
int tmr = 0, cnt = 0;

void tj(int u) {
    d[u] = l[u] = ++tmr;
    st.push_back(u);
    is[u] = true;

    for (int v : e[u]) {
        if (!d[v]) {
            tj(v);
            l[u] = min(l[u], l[v]);
        } else if (is[v]) {
            l[u] = min(l[u], d[v]);
        }
    }

    if (l[u] == d[u]) {
        while (true) {
            int v = st.back();
            st.pop_back();
            is[v] = false;
            c[v] = cnt;
            if (u == v) break;
        }
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n)) return 0;

    vector<S> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].t >> A[i].l >> A[i].r;
        cin >> B[i].t >> B[i].l >> B[i].r;
    }

    e.assign(2 * n, vector<int>());

    auto ae = [&](int u, int v) {
        e[u].push_back(v);
    };

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ov(A[i], A[j])) { ae(i, j + n); ae(j, i + n); }
            if (ov(A[i], B[j])) { ae(i, j); ae(j + n, i + n); }
            if (ov(B[i], A[j])) { ae(i + n, j + n); ae(j, i); }
            if (ov(B[i], B[j])) { ae(i + n, j); ae(j + n, i); }
        }
    }

    d.assign(2 * n, 0);
    l.assign(2 * n, 0);
    c.assign(2 * n, -1);
    is.assign(2 * n, false);

    for (int i = 0; i < 2 * n; ++i) {
        if (!d[i]) tj(i);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (c[i] == c[i + n]) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "RIFT SEALED\n";
    else cout << "RIFT COLLAPSED\n"; 

    return 0;
}