#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

void primMST(int V, vector<pii> adj[]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(V, false); // Mencegah terbentuknya siklus/loop
    int mstCost = 0;

    // Inisiasi awal instalasi kabel dari Node 0
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Jika gedung ini sudah masuk ke jaringan MST, lompati!
        if (inMST[u]) continue;

        // Pasang kabel dan catat total biayanya
        inMST[u] = true;
        mstCost += cost;

        // Daftarkan semua opsi kabel tetangga ke Min-Heap
        for (auto edge : adj[u]) {
            int v = edge.second;
            int weight = edge.first;
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }
    cout << "$$$ Anggaran Biaya Kabel Minimum (MST) = " << mstCost << " Satuan" << endl;
}

int main() {
    int V = 4;
    vector<pii> adj[V];
    
    // Fungsi Lambda agar kode add Edge Undirected lebih bersih
    auto add = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    };
    
    add(0, 1, 10); add(0, 2, 6); add(0, 3, 5);
    add(1, 3, 15); add(2, 3, 4);

    primMST(V, adj);
    return 0;
}