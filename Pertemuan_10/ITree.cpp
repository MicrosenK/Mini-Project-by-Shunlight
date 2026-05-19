#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struktur node untuk merepresentasikan folder
struct TreeNode {
    string name;
    TreeNode* parent;
    vector<TreeNode*> children;

    // Konstruktor
    TreeNode(string folderName, TreeNode* parentNode = nullptr) {
        name = folderName;
        parent = parentNode;
    }
};

class FileSystemTree {
private:
    TreeNode* root;

    // Fungsi rekursif untuk mencari node
    TreeNode* searchNode(TreeNode* node, const string& name) {
        if (!node) return nullptr;
        if (node->name == name) return node;
        
        for (TreeNode* child : node->children) {
            TreeNode* found = searchNode(child, name);
            if (found) return found;
        }
        return nullptr;
    }

    // Fungsi rekursif untuk menghapus node beserta keturunannya
    void deleteTree(TreeNode* node) {
        if (!node) return;
        for (TreeNode* child : node->children) {
            deleteTree(child);
        }
        delete node;
    }

    // Fungsi rekursif untuk menghitung jumlah folder
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        int count = 1; // Menghitung node saat ini
        for (TreeNode* child : node->children) {
            count += countNodes(child);
        }
        return count;
    }

    // Menampilkan hierarki direktori
    void printHierarchy(TreeNode* node, int depth) {
        if (!node) return;
        
        for (int i = 0; i < depth; ++i) {
            cout << "  |";
        }
        if (depth > 0) cout << "-- ";
        
        cout << node->name << endl;
        
        for (TreeNode* child : node->children) {
            printHierarchy(child, depth + 1);
        }
    }

    // Preorder Traversal (Root - Children)
    void printPreorder(TreeNode* node) {
        if (!node) return;
        cout << node->name << " ";
        for (TreeNode* child : node->children) {
            printPreorder(child);
        }
    }

    // Postorder Traversal (Children - Root)
    void printPostorder(TreeNode* node) {
        if (!node) return;
        for (TreeNode* child : node->children) {
            printPostorder(child);
        }
        cout << node->name << " ";
    }

public:
    // Inisialisasi root sistem file
    FileSystemTree(string rootName) {
        root = new TreeNode(rootName);
    }

    // Destruktor
    ~FileSystemTree() {
        deleteTree(root);
    }

    // 1. Membuat folder baru
    bool createFolder(string parentName, string folderName) {
        TreeNode* parent = searchNode(root, parentName);
        if (parent) {
            parent->children.push_back(new TreeNode(folderName, parent));
            return true;
        }
        cout << "Gagal: Parent folder '" << parentName << "' tidak ditemukan.\n";
        return false;
    }

    // 2. Menghapus folder (beserta isinya)
    bool deleteFolder(string folderName) {
        if (folderName == root->name) {
            cout << "Gagal: Tidak dapat menghapus Root direktori.\n";
            return false;
        }
        
        TreeNode* node = searchNode(root, folderName);
        if (node) {
            TreeNode* parent = node->parent;
            // Hapus node dari vector anak milik parent-nya
            auto it = remove(parent->children.begin(), parent->children.end(), node);
            parent->children.erase(it, parent->children.end());
            
            // Hapus dari memori
            deleteTree(node);
            cout << "Folder '" << folderName << "' berhasil dihapus.\n";
            return true;
        }
        cout << "Gagal: Folder '" << folderName << "' tidak ditemukan.\n";
        return false;
    }

    // 3. Menampilkan struktur direktori
    void displayHierarchy() {
        cout << "\n=== Struktur Direktori ===" << endl;
        printHierarchy(root, 0);
        cout << "==========================\n" << endl;
    }

    // 4. Mencari folder tertentu
    void searchFolder(string folderName) {
        TreeNode* node = searchNode(root, folderName);
        if (node) {
            cout << "Pencarian: Folder '" << folderName << "' DITEMUKAN.\n";
        } else {
            cout << "Pencarian: Folder '" << folderName << "' TIDAK DITEMUKAN.\n";
        }
    }

    // 5. Menghitung jumlah folder
    void displayTotalFolders() {
        cout << "Total folder dalam sistem: " << countNodes(root) << " folder\n";
    }

    // 6. Menampilkan path lengkap suatu folder
    void displayFullPath(string folderName) {
        TreeNode* node = searchNode(root, folderName);
        if (!node) {
            cout << "Path: Folder '" << folderName << "' tidak ditemukan.\n";
            return;
        }
        
        string path = "";
        TreeNode* curr = node;
        while (curr != nullptr) {
            if (path == "") {
                path = curr->name;
            } else {
                path = curr->name + "/" + path;
            }
            curr = curr->parent;
        }
        cout << "Path lengkap untuk '" << folderName << "': " << path << endl;
    }

    // 7. Traversal Preorder
    void preorderTraversal() {
        cout << "Preorder Traversal  : ";
        printPreorder(root);
        cout << endl;
    }

    // 8. Traversal Postorder
    void postorderTraversal() {
        cout << "Postorder Traversal : ";
        printPostorder(root);
        cout << endl;
    }
};

int main() {
    // Inisialisasi dengan drive C:
    FileSystemTree fs("C:");

    // --- Skenario Pengujian ---
    
    // 1. Membuat Folder
    fs.createFolder("C:", "Users");
    fs.createFolder("C:", "Windows");
    fs.createFolder("C:", "Program_Files");
    fs.createFolder("Users", "Admin");
    fs.createFolder("Users", "Guest");
    fs.createFolder("Admin", "Documents");
    fs.createFolder("Admin", "Downloads");
    fs.createFolder("Documents", "Work");

    // 3. Menampilkan Struktur
    fs.displayHierarchy();

    // 6. Menampilkan Path Lengkap
    fs.displayFullPath("Work");
    fs.displayFullPath("Windows");
    
    // 4. Mencari Folder
    fs.searchFolder("Admin");
    fs.searchFolder("System32");

    // 5. Menghitung Jumlah Folder
    fs.displayTotalFolders();

    // Traversal
    cout << "\n--- Hasil Traversal ---\n";
    fs.preorderTraversal();
    fs.postorderTraversal();
    cout << "-----------------------\n\n";

    // 2. Menghapus Folder
    cout << ">>> Menghapus folder 'Guest'...\n";
    fs.deleteFolder("Guest");
    
    cout << ">>> Menghapus folder 'Users' (Akan menghapus Admin, Documents, Work, dll)...\n";
    fs.deleteFolder("Users");

    // Menampilkan struktur terbaru setelah penghapusan
    fs.displayHierarchy();
    fs.displayTotalFolders();

    return 0;
}