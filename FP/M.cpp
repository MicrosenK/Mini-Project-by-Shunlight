#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Menyimpan urutan indeks node berdasarkan In-Order Traversal
vector<int> inorder_nodes;

void build_inorder(int u, int n) {
    if (u > n) return;
    build_inorder(2 * u, n);         // Kunjungi anak kiri
    inorder_nodes.push_back(u);      // Kunjungi node saat ini
    build_inorder(2 * u + 1, n);     // Kunjungi anak kanan
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    inorder_nodes.reserve(n);
    build_inorder(1, n);

    vector<int> val(n + 1);
    for (int i = 0; i < n; ++i) {
        val[inorder_nodes[i]] = a[i];
    }

   
    for (int i = 0; i < n; ++i) {
        int tree_index = inorder_nodes[i];
        
        if (tree_index == 1) {
           
            cout << -1 << (i == n - 1 ? "" : " ");
        } else {
           
            int parent_index = tree_index / 2;
            cout << val[parent_index] << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
    return 0;
}