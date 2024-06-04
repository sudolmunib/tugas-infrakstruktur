# <h1 align="center">Laporan Praktikum 11 Hash Table </h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

#### Dasar Teori
Hash Table (Tabel Hash) adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data, di mana setiap elemen dalam kumpulan data memiliki kunci (key) yang unik dan nilainya (value) terkait. Konsep utama di balik tabel hash adalah penggunaan fungsi hash untuk mengonversi kunci menjadi alamat atau indeks di dalam tabel, sehingga memungkinkan pencarian dan pengambilan data dengan efisien.

Pada dasarnya, tabel hash berfungsi sebagai penyimpanan asosiatif, di mana data disimpan dalam bentuk pasangan kunci-nilai. Proses ini melibatkan penggunaan fungsi hash untuk menghasilkan indeks unik dari kunci, dan nilai yang sesuai akan disimpan pada indeks tersebut.

Salah satu keuntungan utama dari tabel hash adalah kecepatan akses dan pencarian data yang sangat efisien. Ketika kita ingin mencari nilai berdasarkan kunci, kita hanya perlu melakukan proses hashing pada kunci untuk mengetahui lokasi penyimpanan datanya, sehingga tidak perlu mencari secara berurutan seperti pada struktur data lainnya seperti array atau list.

Namun, perlu diingat bahwa pada situasi tertentu, bisa saja terjadi tabrakan hash (hash collision), yaitu ketika dua kunci berbeda menghasilkan indeks yang sama. Untuk menangani tabrakan ini, metode penyelesaian tabrakan (collision resolution) digunakan, seperti linear probing, chaining, atau double hashing.

Hash table digunakan dalam berbagai aplikasi, termasuk dalam basis data, kamus (dictionary), dan kebanyakan algoritma yang membutuhkan pencarian atau pengelompokan data dengan cepat dan efisien.

Fungsi Hash Table
Fungsi utama dari Hash Table (Tabel Hash) adalah untuk menyediakan struktur data yang memungkinkan pencarian, penyisipan, dan penghapusan data dengan efisien. Berikut adalah beberapa fungsi utama dari Hash Table:

1. Pencarian (Search)
Hash Table memungkinkan pencarian data berdasarkan kunci (key) dengan cepat. Saat kita ingin mencari nilai berdasarkan kunci, fungsi hash akan mengonversi kunci menjadi indeks, dan nilai yang sesuai dapat diakses langsung dari indeks tersebut, menghasilkan waktu akses yang konstan (O(1)).

2. Penyisipan (Insertion)
Hash Table memungkinkan penambahan data baru dengan kunci dan nilainya. Saat kita ingin menyisipkan data baru, fungsi hash akan mengonversi kunci menjadi indeks, dan nilai tersebut akan disimpan pada indeks yang sesuai. Proses ini dapat dilakukan dengan waktu yang konstan (O(1)) pada kebanyakan kasus, membuatnya sangat efisien.

3. Penghapusan (Deletion)
Hash Table memungkinkan penghapusan data berdasarkan kunci. Saat kita ingin menghapus data, hash table akan menggunakan fungsi hash untuk menemukan indeks data yang sesuai dengan kunci dan menghapusnya dari tabel. Seperti pencarian dan penyisipan, operasi penghapusan juga berjalan dengan waktu yang konstan (O(1)) dalam kebanyakan kasus.

4. Asosiasi Kunci-Nilai (Key-Value Association)
Hash Table menyimpan data dalam bentuk pasangan kunci-nilai (key-value). Ini memungkinkan kita untuk mengaitkan kunci dengan nilai tertentu sehingga kita dapat dengan mudah mengakses nilai tersebut ketika diberikan kunci.

5. Kecepatan Akses
Salah satu keunggulan utama dari Hash Table adalah kecepatan aksesnya. Dengan menggunakan fungsi hash, proses mencari dan mengakses data menjadi sangat cepat karena kita dapat langsung menuju lokasi data tanpa perlu mencari secara berurutan.

Cara Membuat
Untuk membuat Hash Table (Tabel Hash), Anda dapat mengikuti langkah-langkah berikut:

1. Tentukan Ukuran Tabel
Pertama, tentukan ukuran tabel hash yang sesuai untuk kebutuhan Anda. Ukuran tabel haruslah bilangan prima agar membantu mengurangi jumlah tabrakan hash dan mendistribusikan data dengan lebih merata.

2. Buat Struktur Data
Buat struktur data untuk menyimpan pasangan kunci-nilai (key-value) dalam tabel hash. Dalam beberapa bahasa pemrograman, Anda dapat menggunakan array, linked list, atau struktur data lainnya untuk mewakili tabel hash.

3. Definisikan Fungsi Hash
Buatlah fungsi hash yang akan mengubah kunci (key) menjadi indeks dalam tabel hash. Fungsi hash harus menghasilkan nilai yang unik dan merata untuk setiap kunci untuk mencegah terjadinya tabrakan hash sebisa mungkin.

4. Penanganan Tabrakan
Tentukan dan terapkan metode penanganan tabrakan hash. Jika dua kunci berbeda menghasilkan indeks yang sama, Anda perlu memutuskan cara untuk menangani tabrakan tersebut. Metode umum untuk menangani tabrakan adalah dengan teknik chaining, yaitu menyimpan beberapa nilai dalam satu slot tabel hash menggunakan struktur data seperti linked list atau array.

5. Operasi Pencarian, Penyisipan, dan Penghapusan
Implementasikan fungsi-fungsi untuk melakukan operasi pencarian (search), penyisipan (insertion), dan penghapusan (deletion) data dalam tabel hash. Pastikan operasi ini bekerja dengan benar dan efisien, memanfaatkan fungsi hash dan metode penanganan tabrakan yang telah ditentukan sebelumnya.

6. Uji Coba dan Optimalisasi
Setelah selesai membuat Hash Table, lakukan uji coba untuk memastikan bahwa implementasi berfungsi dengan baik dan memberikan hasil yang diharapkan. Jika diperlukan, lakukan optimasi untuk meningkatkan kinerja Hash Table, termasuk pemilihan ukuran tabel yang lebih optimal atau perbaikan pada fungsi hash.

Perlu diingat bahwa implementasi Hash Table dapat bervariasi tergantung pada bahasa pemrograman yang digunakan. Setiap bahasa pemrograman memiliki cara tersendiri dalam membuat dan mengelola struktur data Hash Table. Pastikan untuk mengacu pada dokumentasi resmi bahasa pemrograman yang Anda gunakan atau cari referensi yang tepat untuk mendapatkan contoh dan panduan yang sesuai.

Guided 1

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table; // Array of pointers to Node

public:
    // Constructor
    HashTable() {
        table = new Node*[MAX_SIZE](); // Initialize table with nullptrs
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Key not found, insert new node at the beginning
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4); // Key 4 not found, no effect

    // Traversal
    ht.traverse();

    return 0;
}
```
Output
![Screenshot 2024-06-02 191853](https://github.com/sudolmunib/tugas-praktikum-11-Hash-Table/assets/162574378/37764c93-70df-4911-8d8e-3d406b87c194)

##### Interpretasi
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array.

Cara kerja dari program tersebut adalah sebagai berikut:

Cara kerjanya dimulai dengan inisialisasi tabel hash saat objek HashTable dibuat. Tabel hash ini adalah sebuah array dari pointer ke Node, dimana setiap elemennya diawali dengan nilai nullptr. Proses penyisipan data dilakukan melalui metode insert, dimana kunci data dihash menggunakan fungsi hash_func. Jika terjadi collision (dua kunci yang dihash ke indeks yang sama), data akan disisipkan dalam bentuk linked list di indeks yang bersangkutan.

Kemudian, untuk mencari data, digunakan metode get. Pertama, kunci data dihash untuk menemukan indeks di tabel hash, kemudian pencarian dilakukan pada linked list (jika collision terjadi) di indeks tersebut. Jika data ditemukan, nilai yang terkait dengan kunci tersebut dikembalikan; jika tidak, nilai -1 dikembalikan.

Proses penghapusan data dilakukan melalui metode remove, dimana kunci data dihash untuk menemukan indeks di tabel hash. Kemudian, pencarian dilakukan pada linked list (jika collision terjadi) di indeks tersebut. Jika data ditemukan, node yang mengandung data tersebut dihapus dari linked list.

Terakhir, metode traverse digunakan untuk mencetak semua pasangan kunci-nilai yang ada dalam tabel hash. Ini dilakukan dengan mengunjungi setiap elemen dalam tabel hash dan mencetak nilai-nilai yang ada dalam linked list di setiap indeks.

Melalui proses-proses tersebut, program menyediakan fungsionalitas dasar untuk penyimpanan, pencarian, dan penghapusan data dalam tabel hash. Konsep utama dari tabel hash adalah penggunaan fungsi hash untuk mengonversi kunci menjadi indeks dalam tabel, yang memungkinkan pencarian dan penyisipan data secara efisien.

Guided 2
Kode Program
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```
Output
![Screenshot 2024-06-02 192107](https://github.com/sudolmunib/tugas-praktikum-11-Hash-Table/assets/162574378/81d3ca6c-7a77-4808-9592-94d4dbb3bfd0)

#### Interpretasi
Pada program di atas, class HashNode merepresentasikan setiap node dalam hashtable, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan.

Cara kerja dari program tersebut adalah sebagai berikut:

Pertama, saat data dimasukkan menggunakan metode insert, nama yang diberikan di-hash menggunakan fungsi hashFunc untuk menghasilkan nilai hash. Nilai hash tersebut kemudian digunakan sebagai indeks dalam tabel hash untuk menentukan lokasi penyimpanan data. Jika terjadi tabrakan (collision), yang berarti dua nama menghasilkan nilai hash yang sama, data akan disimpan dalam bentuk linked list di indeks yang sama. Jika nama sudah ada dalam tabel hash, nomor telepon yang terkait akan diperbarui.

Kedua, saat dilakukan pencarian data menggunakan metode searchByName, nama yang diberikan di-hash untuk menemukan indeks dalam tabel hash. Jika nama ditemukan dalam vektor yang sesuai di tabel hash, nomor telepon yang terkait akan dikembalikan. Namun, jika nama tidak ditemukan, fungsi akan mengembalikan sebuah string kosong.

Ketiga, saat dilakukan penghapusan data menggunakan metode remove, nama yang diberikan di-hash untuk menemukan indeks dalam tabel hash. Jika nama ditemukan dalam vektor yang sesuai di tabel hash, node yang mengandung data tersebut akan dihapus dari vektor. Ini dilakukan dengan menghapus node dari linked list atau menggunakan erase untuk menghapus elemen dari vektor.

Terakhir, ketika dilakukan pencetakan isi tabel hash menggunakan metode print, program mencetak isi dari setiap vektor dalam tabel hash. Setiap pasangan kunci-nama dan nomor telepon dalam vektor dicetak, dengan format [nama, nomor_telepon].

Melalui proses-proses tersebut, program menyediakan fungsionalitas untuk penyimpanan, pencarian, dan penghapusan pasangan kunci-nama dan nomor telepon dalam sebuah tabel hash.

Tugas Praktikum
1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

JAWAB:

Kode Program
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk setiap mahasiswa
struct Mahasiswa {
    string nim;
    int nilai;
};

// Struktur data untuk setiap node di dalam tabel hash
struct HashNode {
    Mahasiswa data;
    HashNode* next;
    HashNode(const Mahasiswa& data) : data(data), next(nullptr) {}
};

// Class hash table untuk menyimpan data mahasiswa
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<HashNode*> table[TABLE_SIZE];

    // Fungsi hash sederhana untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(const string& nim) {
        int sum = 0;
        for (char c : nim) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    // Menambahkan data mahasiswa ke dalam tabel hash
    void tambahData(const Mahasiswa& mahasiswa) {
        int index = hashFunc(mahasiswa.nim);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].empty() ? nullptr : table[index][0];
        table[index].clear();
        table[index].push_back(newNode);
    }

    // Menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void hapusData(const string& nim) {
        int index = hashFunc(nim);
        for (HashNode* node : table[index]) {
            if (node->data.nim == nim) {
                delete node;
                table[index].clear();
                cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl; // Tambah keterangan
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariByNIM(const string& nim) {
        int index = hashFunc(nim);
        for (HashNode* node : table[index]) {
            if (node->data.nim == nim) {
                return &node->data;
            }
        }
        return nullptr;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa> cariByNilai(int minNilai, int maxNilai) {
        vector<Mahasiswa> hasil;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (HashNode* node : table[i]) {
                if (node->data.nilai >= minNilai && node->data.nilai <= maxNilai) {
                    hasil.push_back(node->data);
                }
            }
        }
        return hasil;
    }
};

int main() {
    HashTable hashTable;

    // Menu
    cout << "Menu:\n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Hapus Data Mahasiswa\n";
    cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
    cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai\n";
    cout << "0. Keluar\n";

    int pilihan;
    do {
        cout << "\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nim;
                int nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                Mahasiswa mahasiswa = {nim, nilai};
                hashTable.tambahData(mahasiswa);
                cout << "Data mahasiswa berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            }
            case 3: {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                Mahasiswa* hasil = hashTable.cariByNIM(nim);
                if (hasil != nullptr) {
                    cout << "NIM: " << hasil->nim << ", Nilai: " << hasil->nilai << endl;
                } else {
                    cout << "Data mahasiswa tidak ditemukan.\n";
                }
                break;
            }
            case 4: {
                int minNilai, maxNilai;
                cout << "Masukkan rentang nilai (minimal dan maksimal): ";
                cin >> minNilai >> maxNilai;
                vector<Mahasiswa> hasil = hashTable.cariByNilai(minNilai, maxNilai);
                cout << "Hasil pencarian berdasarkan rentang nilai " << minNilai << " - " << maxNilai << ":\n";
                for (const Mahasiswa& mahasiswa : hasil) {
                    cout << "NIM: " << mahasiswa.nim << ", Nilai: " << mahasiswa.nilai << endl;
                }
                break;
            }
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
```
Output

![Screenshot 2024-06-02 195442](https://github.com/sudolmunib/tugas-praktikum-11-Hash-Table/assets/162574378/e30fcf92-9a16-45cc-817c-45a863b53068)

![Screenshot 2024-06-02 195754](https://github.com/sudolmunib/tugas-praktikum-11-Hash-Table/assets/162574378/19ec4bca-a925-4cb6-a5df-0a848aebcccf)


#### Interpretasi

Kode program di atas merupakan implementasi dari hash table untuk menyimpan data mahasiswa. Hash table digunakan untuk menyimpan data mahasiswa berdasarkan NIM mereka. Berikut adalah penjelasan dari setiap bagian kode:

Struktur Data Mahasiswa (Mahasiswa)
- Digunakan untuk merepresentasikan setiap mahasiswa dalam program.
- Memiliki dua atribut: nim untuk Nomor Induk Mahasiswa dan nilai untuk nilai mahasiswa.

Struktur Data Node Hash (HashNode)
- Digunakan untuk menyimpan data mahasiswa dalam bentuk node di dalam tabel hash.
- Setiap node memiliki data mahasiswa dan pointer ke node berikutnya dalam kasus terjadi tumpang tindih (collision).

Class Hash Table (HashTable)
- Menyediakan operasi-operasi untuk menambah, menghapus, dan mencari data mahasiswa.
- Digunakan array dari linked list untuk menyimpan data.
- Fungsi hash sederhana digunakan untuk menentukan indeks di mana data mahasiswa akan disimpan dalam tabel hash.

Class Hash Table (HashTable)
- Menyediakan operasi-operasi untuk menambah, menghapus, dan - - - mencari data mahasiswa.
Digunakan array dari linked list untuk menyimpan data.
- Fungsi hash sederhana digunakan untuk menentukan indeks di mana - data mahasiswa akan disimpan dalam tabel hash.

#### Cara Kerja Program

Program tersebut bekerja dengan cara yang terstruktur dan efisien dalam menyimpan dan mengelola data mahasiswa. Ketika program dimulai, hash table dibuat dengan ukuran tertentu, yang ditentukan oleh konstanta TABLE_SIZE. Ketika pengguna memasukkan data mahasiswa baru, program menghitung nilai hash dari NIM mahasiswa tersebut menggunakan fungsi hash sederhana. Nilai hash ini kemudian digunakan untuk menentukan indeks di mana data mahasiswa akan disimpan dalam tabel hash.

Setiap slot dalam tabel hash berfungsi sebagai sebuah linked list, di mana setiap elemen linked list adalah node yang berisi data mahasiswa. Jika terjadi tumpang tindih (collision), yaitu dua atau lebih data mahasiswa memiliki nilai hash yang sama, maka data tersebut akan disimpan dalam slot yang sama dan dihubungkan secara berurutan dalam linked list.

Ketika pengguna memilih untuk menambahkan data mahasiswa, program akan menghitung nilai hash dari NIM mahasiswa tersebut, lalu menyimpan data mahasiswa tersebut dalam slot yang sesuai dalam tabel hash. Ketika pengguna memilih untuk menghapus data mahasiswa berdasarkan NIM, program akan mencari data mahasiswa tersebut dalam slot yang sesuai dalam tabel hash, lalu menghapusnya jika ditemukan. Setelah pengguna memilih untuk menghapus data mahasiswa, keterangan "Data berhasil dihapus" akan ditampilkan.

Ketika pengguna memilih untuk mencari data mahasiswa berdasarkan NIM, program akan mencari data mahasiswa tersebut dalam slot yang sesuai dalam tabel hash, dan kemudian mengembalikan data mahasiswa jika ditemukan. Jika tidak ditemukan, program akan memberikan pesan bahwa data mahasiswa tidak ditemukan.

Ketika pengguna memilih untuk mencari data mahasiswa berdasarkan rentang nilai, program akan memindai seluruh tabel hash dan linked list di dalamnya untuk mencari data mahasiswa yang memiliki nilai di dalam rentang yang diberikan. Hasil pencarian akan ditampilkan kepada pengguna. Setelah pengguna memilih untuk keluar dari program, program akan selesai.

#### Kesimpulan
Hash Table adalah sebuah struktur data yang mengorganisir data dalam bentuk pasangan kunci-nilai. Terdiri dari dua komponen utama, yaitu array atau vektor dan fungsi hash, hash table menggunakan teknik hashing untuk mengubah rentang nilai kunci menjadi rentang indeks array. Setiap bucket dalam array menyimpan satu atau beberapa item data, dan fungsi hash digunakan untuk menghasilkan nilai unik dari setiap item data yang digunakan sebagai indeks array. Dengan menggunakan hash table, pencarian data dapat dilakukan dalam waktu yang konstan, tergantung pada kasus terbaiknya.

Proses kerjanya adalah dengan memetakan input kunci ke nilai indeks array menggunakan fungsi hash, kemudian menyimpan data pada posisi indeks array yang dihasilkan. Saat data perlu dicari, input kunci digunakan sebagai parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan digunakan untuk mencari data. Dalam kasus collision, di mana dua atau lebih data memiliki nilai hash yang sama, hash table menggunakan teknik chaining untuk menyimpan data dalam slot yang sama.

Operasi yang dapat dilakukan pada hash table meliputi penambahan, penghapusan, pencarian, pembaruan, dan penelusuran data. Penambahan data dilakukan dengan menentukan posisi bucket yang tepat menggunakan fungsi hash, penghapusan dilakukan dengan mencari data menggunakan fungsi hash, pencarian dilakukan dengan memasukkan input kunci ke fungsi hash untuk menentukan posisi bucket, dan pembaruan dilakukan dengan mencari data menggunakan fungsi hash dan memperbarui data yang ditemukan. Penelusuran dilakukan untuk memproses semua data yang ada dalam hash table.

Terkait dengan penyelesaian collision, hash table menggunakan beberapa teknik, termasuk chaining (metode terbuka) dan probing (metode tertutup). Chaining mengatasi collision dengan menyimpan semua item data dengan nilai indeks yang sama ke dalam linked list. Sedangkan probing (penelusuran) dilakukan untuk mencari posisi kosong di bawah tempat terjadinya collision. Metode-metode dalam probing seperti linear, quadratic, dan double hashing memberikan cara yang berbeda untuk menentukan posisi kosong saat collision terjadi.

Kesimpulannya, hash table adalah struktur data yang efisien untuk menyimpan dan mengakses data dengan cepat. Dengan menggunakan fungsi hash yang tepat dan teknik penyelesaian collision yang efektif, hash table dapat menjadi alat yang sangat berguna dalam pengembangan aplikasi yang membutuhkan pengelolaan data yang efisien dan efektif.

[1] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

[2] Prestiliano, J. (2007). Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data.

[2] Santoso, L. E. (2004). STANDARD TEMPLATE LIBRARY C++ UNTUK MENGAJARKAN STRUKTUR DATA. Jurnal FASILKOM Vol, 2(2).