#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class AntrianMahasiswa {
private:
    Mahasiswa* front; 
    Mahasiswa* rear;  

public:
    AntrianMahasiswa() : front(NULL), rear(NULL) {}
    void enqueue(const string& nama, const string& nim) {
    
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Mahasiswa* temp = front;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    void displayAntrian() const {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Antrian Mahasiswa:" << endl;
        Mahasiswa* temp = front;
        while (temp != NULL) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
};

int main() {

    AntrianMahasiswa antrian;
    antrian.enqueue("Andi", "2200003447");
    antrian.enqueue("Maya", "2347587888");
    antrian.enqueue("Munib", "2311110004");
    antrian.enqueue("Wulan", "2311110086");
    antrian.displayAntrian();
    antrian.dequeue();
    antrian.displayAntrian();

    return 0;
}
