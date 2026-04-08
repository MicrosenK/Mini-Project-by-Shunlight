#include <iostream> 
using namespace std;

/*Level 1 — Pointer Dasar
Soal 1 — Menambah Umur
Seorang siswa memiliki umur yang disimpan dalam variabel umur.
Guru ingin menambahkan umur siswa tersebut sebanyak 1 
tahun menggunakan sebuah function.*/
void jumlah(int* x) {
    *x += 1;
}
int main() {
    int umur;
    cin >> umur;
    jumlah(&umur);
    cout  << umur << endl;
}