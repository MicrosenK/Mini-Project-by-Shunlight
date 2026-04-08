#include <iostream>
using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string hobi[3];
};

int main() {

    mahasiswa mhs[3];

    for(int i = 0; i < 3; i++) {

        cout << "Mahasiswa ke-" << i+1 << endl;

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nama: ";
        cin >> mhs[i].nama;

        for(int j = 0; j < 3; j++) {
            cout << "Hobi ke-" << j+1 << ": ";
            cin >> mhs[i].hobi[j];
        }

        cout << endl;
    }

    cout << "\nData Mahasiswa\n";

    for(int i = 0; i < 3; i++) {

        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nama: " << mhs[i].nama << endl;

        for(int j = 0; j < 3; j++) {
            cout << "Hobi: " << mhs[i].hobi[j] << endl;
        }

        cout << endl;
    }

    return 0;
}