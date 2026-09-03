#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = 2e18;
const int INF_INT = 2e9;

int x, y;
vector<vector<int>> adj;

int t;
vector<int> in_time, out_time, depth;
vector<vector<int>> up;

void dfs(int u, int p, int d) {
    in_time[u] = ++t;
    up[0][u] = p;
    for (int i = 1; i < 20; i++) {
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
    out_time[u] = ++t;
}

bool is_ancestor(int u, int v) {
    return in_time[u] <= in_time[v] && out_time[u] >= out_time[v];
}

int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 19; i >= 0; i--) {
        if (up[i][u] > 0 && !is_ancestor(up[i][u], v)) {
            u = up[i][u];
        }
    }
    return up[0][u];
}

// State untuk Virtual Tree & Dijkstra
struct NodeState {
    long long round;
    int fire_id;
    long long dist;
};

struct PQState {
    long long round;
    int fire_id;
    int u;
    long long dist;
    bool operator>(const PQState& other) const {
        if (round != other.round) return round > other.round;
        return fire_id > other.fire_id;
    }
};

vector<vector<int>> vt_adj;
vector<NodeState> best_state;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> x)) return 0;

    adj.resize(x + 1);
    for (int i = 0; i < x - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    t = 0;
    in_time.resize(x + 1);
    out_time.resize(x + 1);
    depth.resize(x + 1);
    up.assign(20, vector<int>(x + 1, 0));

    // Root di 1
    dfs(1, 1, 0);

    vt_adj.resize(x + 1);
    best_state.assign(x + 1, {INF, INF_INT, INF});

    cin >> y;
    while (y--) {
        int K, M;
        cin >> K >> M;

        vector<int> S(K + 1);
        vector<long long> T(K + 1);
        vector<int> nodes;

        for (int j = 1; j <= K; j++) {
            cin >> S[j] >> T[j];
            nodes.push_back(S[j]);
        }

        vector<int> critical(M);
        for (int i = 0; i < M; i++) {
            cin >> critical[i];
            nodes.push_back(critical[i]);
        }

        // Bangun Virtual Tree
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return in_time[a] < in_time[b];
        });
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        vector<int> st;
        vector<int> vt_nodes;
        
        st.push_back(nodes[0]);
        vt_nodes.push_back(nodes[0]);

        auto add_edge = [&](int u, int v) {
            vt_adj[u].push_back(v);
            vt_adj[v].push_back(u);
        };

        for (size_t i = 1; i < nodes.size(); i++) {
            int u = nodes[i];
            int lca = get_lca(u, st.back());

            if (lca != st.back()) {
                while (st.size() >= 2 && depth[st[st.size() - 2]] >= depth[lca]) {
                    add_edge(st[st.size() - 2], st.back());
                    st.pop_back();
                }
                if (st.back() != lca) {
                    add_edge(lca, st.back());
                    st.pop_back();
                    st.push_back(lca);
                    vt_nodes.push_back(lca);
                }
            }
            st.push_back(u);
            vt_nodes.push_back(u);
        }
        while (st.size() >= 2) {
            add_edge(st[st.size() - 2], st.back());
            st.pop_back();
        }

        // Bersihkan duplikat node untuk inisialisasi & pembersihan state
        sort(vt_nodes.begin(), vt_nodes.end());
        vt_nodes.erase(unique(vt_nodes.begin(), vt_nodes.end()), vt_nodes.end());

        // Multi-Source Dijkstra
        priority_queue<PQState, vector<PQState>, greater<PQState>> pq;

        for (int j = 1; j <= K; j++) {
            int u = S[j];
            if (0 < best_state[u].round || (0 == best_state[u].round && j < best_state[u].fire_id)) {
                best_state[u] = {0, j, 0};
                pq.push({0, j, u, 0});
            }
        }

        while (!pq.empty()) {
            PQState curr = pq.top();
            pq.pop();

            // Ignore jika sudah ada api yang memenangkan node ini dengan rekam jejak lebih cepat
            if (curr.round > best_state[curr.u].round || 
               (curr.round == best_state[curr.u].round && curr.fire_id > best_state[curr.u].fire_id)) {
                continue;
            }

            for (int v : vt_adj[curr.u]) {
                long long edge_len = abs(depth[curr.u] - depth[v]);
                long long new_dist = curr.dist + edge_len;
                long long speed = T[curr.fire_id];
                
                // Kalkulasi di ronde ke berapa api akan menyentuh node v
                long long new_round = (new_dist + speed - 1) / speed;

                if (new_round < best_state[v].round || 
                   (new_round == best_state[v].round && curr.fire_id < best_state[v].fire_id)) {
                    best_state[v] = {new_round, curr.fire_id, new_dist};
                    pq.push({new_round, curr.fire_id, v, new_dist});
                }
            }
        }

        // Cetak output sesuai urutan input ruangan kritis
        for (int i = 0; i < M; i++) {
            cout << best_state[critical[i]].fire_id << (i == M - 1 ? "" : " ");
        }
        cout << "\n";

        // Cleanup Virtual Tree untuk skenario selanjutnya
        for (int u : vt_nodes) {
            vt_adj[u].clear();
            best_state[u] = {INF, INF_INT, INF};
        }
    }

    return 0;
}