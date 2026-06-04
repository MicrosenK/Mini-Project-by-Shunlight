#include <iostream>
#include <string>
using namespace std;

// 1. STRUKTUR NODE
struct Mahasiswa {
    long long nrp;
    string nama;
    string divisi;
    Mahasiswa* left;
    Mahasiswa* right;
};

// 2. FUNGSI MEMBUAT NODE BARU
Mahasiswa* buatNode(long long nrp, string nama, string divisi) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nrp = nrp;
    newNode->nama = nama;
    newNode->divisi = divisi;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 3. FUNGSI INSERT (O(log n))
Mahasiswa* insertData(Mahasiswa* root, long long nrp, string nama, string divisi) {
    if (root == NULL) return buatNode(nrp, nama, divisi);
    
    if (nrp < root->nrp)
        root->left = insertData(root->left, nrp, nama, divisi);
    else if (nrp > root->nrp)
        root->right = insertData(root->right, nrp, nama, divisi);
        
    return root;
}

// 4. FUNGSI TRAVERSAL IN-ORDER
void inOrder(Mahasiswa* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << "NRP: " << root->nrp << " | " << root->nama << endl;
        inOrder(root->right);
    }
}

// 5. FUNGSI SEARCH / PENCARIAN
Mahasiswa* cariNRP(Mahasiswa* root, long long target) {
    if (root == NULL || root->nrp == target) return root;
    if (target < root->nrp) return cariNRP(root->left, target);
    return cariNRP(root->right, target);
}

// 6. FUNGSI BANTUAN UNTUK DELETE (Mencari Nilai Minimum)
Mahasiswa* findMin(Mahasiswa* node) {
    Mahasiswa* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 7. FUNGSI DELETE NODE LENGKAP
Mahasiswa* deleteNode(Mahasiswa* root, long long key) {
    if (root == NULL) return root;

    if (key < root->nrp) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->nrp) {
        root->right = deleteNode(root->right, key);
    } else {
        // Kasus 1 & 2
        if (root->left == NULL) {
            Mahasiswa* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Mahasiswa* temp = root->left;
            delete root;
            return temp;
        }
        // Kasus 3: Node dengan 2 anak
        Mahasiswa* temp = findMin(root->right);
        root->nrp = temp->nrp;
        root->nama = temp->nama;
        root->divisi = temp->divisi;
        root->right = deleteNode(root->right, temp->nrp);
    }
    return root;
}

// --- PROGRAM UTAMA ---
int main() {
    Mahasiswa* root = NULL;
    
    // Insert Data
    root = insertData(root, 5025201050, "Andika", "UKM Robotika");
    root = insertData(root, 5025201020, "Bagas", "Asdos Sisop");
    root = insertData(root, 5025201070, "Citra", "Divisi PSDM");
    root = insertData(root, 5025201010, "Doni", "Mahasiswa");
    root = insertData(root, 5025201030, "Eka", "UKM Robotika");

    cout << "--- TAMPILAN IN-ORDER (Otomatis Terurut) ---" << endl;
    inOrder(root);
    cout << endl;

    // Simulasi Search
    cout << "--- MENCARI NRP 5025201070 ---" << endl;
    Mahasiswa* hasil = cariNRP(root, 5025201070);
    if(hasil) cout << "Ditemukan! Nama: " << hasil->nama << ", Divisi: " << hasil->divisi << endl;
    else cout << "Data tidak ditemukan!" << endl;
    cout << endl;

    // Simulasi Delete
    cout << "--- MENGHAPUS NRP 5025201020 (Bagas) ---" << endl;
    root = deleteNode(root, 5025201020);
    
    cout << "--- TAMPILAN IN-ORDER SETELAH DIHAPUS ---" << endl;
    inOrder(root);
    
    return 0;
}