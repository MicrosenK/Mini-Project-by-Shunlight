#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    deque<char> macM;
    deque<char> macT;
    deque<char> macS;

    cin >> n;
    for(int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        macM.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        if(temp == "PULL"){
            int tempInt;
            cin >> tempInt;
            int sizeM  = macM.size();

            if(tempInt > sizeM){
                cout << "Macaron Furina tidak sebanyak itu pls!" << endl;
            }else{
                for(int i = 0; i < tempInt-1; i++){
                    macT.push_back(macM.back());
                    macM.pop_back();
                }
                macS.push_back(macM.back());
                macM.pop_back();
                
                int sizeT = macT.size();

                for(int i = 0; i < sizeT; i++){
                    macM.push_back(macT.front());
                    macT.pop_front();
                }
            }
        }else if(temp == "PUT"){
            int sizeS = macS.size();
            for(int i = 0; i < sizeS; i++){
                macM.push_back(macS.back());
                macS.pop_back();
            }
        }else{
            cout << "Apa itu? Furina tidak paham!" << endl;
        }
    }
    int sizeM = macM.size();
    for(int i = 0; i < sizeM; i++){
        cout << macM.front() << " ";
        macM.pop_front();
    }
    cout << endl;
    int sizeS = macS.size();
    for(int i = 0; i < sizeS; i++){
        cout << macS.front() << " ";
        macS.pop_front();
    }
}