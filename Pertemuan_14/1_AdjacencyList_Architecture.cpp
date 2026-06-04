#include <iostream>
#include <vector>
using namespace std;

// Fungsi menambahkan Edge (Undirected Graph)
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v); // Hubungkan U ke V
    adj[v].push_back(u); // Hubungkan V ke U
}

// Fungsi menampilkan Topologi Graf
void printTopologi(vector<int> adj[], int V) {
    cout << "=== TOPOLOGI JARINGAN GRAF ===\n";
    for (int i = 0; i < V; ++i) {
        cout << "[Node " << i << "] terhubung dengan -> ";
        for (int tetangga : adj[i]) {
            cout << tetangga << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Mengalokasikan 5 Node (0 hingga 4)
    vector<int> adj[V];

    // Merangkai topologi jaringan
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printTopologi(adj, V);
    return 0;
}