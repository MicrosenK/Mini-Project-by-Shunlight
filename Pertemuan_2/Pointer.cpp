#include <iostream>
using namespace std;

int main() {
    int angka = 10;
    int *ptr = &angka;
    
    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Isi pointer: " << ptr << endl;
    cout << "Nilai melalui pointer: " << *ptr << endl;
}