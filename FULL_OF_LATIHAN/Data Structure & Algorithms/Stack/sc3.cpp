#include <iostream>
#include <string>
#include <stack>
//SOAL :
//MENGUBAH DARI KATA "ITS" --> "STI"
using namespace std;

int main() {
    stack<char> st;
    string kata = "ITS";
//LENGTH BERFUNGSI UNTUK MENGETAHUI ADA BERAPA BANYAK SUKU KATA !
    for(int i = 0 ; i < kata.length() ; i++) {
        char k = kata[i];
        st.push(k);
    }
  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
}