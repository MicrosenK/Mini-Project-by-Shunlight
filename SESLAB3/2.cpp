#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Array arah pergerakan untuk 8 arah (Horizontal, Vertikal, Diagonal)
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Fungsi Breadth-First Search (BFS) untuk menandai 1 kelompok yang terhubung
void bfs(int startX, int startY, int N, const vector<string>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Mengecek ke-8 arah tetangga
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Pastikan tetangga masih berada di dalam batas matriks NxN
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                // Jika tetangga adalah rumah terinfeksi dan belum pernah dikunjungi
                if (grid[nx][ny] == '+' && !visited[nx][ny]) {
                    visited[nx][ny] = true; // Tandai agar tidak dihitung dua kali
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    // Optimasi Input/Output agar tidak TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // N: ukuran baris dan kolom
    if (!(cin >> N)) return 0;

    // Membaca map perumahan
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // Matriks untuk mengingat rumah mana saja yang sudah dicek
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int group_count = 0;

    // Melakukan perulangan untuk setiap titik koordinat di perumahan
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Jika menemukan rumah terinfeksi yang belum punya grup
            if (grid[i][j] == '+' && !visited[i][j]) {
                group_count++; // Tambahkan jumlah kelompok
                
                // Jelajahi dan tandai seluruh rumah yang saling menular
                // menggunakan BFS
                bfs(i, j, N, grid, visited);
            }
        }
    }

    // Mengeluarkan jumlah kelompok karantina sesuai dengan permintaan Gaem
    cout << group_count << "\n";

    return 0;
}