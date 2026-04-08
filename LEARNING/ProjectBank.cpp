#include <iostream>
#include <string> 
#include <ctime>
#include <unistd.h>
using namespace std;

void ptrtambah(int* ptr,int x){ 
    *ptr += x;
}
void ptrtarik(int* ptr1, int y){
    *ptr1 -= y;
}

int main() {
    int saldo,pilihan = 0, Rcounter = 0;
    string riwayat[100];

    cout << " ------ Welcome to Mini Bank----------" << endl;
    cout << "masukan saldo awal anda ";
    cin >> saldo;
    cout << "saldo anda sekarang adalah " << saldo << endl;
    cout << " " << endl;
    
    while (pilihan != 5) 
    {
    cout << "============================================"<< endl;
    cout << "    MINI BANK BY TERANGBENDERANG99          "<< endl;
    cout <<"==========================================="<< endl;
        cout << "1.Cek Saldo"<< endl;
        cout << "2.Tambah Saldo" << endl;
        cout << "3.Tarik Saldo"  << endl;
        cout << "4.Riwayat Transaksi" << endl;
        cout << "5.Keluar" << endl;
    cout << "============================================"<< endl;
        cout << "pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {
        cout << "SALDO SEKARANG BERNILAI " << saldo << endl;}
        else if(pilihan == 2) {
            cout << "MAU TAMBAH BERAPA ? ";
            int tambah;
            cin >> tambah;
            cout << "MEMPROSES TRANSAKSI..." << endl;
            sleep(1.25);
            cout << "DONE" << endl;
            ptrtambah(&saldo,tambah);
            riwayat[Rcounter] = "+ " + to_string(tambah); //mengubah dari int ke string
            Rcounter++;
        } 
        else if(pilihan == 3) {
            cout << "MAU TARIK BERAPA ? " << endl;
            int tarik;
            cin >> tarik;
                if (tarik > saldo) {
            cout << "MEMPROSES TRANSAKSI..." << endl;
            sleep(1.25);
                cout << "MAAF, SALDO TIDAK CUKUP" << endl;}
                else {
            cout << "MEMPROSES TRANSAKSI..." << endl;
            sleep(1.25);
            ptrtarik(&saldo,tarik);
            riwayat[Rcounter] = "- " + to_string(tarik);
            Rcounter++;
        }}
        else if (pilihan == 4){ 
            if (Rcounter == 0) {
                cout << "BELUM ADA TRANSAKSI" << endl;
            }          
                 for (int i = 0; i < Rcounter ; i++){
                    cout << i+1 << ". " << riwayat[i] << endl;
                 }}
        else if (pilihan == 5){
            cout << "TERIMAKASIH DAN SAMPAI JUMPA" << endl;
           return 0;
        }
    }
    }
