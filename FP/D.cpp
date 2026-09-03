#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O untuk mencegah TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    // Membaca koordinat awan
    vector<pair<long long, long long>> clouds(N);
    for (int i = 0; i < N; ++i) {
        cin >> clouds[i].first >> clouds[i].second;
    }

    // Variabel untuk Algoritma Prim
    // min_dist menyimpan jarak kuadrat terdekat dari pohon MST saat ini ke node tertentu
    vector<long long> min_dist(N, -1); 
    vector<bool> in_tree(N, false);
    vector<long long> merge_weights;

    // Mulai MST dari awan ke-0
    min_dist[0] = 0;

    for (int i = 0; i < N; ++i) {
        long long current_min = -1;
        int u = -1;

        // Cari awan terdekat yang belum masuk ke dalam MST
        for (int j = 0; j < N; ++j) {
            if (!in_tree[j] && min_dist[j] != -1) {
                if (current_min == -1 || min_dist[j] < current_min) {
                    current_min = min_dist[j];
                    u = j;
                }
            }
        }

        // Jika semua awan yang bisa dijangkau sudah diproses
        if (u == -1) break;

        in_tree[u] = true;
        
        // Simpan energi (jarak kuadrat) yang dibutuhkan untuk menggabungkan awan ini (kecuali root)
        if (u != 0) {
            merge_weights.push_back(current_min);
        }

        // Perbarui jarak minimum ke node tetangga yang belum masuk pohon MST
        for (int v = 0; v < N; ++v) {
            if (!in_tree[v]) {
                long long dx = clouds[u].first - clouds[v].first;
                long long dy = clouds[u].second - clouds[v].second;
                long long dist_sq = dx * dx + dy * dy;

                if (min_dist[v] == -1 || dist_sq < min_dist[v]) {
                    min_dist[v] = dist_sq;
                }
            }
        }
    }

    // Urutkan energi penggabungan (edges dari MST)
    sort(merge_weights.begin(), merge_weights.end());

    // Memproses setiap pertanyaan (query) Cinnamoroll
    for (int i = 0; i < Q; ++i) {
        long long P;
        cin >> P;
        
        // Cari berapa banyak sisi MST yang bisa dilewati dengan energi P
        // upper_bound mengembalikan iterator ke elemen pertama yang > P
        auto it = upper_bound(merge_weights.begin(), merge_weights.end(), P);
        int merged_edges = distance(merge_weights.begin(), it);
        
        // Jumlah kelompok terpisah = Total awal node (N) - jumlah edge yang berhasil tersambung
        cout << N - merged_edges << "\n";
    }

    return 0;
}