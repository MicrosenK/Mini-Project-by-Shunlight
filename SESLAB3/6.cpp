#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Array arah pergerakan untuk 4 arah (Atas, Bawah, Kiri, Kanan)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    // Baca ukuran n dan m (1 <= n, m <= 182)
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Matriks untuk menyimpan jarak, inisialisasi dengan angka yang sangat besar (infinity)
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;

    // Langkah 1: Cari semua pixel putih ('1') dan jadikan titik awal (sumber) BFS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                dist[i][j] = 0;     // Jarak pixel putih ke dirinya sendiri adalah 0
                q.push({i, j});     // Masukkan ke antrean
            }
        }
    }

    // Langkah 2: Mulai Multi-source BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Cek 4 tetangga di sekitarnya
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Pastikan koordinat tidak keluar dari batas peta
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // Jika ditemukan jalur yang jaraknya lebih pendek, perbarui jaraknya!
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Langkah 3: Cetak hasil sesuai format soal (dipisahkan spasi)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Optimasi Input/Output agar tidak memakan waktu lama saat ada banyak testcase
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Baca jumlah testcase
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}