#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    // Baca nama-nama penghuni
    vector<string> nama(x);
    for (int i = 0; i < x; i++) {
        cin >> nama[i];
    }
    
    // Mapping nama ke index
    unordered_map<string, int> inds;
    for (int i = 0; i < x; i++) {
        inds[nama[i]] = i;
    }
    
    // Array untuk menyimpan tujuan setiap orang (hanya SATU tujuan)
    vector<int> tujuan(x);
    for (int i = 0; i < x; i++) {
        string X, Y;
        cin >> X >> Y;
        int from = inds[X];
        int to = inds[Y];
        tujuan[from] = to;  // Langsung simpan tujuan
    }
    
    // Baca A dan B
    string A, B;
    cin >> A >> B;
    int start = inds[A];
    int target = inds[B];
    
    // Ikuti jalur dari start sampai ketemu target atau cycle
    vector<bool> visited(x, false);
    int now = start;
    
    while (!visited[now]) {
        if (now == target) {
            cout << "Oalah, ez ini mah!" << endl;
            return 0;
        }

        visited[now] = true;
        now = tujuan[now];  // Pindah ke tujuan surat orang ini
    }

    // Kalau udah visited tapi belum ketemu target
    cout << "cooked" << endl;
    return 0;
}