#include <iostream>
using namespace std;

// Struktur untuk Doubly Node
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    
    DoublyNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        DoublyNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        // Hubungkan node terakhir dengan node baru
        temp->next = newNode;
        // Pointer prev node baru menunjuk ke node terakhir
        newNode->prev = temp;
    }

    void display() {
        DoublyNode* temp = head;
        cout << "NULL <- ";
        while (temp != nullptr) {
            cout << "[" << temp->data << "] <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(100);
    dll.append(200);
    dll.append(300);
    
    cout << "Doubly Linked List: ";
    dll.display();
    // Output: NULL <- [100] <-> [200] <-> [300] <-> NULL
    
    return 0;
}