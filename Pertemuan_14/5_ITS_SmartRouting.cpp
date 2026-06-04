#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
#define INF 9999999

// Menggunakan tipe {Waktu Tempuh, Nama Lokasi}
typedef pair<int, string> NodeDistance;

void cariRuteTercepat(unordered_map<string, vector<pair<string, int>>>& peta, string asal) {
    // Hash Table penyimpan akumulasi waktu terpendek dari posisi Asal
    unordered_map<string, int> waktuTempuh;
    
    // Setel semua destinasi dengan waktu Tak Terhingga di awal
    for (auto node : peta) waktuTempuh[node.first] = INF;
    
    priority_queue<NodeDistance, vector<NodeDistance>, greater<NodeDistance>> pq;

    // Setup Node Awal
    waktuTempuh[asal] = 0;
    pq.push({0, asal});

    while (!pq.empty()) {
        string tmpt_skrg = pq.top().second;
        int waktu_skrg = pq.top().first;
        pq.pop();

        // Optimasi: Skip evaluasi data usang yang tertinggal di Queue
        if (waktu_skrg > waktuTempuh[tmpt_skrg]) continue;

        for (auto tetangga : peta[tmpt_skrg]) {
            string destinasi = tetangga.first;
            int kepadatan_jalan = tetangga.second;

            // Inti Dijkstra: Relaksasi Rute
            if (waktuTempuh[tmpt_skrg] + kepadatan_jalan < waktuTempuh[destinasi]) {
                waktuTempuh[destinasi] = waktuTempuh[tmpt_skrg] + kepadatan_jalan;
                pq.push({waktuTempuh[destinasi], destinasi});
            }
        }
    }

    cout << "=== LAPORAN AI ROUTING DARI TITIK AWAL [" << asal << "] ===\n";
    for (auto hasil : waktuTempuh) {
        cout << " -> Menuju [ " << hasil.first << " ] memakan ETA = " << hasil.second << " Menit\n";
    }
}

int main() {
    // Database Peta Menggunakan Hash Table (Dictionary)
    unordered_map<string, vector<pair<string, int>>> petaITS;

    // Lambda untuk injeksi data Undirected Edge
    auto mappingJalan = [&](string u, string v, int waktu) {
        petaITS[u].push_back({v, waktu});
        petaITS[v].push_back({u, waktu});
    };

    // Mendaftarkan jalan, kemacetan, dan jarak (Direpresentasikan dlm Menit)
    mappingJalan("Asrama", "Perpustakaan", 10);
    mappingJalan("Asrama", "Bundaran ITS", 15);
    mappingJalan("Bundaran ITS", "Informatika", 5);
    mappingJalan("Perpustakaan", "Informatika", 12);
    mappingJalan("Informatika", "Rektorat", 3);

    // Jalankan Aplikasi (Booting)
    cariRuteTercepat(petaITS, "Asrama");

    return 0;
}