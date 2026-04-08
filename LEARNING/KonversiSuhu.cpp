#include <iostream>
using namespace std;

int main() {
    string suhu1;
    string comp1;
    cout << " ====== Suhu Konversi ======="  << endl;
    cout << "masukin suhu nya berapa " << endl;
    cin >> suhu1;
    cout << "suhu sekarang adalah " << suhu1 << " derajat" << endl;
    cout << suhu1 << " derajat apa nih ? (English Only) " <<endl;  
     cin >> comp1;
     cin.ignore();

    if (comp1 == "Celcius" || comp1 == "celcius" ) {
        string comp2;
        cout << "mau ubah kemana nih ? " << endl;
        cin >> comp2;

        if (comp2 == "Fahrenheit" || comp2 == "fahrenheit") {
            float F;
            float ffloat = stof(suhu1); //ubah dari string ke integer dll
            F = (ffloat * 1.8) + 32.0;
            cout << "Jadi" << F << " F" << endl;
        }
        else if (comp2 == "Kelvin" || comp2 == "kelvin") {
            float K;
            float kfloat = stof(suhu1);
            K = kfloat + 273.15;
            cout << "Jadi " << K << " K" << endl;
        }
    if (comp1 == "Kelvin" || comp1 == "kelvin" ) {
        string comp3;
        cout << "mau ubah kemana nih ? " << endl;
        cin >> comp3;
        if (comp3 == "Celcius" || comp3 == "celcius" ) {
            float C;
            float Cfloat = stof(comp1);
            C = Cfloat - 273.15;
            cout << "Jadi " << C << " C" << endl;
        }
    }

  }
}