#include <iostream>
using namespace std;

// Struktur untuk Node
struct Node {
    int data;
    Node* next;
    
    // Constructor untuk inisialisasi node baru
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah data di akhir
    void append(int data) {
        Node* newNode = new Node(data);
        
        // Jika list kosong, jadikan head
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        // Telusuri sampai node terakhir
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // Sambungkan node terakhir dengan node baru
        temp->next = newNode;
    }

    // Fungsi untuk menampilkan list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sll;
    sll.append(10);
    sll.append(20);
    sll.append(30);
    
    cout << "Singly Linked List: ";
    sll.display(); 
    // Output: [10] -> [20] -> [30] -> NULL
    
    return 0;
}