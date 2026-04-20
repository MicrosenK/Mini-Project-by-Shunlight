#include <iostream>

using namespace std;

// Struktur Node untuk merepresentasikan setiap elemen dalam Linked List
struct Node {
    int data;
    Node* next;
    
    // Constructor untuk inisialisasi node baru
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// Kelas Queue menggunakan Linked List
class Queue {
private:
    Node* front; // Pointer menunjuk ke elemen paling depan
    Node* rear;  // Pointer menunjuk ke elemen paling belakang

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Memeriksa apakah antrean kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Menambahkan elemen baru ke bagian belakang (rear)
    void enqueue(int item) {
        Node* newNode = new Node(item);
        
        // Jika antrean kosong, front dan rear menunjuk ke node yang sama
        if (rear == nullptr) {
            front = rear = newNode;
            cout << "[" << item << "] dimasukkan ke dalam antrean.\n";
            return;
        }
        
        // Tambahkan node baru di belakang rear, lalu pindahkan pointer rear
        rear->next = newNode;
        rear = newNode;
        cout << "[" << item << "] dimasukkan ke dalam antrean.\n";
    }

    // Dequeue: Menghapus dan mengembalikan elemen dari bagian depan (front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong! Tidak ada yang bisa dikeluarkan.\n";
            return;
        }
        
        // Simpan node depan ke variabel sementara
        Node* temp = front;
        
        // Pindahkan front ke node berikutnya
        front = front->next;
        
        // Jika setelah dihapus antrean menjadi kosong, update rear menjadi nullptr juga
        if (front == nullptr) {
            rear = nullptr;
        }
        
        cout << "[" << temp->data << "] dikeluarkan dari antrean.\n";
        
        // C++ mewajibkan kita membebaskan memori yang tidak terpakai
        delete temp; 
    }

    // Peek: Melihat elemen paling depan tanpa menghapusnya
    int peek() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
            return -1; // Mengembalikan nilai penanda (dummy)
        }
        return front->data;
    }

    // Menampilkan seluruh isi antrean
    void display() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
            return;
        }
        
        Node* current = front;
        cout << "Isi antrean (Depan -> Belakang): ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << "\n";
    }
    
    // Destructor untuk membersihkan sisa memori saat objek Queue dihancurkan
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// === Contoh Penggunaan ===
int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();
    
    cout << "Elemen paling depan saat ini: " << q.peek() << "\n";
    
    q.dequeue();
    q.display();
    
    q.dequeue();
    q.dequeue();
    
    // Mencoba dequeue saat kosong
    q.dequeue();
    
    return 0;
}