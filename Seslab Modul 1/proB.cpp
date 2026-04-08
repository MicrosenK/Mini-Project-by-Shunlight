#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    
    int x;
    cin >> x;

    priority_queue<pair<int,string>> pq;

    for(int i = 0; i < x; i++) {
        
        int P;
        string T;

        cin >> P;
        getline(cin >> ws, T);
        if(T.find("seru-seruan") == string::npos) { //kalau TIDAK mengandung "seru-seruan"
            pq.push({P, T});
        }
    }

    while(!pq.empty()) {
        cout << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}