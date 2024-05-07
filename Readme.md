# <h1 align="center">Laporan Praktikum Modul 8 QUEUE</h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>


Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

#### Prinsip FIFO pada Queue

Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue. 

![Screenshot 2024-05-07 235328](https://github.com/sudolmunib/tugas-praktikum-8-QUEUE/assets/162574378/63c40946-6bad-40c9-9983-bac51e214353)

#### Fungsi Queue
Queue memiliki peran yang penting dalam berbagai aplikasi dan algoritma. Salah satu fungsi utamanya adalah mengatur dan mengelola antrean tugas atau operasi secara efisien. Dalam sistem komputasi, ia digunakan untuk menangani tugas-tugas seperti penjadwalan proses, antrean pesan, dan manajemen sumber daya.

#### Jenis-jenis Queue
Jenis struktur data ini dapat diklasifikasikan berdasarkan cara implementasinya, maupun berdasarkan penggunaannya. Di antara jenis-jenis tersebut adalah sebagai berikut.

Berdasarkan Implementasinya

- Linear/Simple Queue: Elemen-elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan tersebut.
- Circular Queue: Mirip dengan jenis linear, tetapi ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berputar.

Berdasarkan Penggunaan

- Priority Queue: Setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
- Double-ended Queue (Dequeue): Elemen dapat ditambahkan atau dihapus dari kedua ujung antrean.
#### Keuntungan dan Keterbatasan
Meskipun struktur data queue memiliki banyak kegunaan, kamu juga harus mengetahui beberapa keuntungan dan keterbatasan yang perlu diperhatikan sebelum menggunakannya.

#### Keuntungan

- Data berjumlah besar dapat dikelola dengan mudah dan efisien.
- Proses insert dan delete data dapat dilakukan dengan mudah karena mengikuti aturan first in first out (FIFO).
- Efisien dalam menangani tugas berdasarkan urutan kedatangan.
#### Keterbatasan
- Tidak efisien untuk pencarian elemen tertentu dalam antrean.
- Memerlukan alokasi memori yang cukup untuk menyimpan antrean.

#### Implementasi dan Contoh Penggunaan
Penerapannya dapat ditemukan dalam berbagai aspek pemrograman. Misalnya, dalam simulasi antrean di kasir supermarket, seperti pemrosesan tugas pada sistem operasi, sequence ketikan pada keyboard, dan masih banyak lagi.

Berikut contoh implementasi sederhana antrean menggunakan struktur data queue pada bahasa pemrograman C++

### GUIDED 1
Input
```Cpp
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Antriannya kosong atau tidak
    return back == 0;
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
## Output
![Screenshot 2024-05-08 000939](https://github.com/sudolmunib/tugas-praktikum-8-QUEUE/assets/162574378/91cb4bbd-e922-4a88-99c2-9a9c846e868d)

Interpretasi :

Program di atas adalah sebuah implementasi sederhana dari sebuah antrian (queue) menggunakan array 
Program tersebut dimulai dengan mendefinisikan beberapa variabel dan array yang digunakan untuk mengimplementasikan antrian. Variabel front dan back digunakan sebagai penanda untuk menandai elemen depan dan belakang antrian. Array queueTeller digunakan untuk menyimpan elemen-elemen dalam antrian.

Selanjutnya, terdapat beberapa fungsi yang didefinisikan untuk melakukan operasi-operasi pada antrian. Fungsi isFull() digunakan untuk memeriksa apakah antrian sudah penuh, sedangkan fungsi  isEmpty () digunakan untuk memeriksa apakah antrian kosong. Fungsi enqueue Antrian() digunakan untuk menambahkan elemen ke belakang antrian, sedangkan fungsi dequeueAntrian() digunakan untuk menghapus elemen dari depan antrian. Fungsi countQueue() digunakan untuk menghitung jumlah elemen dalam antrian, dan fungsi clearQueue() digunakan untuk menghapus semua elemen dalam antrian.

Pada bagian main(), beberapa operasi antrian dilakukan untuk menguji fungsionalitas program. Elemen-elemen "Andi" dan "Maya" ditambahkan ke dalam antrian menggunakan fungsi enqueueAntrian(). Kemudian, isi antrian ditampilkan menggunakan fungsi viewQueue() dan jumlah elemen dalam antrian ditampilkan menggunakan fungsi countQueue(). Selanjutnya, elemen pertama dalam antrian dihapus menggunakan fungsi dequeueAntrian(). Setelah itu, isi antrian dan jumlah elemen dalam antrian ditampilkan kembali. Terakhir, semua elemen dalam antrian dihapus menggunakan fungsi clearQueue(), dan isi antrian dan jumlah elemen dalam antrian ditampilkan kembali.

### Unguided 1
 [1]

Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list!

Input
```Cpp
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
```
Output
![Screenshot 2024-05-08 002019](https://github.com/sudolmunib/tugas-praktikum-8-QUEUE/assets/162574378/10ffd23d-2b6e-4796-8dfe-b6a983d5a822)

Interpretasi:

Program di atas adalah progrm sebuah antrian  menggunakan linked list. Linked list adalah struktur data linear yang terdiri dari serangkaian node, di mana setiap node terdiri dari data dan pointer yang menunjuk ke node berikutnya.

Program tersebut terdapat struktur Node yang digunakan untuk merepresentasikan setiap elemen dalam linked list. Setiap Node memiliki dua atribut: data untuk menyimpan nilai data, dan next untuk menunjukkan ke node berikutnya.

Kemudian, terdapat class Queue yang digunakan untuk merepresentasikan antrian menggunakan linked list. Di dalam class Queue, terdapat dua pointer yaitu front yang menunjuk ke node depan dari antrian, daN rear yang menunjuk ke node belakang dari antrian.

PEROGRAM tersebt memiliki beberapa method untuk melakukan operasi pada antrian. Method enqueue digunakan untuk menambahkan elemen ke belakang antrian. Method ini membuat node baru, mengisi data, dan menyesuaikan pointer rear untuk menunjuk ke node baru jika antrian masih kosong atau menambahkan node baru di belakang jika antrian sudah berisi elemen.

Method dequeue digunakan untuk menghapus elemen dari depan antrian. Method ini memindahkan pointer front ke node berikutnya, dan jika setelah penghapusan antrian menjadi kosong, pointer rear juga diatur menjadi NULL. Method isEmpty digunakan untuk memeriksa apakah antrian kosong atau tidak.

Method displayQueue digunakan untuk menampilkan isi antrian. Method ini mengecek apakah antrian kosong, dan jika tidak, menampilkan data dari setiap node dalam antrian.

Dalam fungsi main(), objek queue dari class Queue dibuat. Beberapa operasi antrian dilakukan untuk menguji fungsionalitas program. Elemen-elemen "Andi" dan "Maya" ditambahkan ke dalam antrian menggunakan method enqueue(). Kemudian, isi antrian ditampilkan menggunakan method displayQueue(). Elemen pertama dalam antrian dihapus menggunakan method dequeue(), dan setelah itu isi antrian ditampilkan kembali.

### Unguided 2
[2]

Dari nomor 1 buatlah konsep antri dengan atribut Nama Mahasiswa dan NIM Mahasiswa!

Input
```Cpp
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
```
Output
![Screenshot 2024-05-08 004516](https://github.com/sudolmunib/tugas-praktikum-8-QUEUE/assets/162574378/a5224046-8b9f-4add-ac91-2fe7fed33af2)


Interpretasi:

Program tersebut menggunakan linked list untuk menyimpan data mahasiswa. Setiap elemen dalam antrian direpresentasikan oleh struktur Mahasiswa, yang memiliki atribut nama, nim, dan pointer next yang menunjuk ke Mahasiswa selanjutnya dalam antrian.

Di dalam class AntrianMahasiswa, terdapat dua pointer yaitu front yang menunjuk ke Mahasiswa pertama dalam antrian, dan rear yang menunjuk ke Mahasiswa terakhir dalam antrian.

Program memiliki beberapa method untuk melakukan operasi pada antrian. Method enqueue digunakan untuk menambahkan data mahasiswa ke dalam antrian. Method ini membuat node baru, mengisi data mahasiswa, dan menyesuaikan pointer rear untuk menunjuk ke node baru jika antrian masih kosong atau menambahkan node baru di belakang jika antrian sudah berisi elemen.

Method dequeue digunakan untuk menghapus data mahasiswa dari depan antrian. Method ini memindahkan pointer front ke node berikutnya, dan jika setelah penghapusan antrian menjadi kosong, pointer rear juga diatur menjadi NULL.

Method isEmpty digunakan untuk memeriksa apakah antrian kosong atau tidak.

Method displayAntrian digunakan untuk menampilkan data mahasiswa dalam antrian. Method ini mengecek apakah antrian kosong, dan jika tidak, menampilkan data mahasiswa dari setiap node dalam antrian.

Dalam fungsi main(), objek antrian dari class AntrianMahasiswa dibuat. Beberapa operasi antrian dilakukan untuk menguji fungsionalitas program. Data mahasiswa "Andi", "Maya", "Munib", dan "Wulan" ditambahkan ke dalam antrian menggunakan method enqueue(). Kemudian, isi antrian ditampilkan menggunakan method displayAntrian(). Data mahasiswa pertama dalam antrian dihapus menggunakan method dequeue(), dan setelah itu isi antrian ditampilkan kembali.

#### Kesimpulan
Queue adalah struktur data linear yang sangat penting dalam pengembangan perangkat lunak karena mengikuti prinsip First-In, First-Out (FIFO). Ini berarti elemen pertama yang dimasukkan ke dalam queue adalah yang pertama kali dikeluarkan, sehingga mirip dengan antrian di kehidupan sehari-hari di mana orang yang datang pertama kali dilayani terlebih dahulu.

Operasi dasar pada queue meliputi enqueue (penambahan elemen), dequeue (penghapusan elemen), isEmpty (pengecekan apakah queue kosong), dan isFull (pengecekan apakah queue penuh). Enqueue dilakukan pada bagian belakang queue, sementara dequeue dilakukan pada bagian depan queue. Queue juga memungkinkan akses cepat ke elemen pertama melalui operasi front tanpa menghapusnya.

Daftar Pustaka
[1] Christodoulou, M. & Szczygiel, E. (2018). Algoritmic and programming.
P.T.E.A. Wszechnica Sp. Z.o.o.

[2] Hermin, F. & Widyati, R. (2004). Komputer II. Penerbit Universitas Terbuka.

