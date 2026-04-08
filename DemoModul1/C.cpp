#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    queue<int> d, que;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') d.push(i);
        else que.push(i);
    }
    
    while (!d.empty() && !que.empty()) {
        int index1 = d.front(); d.pop();
        int index2 = que.front(); que.pop();
        
        if (index1 < index2) {
            d.push(index1 + n);
        } else {
            que.push(index2 + n);
        }
    }
    
    if (d.empty()) {
    cout << "Sudar" << endl;
    } else {
    cout << "Darsu" << endl;
    }
    
    return 0;
}