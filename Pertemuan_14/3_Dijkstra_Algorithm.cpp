#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 9999999

// Typedef untuk menyimpan struktur {Bobot/Jarak, Tujuan_Vertex}
typedef pair<int, int> pii;

void dijkstra(int V, vector<pii> adj[], int start) {
    // Array penyimpan jarak terpendek (Awalnya diset Tak Terhingga)
    vector<int> dist(V, INF);
    
    // Priority Queue C++ (Min-Heap) untuk mengambil jarak terpendek secara instan O(1)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {Jarak, Node}

    while (!pq.empty()) {
        int u = pq.top().second;   // Node saat ini
        int d = pq.top().first;    // Jarak akumulasi ke node ini
        pq.pop();

        // Jika kita mengekstrak data lama/kadaluarsa dari antrean, lewati!
        if (d > dist[u]) continue;

        // Eksekusi Konsep "RELAXATION"
        for (auto edge : adj[u]) {
            int v = edge.second;       // Node tetangga
            int weight = edge.first;   // Bobot jalan ke tetangga

            // Jika (Jarak ke U + Jembatan ke V) lebih kecil dari Jarak V yang lama, UPDATE!
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Lempar penemuan baru ke Min-Heap
            }
        }
    }

    cout << "=== REKAP JARAK TERPENDEK DARI NODE [" << start << "] ===\n";
    for (int i = 0; i < V; ++i)
        cout << " -> Menuju Node [" << i << "] memakan biaya = " << dist[i] << " KM\n";
}

int main() {
    int V = 4;
    vector<pii> adj[V];
    
    // Format input: adj[Asal].push_back({Bobot, Tujuan})
    adj[0].push_back({4, 1}); adj[0].push_back({1, 2});
    adj[2].push_back({2, 1}); adj[1].push_back({5, 3});
    adj[2].push_back({8, 3});

    dijkstra(V, adj, 0);
    return 0;
}