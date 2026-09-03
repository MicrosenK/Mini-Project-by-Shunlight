#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int num;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node(); //menyimpan alamat dari node yang baru itu kedalam variabel newNode; 
    newNode->num = value; //tembus ke isi struct lalu masukin nilai value nya!
    /*untuk mengakses isi dari struct nya itu harus
    pakai tanda -> karena dia bertipe sebuah pointer (alamat) contoh "0x077" */
    newNode->left = NULL; //sama
    newNode->right = NULL; //sama
    return newNode; //panggil lagi kalo artinya lu dah selesai membuat nih
}





