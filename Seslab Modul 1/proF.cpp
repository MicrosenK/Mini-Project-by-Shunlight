#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N, S;
    queue<int> q;  // queue untuk menyimpan pelanggan
    string status;
    
    // Baca jumlah pelanggan
    cin >> N;
    
    // Baca N pelanggan dan masukkan ke queue
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        q.push(id);  // masukkan ke belakang queue
    }
    
    // Baca jumlah status pembayaran
    cin >> S;
    
    // Proses S status pembayaran
    for (int i = 0; i < S; i++) {
        cin >> status;
        
        // Cek apakah queue kosong
        if (q.empty()) {
            break;  // hentikan proses
        }
        
        // Ambil pelanggan paling depan
        int current = q.front();
        q.pop();  // keluarkan dari depan
        
        if (status == "BERHASIL") {
            // BERHASIL: customer keluar (tidak dimasukkan lagi)
            // sudah otomatis ke-pop, jadi tidak perlu ngapa-ngapain
        } 
        else if (status == "GAGAL") {
            // GAGAL: masukkan lagi ke belakang
            q.push(current);
        }
    }
    
    // Cetak hasil
    if (q.empty()) {
        cout << "KOSONG" << endl;
    } else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}