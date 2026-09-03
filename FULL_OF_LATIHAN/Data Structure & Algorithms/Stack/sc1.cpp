#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> tulisan;
    tulisan.push("Halo");   
    tulisan.push("nama");
    tulisan.push("saya");
    tulisan.push("Budi");

    tulisan.pop();
    tulisan.push("Razi");
    while(!tulisan.empty()){
        cout << tulisan.top() << endl;
        tulisan.pop();}
    }