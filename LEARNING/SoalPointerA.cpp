#include <iostream>
using namespace std;

void tambahSaldo(int* ptr, int bonus) {
    *ptr += bonus;
}
int main() {
    int saldo, bon;
    cin >> saldo >> bon;
    tambahSaldo(&saldo,bon);
    cout << saldo << "" << bon << endl;
}