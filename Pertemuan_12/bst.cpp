// C++ Program untuk implementasi Binary Search Tree
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor node baru
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Fungsi rekursif untuk menyisipkan node baru
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    // Jika nilai lebih kecil, masukkan ke kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Jika nilai lebih besar, masukkan ke kanan
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi untuk mencetak tree dengan metode Inorder (Kiri - Induk - Kanan)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    
    // Memasukkan data ke dalam BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal dari BST: ";
    inorder(root);
    cout << endl;
    
    return 0;
}