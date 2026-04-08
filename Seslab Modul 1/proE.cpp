#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;  
    vector<int> arr;
    
    for(int j = 0; j < T; j++) {
        int op;
        cin >> op;  
        
        if(op == 1) {
            int x;
            cin >> x;
            arr.push_back(x);}

        else if(op == 2) {
            int x;
            cin >> x;
            for(int i = 0; i < arr.size(); i++) {
                arr[i] += x;}}

        else if(op == 3) {
            if(arr.empty()) {
                cout << "kosong woe" << endl;
            } else {
                arr.pop_back();}}

        else if(op == 4) {
            if(arr.empty()) {
                cout << "gaada isinya :(" << endl;
            } else {
                for(int i = 0; i < arr.size(); i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;}}

        else if(op == 5) {
            int y, x;
            cin >> y >> x;
            arr.insert(arr.begin() + y, x);
        }
    } return 0;}