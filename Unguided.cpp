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
    HashNode(const Mahasiswa& data) : data(data), next(NULL) {}
};

// Class hash table untuk menyimpan data mahasiswa
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<HashNode*> table[TABLE_SIZE];

    // Fungsi hash sederhana untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(const string& nim) {
        int sum = 0;
        for (size_t i = 0; i < nim.size(); i++) {
            sum += nim[i];
        }
        return sum % TABLE_SIZE;
    }

public:
    // Menambahkan data mahasiswa ke dalam tabel hash
    void tambahData(const Mahasiswa& mahasiswa) {
        int index = hashFunc(mahasiswa.nim);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].empty() ? NULL : table[index][0];
        table[index].clear();
        table[index].push_back(newNode);
    }

    // Menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void hapusData(const string& nim) {
        int index = hashFunc(nim);
        for (vector<HashNode*>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it)->data.nim == nim) {
                delete *it;
                table[index].clear();
                cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariByNIM(const string& nim) {
        int index = hashFunc(nim);
        for (vector<HashNode*>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it)->data.nim == nim) {
                return &(*it)->data;
            }
        }
        return NULL;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai
    vector<Mahasiswa> cariByNilai(int minNilai, int maxNilai) {
        vector<Mahasiswa> hasil;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (vector<HashNode*>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
                if ((*it)->data.nilai >= minNilai && (*it)->data.nilai <= maxNilai) {
                    hasil.push_back((*it)->data);
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
                if (hasil != NULL) {
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
                for (vector<Mahasiswa>::iterator it = hasil.begin(); it != hasil.end(); ++it) {
                    cout << "NIM: " << it->nim << ", Nilai: " << it->nilai << endl;
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
