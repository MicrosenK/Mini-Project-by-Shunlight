#include <iostream>
#include <vector>

using namespace std;


struct DSU {
    vector<int> parent;
    int awal;

 
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        awal = n; 
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            awal--; 
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Menyimpan daftar jembatan (1-based index)
    vector<pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    int q;
    cin >> q;
    
    vector<int> col(q);
    vector<bool> wos(m + 1, false);
    for (int i = 0; i < q; ++i) {
        cin >> col[i];
        wos[col[i]] = true;
    }

    DSU dsu(n);
    for (int i = 1; i <= m; ++i) {
        if (!wos[i]) {
            dsu.unite(edges[i].first, edges[i].second);
        }
    }

    vector<int> ans(q);
    for (int i = q - 1; i >= 0; --i) {
        ans[i] = dsu.awal; 
        int bridge_idx = col[i];
        dsu.unite(edges[bridge_idx].first, edges[bridge_idx].second); 
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}