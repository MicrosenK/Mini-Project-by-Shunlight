#include <iostream>
#include <string>
#define MAX 10

using namespace std;

class QueueAkademik {
private:
    int front, rear;
    string antrian[MAX];
    string mahasiswa_dilayani;

public:
    QueueAkademik() {
        front = -1;
        rear = -1;
        mahasiswa_dilayani = "Belum ada";
    }

    bool isFull() { return rear == MAX - 1; }
    bool isEmpty() { return front == -1; }

    // Enqueue: Mahasiswa mengambil nomor/masuk [cite: 29, 37]
    void enqueue(string nama) {
        if (isFull()) {
            cout << "Antrian Penuh!" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        rear++;
        antrian[rear] = nama;
        cout << "[Sistem] Mahasiswa " << nama << " masuk antrian." << endl;
    }

    // Dequeue: Mahasiswa dipanggil/dilayani [cite: 30, 38]
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian Kosong, tidak ada yang dilayani." << endl;
            return;
        }
        mahasiswa_dilayani = antrian[front];
        cout << "\n[Layanan] Memanggil Mahasiswa " << mahasiswa_dilayani << " untuk dilayani." << endl;
        
        if (front >= rear) { // Reset jika antrian habis
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    // Menampilkan kondisi antrian [cite: 27, 28, 31, 32]
    void tampilkanKondisi() {
        cout << "\n--- Status Antrian Saat Ini ---" << endl;
        cout << "Sedang dilayani : " << mahasiswa_dilayani << endl;
        if (isEmpty()) {
            cout << "Antrian menunggu: Kosong" << endl;
        } else {
            cout << "Antrian menunggu: ";
            for (int i = front; i <= rear; i++) {
                cout << antrian[i] << (i == rear ? "" : ", ");
            }
            cout << "\nPosisi Front : " << antrian[front] << " (Indeks: " << front << ")";
            cout << "\nPosisi Rear  : " << antrian[rear] << " (Indeks: " << rear << ")";
            cout << endl;
        }
        cout << "-------------------------------" << endl;
    }
};

int main() {
    QueueAkademik layanan;

    // Simulasi [cite: 40, 41, 42, 43, 44, 45]
    layanan.enqueue("A"); // Mahasiswa A masuk [cite: 41]
    layanan.enqueue("B"); // Mahasiswa B masuk [cite: 41]
    layanan.enqueue("C"); // Mahasiswa C masuk [cite: 41]
    
    layanan.dequeue();    // Mahasiswa pertama (A) dilayani [cite: 42, 43]
    
    layanan.enqueue("D"); // Tambah mahasiswa D [cite: 44]
    
    layanan.tampilkanKondisi(); // Tampilkan kondisi antrian [cite: 45]

    return 0;
}