#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct tro {
    int count = 0;
    unordered_map<char, int> children;
};

vector<tro> trie;

void insert(const string& kata) {
    int node = 0;
    
    for (char c : kata) {
        if (trie[node].children.find(c) == trie[node].children.end()) {
            int isi = trie.size();
            trie.emplace_back();
            trie[node].children[c] = isi;
        }
        node = trie[node].children[c];
        trie[node].count++;
    }
}

int nuery(const string& prefix) {
    int node = 0;
    
    for (char c : prefix) {
        if (trie[node].children.find(c) == trie[node].children.end()) {
            return 0;
        }
        node = trie[node].children[c];
    }
    
    return trie[node].count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    trie.emplace_back(); 

    for (int i = 0; i < n; ++i) {
        string kata;
        cin >> kata;
        insert(kata);
    }
    int a;
    cin >> a;

    while (a--) {
        string prefix;
        cin >> prefix;
        cout << nuery(prefix) << "\n";
    }
    return 0;
}