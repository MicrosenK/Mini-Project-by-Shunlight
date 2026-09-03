#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long total_ans = 0;
int target_d;

// dfs mengembalikan void, dp1 dan dp2 di-passing dengan referensi
void dfs(int u, int p, const vector<vector<int>>& adj, vector<vector<long long>>& dp1, vector<vector<long long>>& dp2) {
    // Awalnya di node u hanya ada dirinya sendiri (1 node tunggal di jarak 0)
    dp1[u] = {1};
    dp2[u] = {};

    for (int v : adj[u]) {
        if (v == p) continue;
        
        dfs(v, u, adj, dp1, dp2);
        
        // c1 adalah dp1 dari child v, digeser 1 jarak (karena melewati edge v->u)
        vector<long long> c1(dp1[v].size() + 1, 0);
        for (size_t i = 0; i < dp1[v].size(); ++i) c1[i + 1] = dp1[v][i];
        
        // c2 adalah dp2 dari child v, digeser 1 ukuran (karena path naik ke u menambah 1 node)
        vector<long long> c2;
        if (!dp2[v].empty()) {
            c2.assign(dp2[v].size() + 1, 0);
            for (size_t i = 0; i < dp2[v].size(); ++i) c2[i + 1] = dp2[v][i];
        }
        
        // 1. HITUNG JAWABAN (Pertemuan 3 target di node u)
        for (size_t y = 0; y < dp1[u].size(); ++y) {
            for (size_t x = 0; x < c2.size(); ++x) {
                if (x + y == target_d) {
                    total_ans += dp1[u][y] * c2[x];
                }
            }
        }
        
        for (size_t x = 0; x < dp2[u].size(); ++x) {
            for (size_t y = 0; y < c1.size(); ++y) {
                if (x + y == target_d) {
                    total_ans += dp2[u][x] * c1[y];
                }
            }
        }
        
        // 2. UPDATE STATE dp2 (Pasangan target)
        int new_len2 = max({
            (int)dp2[u].size(),
            (int)c2.size(),
            (int)(dp1[u].size() + c1.size()) // ukuran maksimal dari gabungan dua node tunggal
        });
        
        vector<long long> next_dp2(new_len2, 0);
        // Bawa data pasangan lama
        for (size_t i = 0; i < dp2[u].size(); ++i) next_dp2[i] += dp2[u][i];
        for (size_t i = 0; i < c2.size(); ++i) next_dp2[i] += c2[i];
        
        // Persilangan: 1 target dari d1_u bertemu 1 target dari c1 membentuk pasangan baru di u
        for (size_t y = 0; y < dp1[u].size(); ++y) {
            for (size_t x = 0; x < c1.size(); ++x) {
                int s = x + y + 1; // ukuran subgraph dari pasangannya
                if (s < next_dp2.size()) {
                    next_dp2[s] += dp1[u][y] * c1[x];
                }
            }
        }
        
        // 3. UPDATE STATE dp1 (Target tunggal)
        int new_len1 = max(dp1[u].size(), c1.size());
        vector<long long> next_dp1(new_len1, 0);
        for (size_t i = 0; i < dp1[u].size(); ++i) next_dp1[i] += dp1[u][i];
        for (size_t i = 0; i < c1.size(); ++i) next_dp1[i] += c1[i];
        
        // Potong array agar memori/waktu looping tidak boros melebihi target_d
        if (next_dp1.size() > target_d + 1) next_dp1.resize(target_d + 1);
        if (next_dp2.size() > target_d + 1) next_dp2.resize(target_d + 1);
        
        dp1[u] = move(next_dp1);
        dp2[u] = move(next_dp2);
        
        // Hapus child untuk menghemat RAM karena tidak akan dipakai lagi (Memory Optimization)
        dp1[v].clear(); dp1[v].shrink_to_fit();
        dp2[v].clear(); dp2[v].shrink_to_fit();
    }
}

void solve() {
    int n;
    if (!(cin >> n >> target_d)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    total_ans = 0;
    // Pakai vector dari luar agar memori dikelola per test case
    vector<vector<long long>> dp1(n + 1);
    vector<vector<long long>> dp2(n + 1);
    
    dfs(1, 0, adj, dp1, dp2);
    
    cout << total_ans << "\n";
}

int main() {
    // Fast I/O standard
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}