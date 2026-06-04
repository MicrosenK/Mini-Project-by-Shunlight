#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertData(Node* root, int val) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = val; temp->left = temp->right = NULL;
        return temp;
    }
    if (val < root->data) root->left = insertData(root->left, val);
    else root->right = insertData(root->right, val);
    return root;
}

// Fungsi Mengecek Kedalaman/Tinggi (Height) Tree
int hitungKedalaman(Node* root) {
    if (root == NULL) return 0;
    int kedalamanKiri = hitungKedalaman(root->left);
    int kedalamanKanan = hitungKedalaman(root->right);
    return max(kedalamanKiri, kedalamanKanan) + 1;
}

int main() {
    Node* rootSkewed = NULL;
    Node* rootSeimbang = NULL;
    
    // --- KASUS 1: SKEWED TREE --- (Data dimasukkan berurutan)
    for(int i = 1; i <= 7; i++) rootSkewed = insertData(rootSkewed, i);
    
    // --- KASUS 2: TREE SEIMBANG --- (Data diacak terpusat)
    int dataAcak[] = {4, 2, 6, 1, 3, 5, 7};
    for(int i = 0; i < 7; i++) rootSeimbang = insertData(rootSeimbang, dataAcak[i]);
    
    cout << "=== LAPORAN INVESTIGASI KEDALAMAN TREE ===" << endl;
    cout << "Total Data Node dimasukkan: 7 buah\n\n";
    
    cout << "[!] Skewed Tree (Berurutan): " << hitungKedalaman(rootSkewed) << " Level (Sangat Buruk!)" << endl;
    cout << "[V] Tree Seimbang (Acak): " << hitungKedalaman(rootSeimbang) << " Level (Optimal!)" << endl;

    return 0;
}