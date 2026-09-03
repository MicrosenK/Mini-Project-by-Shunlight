#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> num;
    int jmlh, angka, total = 0;
    cout << "Masukan jumlah data suhu : ";
    cin >> jmlh;

    for (int i = 0; i < jmlh; i++)
    {
        cout << "Masukin suhu ke - " << i + 1 << ": ";
        cin >> angka;
        num.push_back(angka);
    }
    //CEK MAXIMUM SUHU
    int max = num[0];
    for(int i = 1 ; i < num.size() ; i++) {
        if(num[i] > max){
            max = num[i];
        }
    }

    for (int i = 0 ; i < num.size() ; i++) {
         total += num[i];
    }

    double rata = ((double)total/jmlh);
    cout << "--- HASIL ANALISIS SENSOR ---" << endl;
    cout << "Jumlah data yang tersimpan di vector : " << jmlh << endl;
    cout << "Suhu tertinggi (Maksimum) : " << max << " Celcius"<<endl;
    cout << "Total seluruh suhu adalah : " << total << endl;
    cout << "Rata-rata suhu ruangan : " << rata << " Celcius" <<endl;

    }