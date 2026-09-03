#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ============================================================
// 1. HASH TABLE - Login
// ============================================================
const int TABLE_SIZE = 10;

struct Mahasiswa {
    string nim, nama, password;
    bool kosong = true;
};

Mahasiswa hashTable[TABLE_SIZE];

int hashFunc(const string& nim) {
    int h = 0;
    for (char c : nim) h += c;
    return h % TABLE_SIZE;
}

void htInsert(string nim, string nama, string password) {
    int i = hashFunc(nim);
    while (!hashTable[i].kosong) i = (i + 1) % TABLE_SIZE;
    hashTable[i] = {nim, nama, password, false};
    cout << "Registrasi: " << nama << " berhasil.\n";
}

bool htLogin(const string& nim, const string& pass) {
    int i = hashFunc(nim);
    while (!hashTable[i].kosong) {
        if (hashTable[i].nim == nim && hashTable[i].password == pass) {
            cout << "Login berhasil: " << hashTable[i].nama << "\n";
            return true;
        }
        i = (i + 1) % TABLE_SIZE;
    }
    cout << "Login gagal.\n";
    return false;
}

// ============================================================
// 2. LINKED LIST - Riwayat Aktivitas
// ============================================================
struct AktNode {
    string aktivitas;
    AktNode* next;
};

AktNode* riwayatHead = nullptr;

void riwayatTambah(const string& a) {
    AktNode* node = new AktNode{a, nullptr};
    if (!riwayatHead) { riwayatHead = node; }
    else {
        AktNode* curr = riwayatHead;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
    cout << "Aktivitas: " << a << "\n";
}

void riwayatTampilkan() {
    cout << "Riwayat:\n";
    AktNode* curr = riwayatHead;
    int i = 1;
    while (curr) { cout << "  " << i++ << ". " << curr->aktivitas << "\n"; curr = curr->next; }
}

// ============================================================
// 3. QUEUE - Antrian Konsultasi
// ============================================================
struct QNode {
    string nama, dosen;
    QNode* next;
};

QNode *qFront = nullptr, *qRear = nullptr;
int qNo = 0;

void qEnqueue(const string& nama, const string& dosen) {
    QNode* node = new QNode{nama, dosen, nullptr};
    if (!qRear) qFront = qRear = node;
    else { qRear->next = node; qRear = node; }
    cout << "Antrian ke-" << ++qNo << ": " << nama << " -> " << dosen << "\n";
}

void qDequeue() {
    if (!qFront) { cout << "Antrian kosong.\n"; return; }
    cout << "Melayani: " << qFront->nama << "\n";
    QNode* temp = qFront;
    qFront = qFront->next;
    if (!qFront) qRear = nullptr;
    delete temp;
}

void qTampilkan() {
    cout << "Sisa antrian:\n";
    QNode* curr = qFront;
    int i = 1;
    while (curr) { cout << "  " << i++ << ". " << curr->nama << "\n"; curr = curr->next; }
}

// ============================================================
// 4. TREE - Struktur Organisasi
// ============================================================
struct TreeNode {
    string nama;
    vector<TreeNode*> anak;
};

TreeNode* buatNode(const string& nama) {
    return new TreeNode{nama, {}};
}

void treeTampilkan(TreeNode* node, string prefix = "", bool isLast = true) {
    if (!node) return;
    cout << prefix << (isLast ? "L-- " : "|-- ") << node->nama << "\n";
    string childPrefix = prefix + (isLast ? "    " : "|   ");
    for (int i = 0; i < (int)node->anak.size(); i++)
        treeTampilkan(node->anak[i], childPrefix, i == (int)node->anak.size() - 1);
}

// ============================================================
// 5. GRAPH + DIJKSTRA - Navigasi
// ============================================================
const int V = 5;
vector<pair<int,int>> adj[V];
string namaLokasi[V];

void addLokasi(int i, const string& nama) { namaLokasi[i] = nama; }
void addJalan(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void dijkstra(int start, int end) {
    int dist[V]; fill(dist, dist + V, INT_MAX);
    int prev[V]; fill(prev, prev + V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
    }
    if (dist[end] == INT_MAX) { cout << "Tidak ada rute.\n"; return; }
    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) path.push_back(at);
    reverse(path.begin(), path.end());
    cout << "Rute: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << namaLokasi[path[i]];
        if (i < (int)path.size() - 1) cout << " -> ";
    }
    cout << " (" << dist[end] << " meter)\n";
}

// ============================================================
// 6. STACK - Undo KRS
// ============================================================
struct SNode {
    string matkul;
    SNode* next;
};

SNode* stackTop = nullptr;

void stackPush(const string& m) {
    stackTop = new SNode{m, stackTop};
    cout << "Tambah KRS: " << m << "\n";
}

void stackUndo() {
    if (!stackTop) { cout << "KRS kosong.\n"; return; }
    cout << "Undo: " << stackTop->matkul << " dihapus.\n";
    SNode* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
}

void stackTampilkan() {
    cout << "KRS: ";
    if (!stackTop) { cout << "(kosong)\n"; return; }
    SNode* curr = stackTop;
    while (curr) { cout << curr->matkul; if (curr->next) cout << ", "; curr = curr->next; }
    cout << "\n";
}

// ============================================================
// 7. PRIORITY QUEUE - Prioritas Layanan
// ============================================================
struct Layanan {
    string nama;
    int prioritas;
    bool operator>(const Layanan& o) const { return prioritas > o.prioritas; }
};

priority_queue<Layanan, vector<Layanan>, greater<Layanan>> pqLayanan;

void pqDaftar(const string& nama, int p) {
    pqLayanan.push({nama, p});
    cout << "Daftar: " << nama << " (prioritas " << p << ")\n";
}

void pqLayani() {
    if (pqLayanan.empty()) { cout << "Antrian kosong.\n"; return; }
    Layanan item = pqLayanan.top(); pqLayanan.pop();
    cout << "Dilayani: " << item.nama << "\n";
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "=== Smart Campus Navigation System ===\n\n";

    cout << "-- 1. LOGIN (Hash Table) --\n";
    htInsert("12345", "Andi", "pass123");
    htInsert("12346", "Budi", "budi456");
    htLogin("12345", "pass123");
    htLogin("12345", "salah");

    cout << "\n-- 2. RIWAYAT AKTIVITAS (Linked List) --\n";
    riwayatTambah("Login");
    riwayatTambah("Isi KRS");
    riwayatTambah("Konsultasi Dosen");
    riwayatTampilkan();

    cout << "\n-- 3. ANTRIAN KONSULTASI (Queue) --\n";
    qEnqueue("Andi", "Dr. Sari");
    qEnqueue("Budi", "Dr. Sari");
    qEnqueue("Citra", "Dr. Sari");
    qDequeue();
    qTampilkan();

    cout << "\n-- 4. ORGANISASI KAMPUS (Tree) --\n";
    TreeNode* rektor = buatNode("Rektor");
    TreeNode* wakAkad = buatNode("Wakil Rektor Akademik");
    wakAkad->anak.push_back(buatNode("Fakultas Teknik"));
    wakAkad->anak.push_back(buatNode("Fakultas Ekonomi"));
    TreeNode* wakMhs = buatNode("Wakil Rektor Kemahasiswaan");
    wakMhs->anak.push_back(buatNode("BEM"));
    rektor->anak.push_back(wakAkad);
    rektor->anak.push_back(wakMhs);
    treeTampilkan(rektor);

    cout << "\n-- 5. NAVIGASI KAMPUS (Graph + Dijkstra) --\n";
    addLokasi(0, "Gerbang");
    addLokasi(1, "Fak. Teknik");
    addLokasi(2, "Perpustakaan");
    addLokasi(3, "Kantin");
    addLokasi(4, "Rektorat");
    addJalan(0, 1, 200);
    addJalan(0, 2, 350);
    addJalan(1, 2, 150);
    addJalan(1, 3, 100);
    addJalan(2, 4, 200);
    addJalan(3, 4, 250);
    dijkstra(0, 4);
    dijkstra(3, 2);

    cout << "\n-- 6. KRS + UNDO (Stack) --\n";
    stackPush("IF101");
    stackPush("IF102");
    stackPush("IF103");
    stackUndo();
    stackTampilkan();

    cout << "\n-- 7. PRIORITAS LAYANAN (Priority Queue) --\n";
    pqDaftar("Andi (biasa)", 3);
    pqDaftar("Budi (beasiswa)", 1);
    pqDaftar("Citra (difabel)", 2);
    pqLayani();
    pqLayani();
    pqLayani();

    cout << "\n=== Selesai ===\n";
    return 0;
}