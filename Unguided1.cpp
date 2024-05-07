#include <iostream>
using namespace std;
struct Node {
    string data;
    Node* next;
};

// Class untuk merepresentasikan queue menggunakan linked list
class Queue {
private:
    Node* front; // Node depan dari queue
    Node* rear;  // Node belakang dari queue

public:
    // Constructor untuk menginisialisasi queue kosong
    Queue() : front(NULL), rear(NULL) {}

    // Method untuk menambahkan elemen ke belakang queue
    void enqueue(const string& data) {
        // Membuat node baru
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        // Jika queue kosong, node baru menjadi front dan rear
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            // Menambahkan node baru di belakang queue
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Method untuk menghapus elemen dari depan queue
    void dequeue() {
        // Jika queue kosong, tidak ada yang dihapus
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        // Menyimpan node yang akan dihapus
        Node* temp = front;
        // Memindahkan front ke node berikutnya
        front = front->next;
        // Jika setelah penghapusan, queue menjadi kosong, rear juga harus diatur menjadi nullptr
        if (front == NULL) {
            rear = NULL;
        }
        // Menghapus node
        delete temp;
    }

    // Method untuk mengecek apakah queue kosong
    bool isEmpty() const {
        return front == NULL;
    }

    // Method untuk menampilkan isi dari queue
    void displayQueue() const {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian teller:" << endl;
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    // Membuat objek dari class Queue
    Queue queue;

    // Menambahkan elemen ke dalam queue
    queue.enqueue("Andi");
    queue.enqueue("Maya");

    // Menampilkan isi queue
    queue.displayQueue();

    // Menghapus elemen dari depan queue
    queue.dequeue();

    // Menampilkan isi queue setelah penghapusan
    queue.displayQueue();

    return 0;
}
