#include <iostream>
using namespace std;

/*Soal 2 — Diskon Harga
Sebuah toko memberikan diskon 5000 rupiah untuk sebuah barang.
Harga barang disimpan dalam variabel harga*/
void diskon(int* ptr){
    *ptr -= 5000;
}

int main() {
    int harga;
    cin >> harga;
    diskon(&harga);
    cout << harga << endl;
}