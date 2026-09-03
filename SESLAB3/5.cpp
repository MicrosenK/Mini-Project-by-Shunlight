#include <iostream>
#include <vector>

using namespace std;

// Struktur Disjoint Set Union (DSU) untuk mengelompokkan bilangan
struct DSU {
    vector<int> parent;
    int components; // Untuk melacak jumlah kelompok yang terbentuk

    DSU(int n) {
        parent.resize(n);
        // Awalnya tiap bilangan adalah kelompoknya masing-masing
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        components = n; // Awalnya ada N kelompok
    }

    // Mencari 'akar' dari sebuah kelompok
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    // Menggabungkan dua kelompok
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        // Kalau belum satu kelompok, gabungkan!
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--; // Tiap ada yang gabung, total kelompok berkurang 1
        }
    }
};

int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Baca jumlah bilangan
    if (!(cin >> n)) return 0;

    // Baca list bilangannya
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int c;
    // Baca bilangan pembagi c
    cin >> c;

    // Inisialisasi DSU dengan N elemen
    DSU dsu(n);

    // Cek semua kemungkinan pasangan bilangan (kombinasi)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Syarat terhubung: (a XOR b) kelipatan c
            if ((arr[i] ^ arr[j]) % c == 0) {
                dsu.unite(i, j); // Gabungkan indeks i dan j
            }
        }
    }

    // Cetak hasil akhir (jumlah kelompok)
    cout << dsu.components << "\n";

    return 0;
}