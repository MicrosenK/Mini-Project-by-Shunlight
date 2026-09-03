#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, pair<int,int>> pos;
    
    int n;
    cin >> n;
    vector<int> size_reg(n);
    
    for (int i = 0; i < n; i++)
    {
        string tuj;
        cin >> tuj;

        string name;
        int idx = 0;
        while (cin >> name && name != "end") {
            pos[name] = {i, idx};  // simpan {region_idx, posisi}
            idx++;
        }
        size_reg[i] = idx;  // simpan ukuran ring tuj ke-i
    }

    int f;
    cin >> f;
    
    while (f--)
    {
        string awal, tujuan;
        int K;
        cin >> awal >> tujuan >> K;

        // cek keberadaan karakter
        if (pos.count(awal) == 0 || pos.count(tujuan) == 0) {
            cout << "Signal lost\n";
            continue;
        }

        int a = pos[awal].first;   // region_idx src
        int b = pos[tujuan].first; // region_idx dst

        int dist;

        if (a == b) {
            int diff = abs(pos[awal].second - pos[tujuan].second);
            dist = min(diff, size_reg[a] - diff);

        } else {
            int zerox = min(pos[awal].second, size_reg[a] - 1 - pos[awal].second);
            int zeroy = min(pos[tujuan].second, size_reg[b] - 1 - pos[tujuan].second);

            int distreg = abs(a - b);
            distreg = min(distreg, n - distreg);
            dist = zerox + zeroy + distreg + 2;
        }

        if (K >= dist) {
            cout << "Connected on " << dist << " second\n";
        } else {
            cout << "Signal lost\n";
        }
    }

    return 0;
}
