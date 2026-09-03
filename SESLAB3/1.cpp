#include <iostream>
#include <vector>

using namespace std;

// Struktur Disjoint Set Union (DSU) untuk menggabungkan kosmik yang berhubungan
struct DSU {
    vector<int> parent;
    int components; // Menyimpan jumlah kelompok (komponen) yang terpisah

    DSU(int n) {
        parent.resize(n);
        // Pada awalnya, setiap kosmik adalah kelompoknya sendiri
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        components = n; // Awalnya ada N kelompok
    }

    // Fungsi untuk mencari 'akar' atau perwakilan dari suatu kelompok
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression agar pencarian selanjutnya lebih cepat
        return parent[i] = find(parent[i]);
    }

    // Fungsi untuk menyatukan dua kosmik ke dalam satu kelompok
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        // Jika akar mereka berbeda, berarti mereka dari kelompok yang berbeda
        if (root_i != root_j) {
            parent[root_i] = root_j; // Gabungkan kelompok
            components--; // Karena ada 2 kelompok yang bergabung, total kelompok berkurang 1
        }
    }
};

int main() {
    // Optimasi agar proses Input/Output (cin/cout) di C++ jadi lebih cepat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    // N: jumlah kosmik, M: jumlah hubungan
    if (!(cin >> N >> M)) return 0;

    // Inisialisasi DSU dengan N kosmik
    DSU dsu(N);

    // Membaca setiap hubungan kosmik
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v); // Gabungkan kosmik u dan v
    }

    // Cek apakah seluruh kosmik sudah membentuk 1 kesatuan
    if (dsu.components == 1) {
        cout << "Kompleksitas entitas terbentuk\n";
    } else {
        // Jika belum, hitung butuh berapa koneksi (x) lagi
        int x = dsu.components - 1;
        cout << "Seluruh kosmik tidak berkaitan, butuh " << x << " lagi\n";
    }

    return 0;
}