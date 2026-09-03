#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> tabung;

    // 1. Kita isi dulu stack-nya
    tabung.push("MERAH");
    tabung.push("HIJAU");
    tabung.push("BIRU");
    tabung.push("KUNING");

    cout << "Ukuran stack awal: " << tabung.size() << " data.\n";
    cout << "=== MEMULAI PROSES MENGOSONGKAN STACK ===\n\n";

    // 2. Cara keluarin semua isinya pakai perulangan while
    // tabung.empty() akan bernilai true jika kosong, dan false jika masih ada isinya.
    // Tanda seru (!) artinya "TIDAK", jadi artinya: "Selama tabung TIDAK kosong"
    while (!tabung.empty()) {
        
        // Ambil/intip data yang paling atas dulu
        cout << "Mengeluarkan data: " << tabung.top() << endl;
        
        // Hapus data teratas tersebut dari stack
        tabung.pop(); 
    }

    cout << "\n=== PROSES SELESAI ===\n";
    cout << "Ukuran stack sekarang: " << tabung.size() << " data (Sudah kosong melompong).\n";

    return 0;
}