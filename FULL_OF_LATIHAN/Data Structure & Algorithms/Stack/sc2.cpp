#include <iostream> 
#include <stack>
#include <string>

using namespace std;
//SOAL:
//AMBIL BUKU YANG TELAH DITUMPUK DARI BAWAH KE ATAS !
int main() {
    stack<string> st;
    st.push("Matematika");
    st.push("Fisika");
    st.push("Struktur Data");

    while(!st.empty()){
    cout << "Mengambil buku : " << st.top() << endl;
    st.pop();
    }

    return 0;
}