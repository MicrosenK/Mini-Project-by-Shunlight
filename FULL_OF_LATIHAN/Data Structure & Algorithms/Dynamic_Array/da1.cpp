#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(33);
    num.push_back(523);
    num.push_back(1000);

    int last = num.back();
    num.pop_back();
    cout <<"cek ukuran : " << num.size() << endl;
    cout << "hapus angka ke : " << last <<  endl;
    
    for (int i = 0 ; i < num.size(); i++) {
        int num1 = num[i];
        cout << "isi index ke - " << i  << " adalah "<< num1 << endl;
    }
}