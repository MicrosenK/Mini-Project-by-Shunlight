#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue <unsigned long long> pq;
    unsigned long long n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        unsigned long long x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() >= 2) {
        if (!pq.empty()) {
            unsigned long long T = pq.top(); pq.pop();
            unsigned long long R = pq.top(); pq.pop();
            if (R != T) {
                unsigned long long total = T - R;
                pq.push(total);}}
    }
    if(pq.empty()) {
        cout << "0";
    } else {
        cout << pq.top();
        pq.pop();
    }
}