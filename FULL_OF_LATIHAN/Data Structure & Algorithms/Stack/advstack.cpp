#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool cekKurungSempurna(string teks) {
    stack<char> st; // Stack untuk menyimpan karakter kurung buka

    // Loop untuk mengecek setiap karakter dalam string
    for (int i = 0; i < teks.length(); i++) {
        char karakter = teks[i];

        // 1. Jika kurung buka, masukkan ke stack
        if (karakter == '(' || karakter == '[' || karakter == '{') {
            st.push(karakter);
        } 
        // 2. Jika kurung tutup, kita cek pasangannya
        else if (karakter == ')' || karakter == ']' || karakter == '}') {
            
            // Antispasi: Kalau ketemu kurung tutup tapi stack sudah kosong duluan
            if (st.empty()) return false; 

            char teratas = st.top(); // Intip kurung buka terakhir yang masuk

            // Cek apakah pasangannya cocok
            if ((karakter == ')' && teratas == '(') ||
                (karakter == ']' && teratas == '[') ||
                (karakter == '}' && teratas == '{')) {
                st.pop(); // Jika cocok, hapus kurung buka dari stack
            } else {
                return false; // Jika tidak cocok (misal '[' ketemu ')'), maka salah!
            }
        }
    }

    // Di akhir, jika stack kosong berarti semua punya pasangan
    return st.empty(); 
}

int main() {
    // Kita uji coba dengan 2 string berbeda
    string rumusBenar = "{[()]}";
    string rumusSalah = "{[(])}"; // Urutannya ngaco

    cout << "=== PENGUJIAN ADVANCED STACK ===\n\n";

    if (cekKurungSempurna(rumusBenar)) {
        cout << rumusBenar << " -> Rumus VALID!\n";
    } else {
        cout << rumusBenar << " -> Rumus ERROR/TIDAK VALID!\n";
    }

    if (cekKurungSempurna(rumusSalah)) {
        cout << rumusSalah << " -> Rumus VALID!\n";
    } else {
        cout << rumusSalah << " -> Rumus ERROR/TIDAK VALID!\n";
    }

    return 0;
}