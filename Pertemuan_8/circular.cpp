#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Melingkar ke dirinya sendiri
            return;
        }
        
        Node* temp = head;
        // Berhenti jika next adalah head
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // Sambungkan node terakhir ke node baru
        temp->next = newNode;
        // Node baru menunjuk kembali ke head
        newNode->next = head;
    }

    void display() {
        if (head == nullptr) return;
        
        Node* temp = head;
        // Menggunakan do-while agar node head tetap dieksekusi pertama kali
        do {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        } while (temp != head);
        
        cout << "(Kembali ke Head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    
    cout << "Circular Linked List: ";
    cll.display();
    // Output: [1] -> [2] -> [3] -> (Kembali ke Head)
    
    return 0;
}