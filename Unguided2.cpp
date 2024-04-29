#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    const int JUMLAH_BUKU = 3; 

    // Mendeklarasikan array favorit dengan tipe buku dan ukuran JUMLAH_BUKU
    buku favorit[JUMLAH_BUKU];

    // Mengisi data ke dalam array favorit
    for (int i = 0; i < JUMLAH_BUKU; ++i) {
        cout << "Masukkan informasi buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, favorit[i].judulBuku);
        cout << "Pengarang: ";
        getline(cin, favorit[i].pengarang);
        cout << "Penerbit: ";
        getline(cin, favorit[i].penerbit);
        cout << "Tebal Halaman: ";
        cin >> favorit[i].tebalHalaman;
        cout << "Harga Buku: Rp ";
        cin >> favorit[i].hargaBuku;
        cin.ignore(); // Membersihkan newline character dari buffer input
    }

    // Menampilkan informasi buku favorit
    cout << "\nInformasi buku favorit:" << endl;
    for (int i = 0; i < JUMLAH_BUKU; ++i) {
        cout << "Buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku : " << favorit[i].judulBuku << endl;
        cout << "Pengarang : " << favorit[i].pengarang << endl;
        cout << "Penerbit : " << favorit[i].penerbit << endl;
        cout << "Tebal Halaman: " << favorit[i].tebalHalaman << " halaman" << endl;
        cout << "Harga Buku : Rp " << favorit[i].hargaBuku << endl << endl;
    }

    return 0;
}