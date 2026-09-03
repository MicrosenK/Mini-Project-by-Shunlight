#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Optimasi I/O biar eksekusi ngebut
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Baca jumlah area
    if (!(cin >> N)) return 0;

    // Vektor untuk menyimpan daftar kunci di setiap area
    vector<vector<int>> keys(N);
    
    // Membaca input kunci untuk masing-masing area
    for (int i = 0; i < N; ++i) {
        int Q;
        cin >> Q; // Baca jumlah kunci di area i
        for (int j = 0; j < Q; ++j) {
            int key;
            cin >> key; // Baca nomor kuncinya
            keys[i].push_back(key);
        }
    }

    // Array penanda area mana saja yang sudah berhasil dibuka
    vector<bool> visited(N, false);
    queue<int> q;

    // Mulai dari area 0
    visited[0] = true;
    q.push(0);
    
    int opened_count = 1; // Menghitung total area yang sudah terbuka

    // Mulai penelusuran (BFS)
    while (!q.empty()) {
        int current_area = q.front();
        q.pop();

        // Cek semua kunci yang ada di area saat ini
        for (int key : keys[current_area]) {
            // Jika area dari kunci tersebut belum terbuka
            if (!visited[key]) {
                visited[key] = true;    // Tandai sudah terbuka
                q.push(key);            // Masukkan ke antrean untuk dieksplorasi kuncinya nanti
                opened_count++;         // Tambah hitungan area terbuka
            }
        }
    }

    // Pengecekan hasil akhir
    if (opened_count == N) {
        cout << "Para peserta LBH berhasil keluar!\n";
    } else {
        cout << "Para peserta LBH terjebak selamanya.\n";
    }

    return 0;
}