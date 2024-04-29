# <h1 align="center">Laporan Praktikum Modul 5 Struct</h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

## Dasar Teori 
Struktur adalah salah satu konsep penting yang ada dalam berbagai aspek kehidupan, baik itu di bidang ilmu pengetahuan, teknologi, seni, dan lain sebagainya. Dalam konteks umum, pengertian struktur adalah susunan atau pola yang teratur dari suatu benda, sistem, atau organisasi. Struktur memiliki peran penting dalam menjaga kestabilan, ketahanan, dan fungsionalitas suatu entitas.

Dalam pemrograman komputer, struktur data adalah cara penyusunan dan pengorganisasian data di dalam komputer. Struktur data berfungsi untuk menyimpan, mengakses, dan memanipulasi data secara efisien. Dalam pemrograman, berbagai jenis struktur data digunakan untuk mengatur dan mengelola data dalam program.

Beberapa jenis struktur data yang umum digunakan dalam pemrograman antara lain:

1. Array adalah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe yang sama. Data dalam array diindeks berdasarkan posisinya, sehingga memudahkan akses dan manipulasi data.

2. Linked list adalah struktur data yang terdiri dari sejumlah simpul yang saling terhubung. Setiap simpul menyimpan data dan pointer ke simpul berikutnya. Linked list memungkinkan penyisipan dan penghapusan data secara efisien.

3. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out). Data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang dikeluarkan. Operasi yang umum dilakukan pada stack adalah push (memasukkan data) dan pop (mengeluarkan data).

4. Queue adalah struktur data yang mengikuti prinsip FIFO (First In, First Out). Data yang pertama dimasukkan ke dalam queue akan menjadi data pertama yang dikeluarkan. Operasi yang umum dilakukan pada queue adalah enqueue (memasukkan data) dan dequeue (mengeluarkan data).

5. Tree adalah struktur data yang terdiri dari simpul-simpul yang terhubung dalam bentuk hierarki. Setiap simpul memiliki anak-anak yang terhubung ke simpul tersebut. Struktur data ini sering digunakan dalam representasi hirarki, seperti struktur direktori pada sistem operasi.
## Guided 

### Guided 1 

#### Kode Program 
```C++
#include <iostream>

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
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "TRIK AHLI NERAKA";
    favorit.pengarang = "Abdul munib";
    favorit.penerbit = "Gagas Media";a
    favorit.tebalHalaman = 50000;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
    return 0;
}
```
#### Output
![Screenshot 2024-04-29 124614](https://github.com/sudolmunib/tugas-praktikum-5-Struct/assets/162574378/c81693d6-d6ae-4f31-ab3d-6085ae492bed)

#### Interpretasi
Program tersebut bertujuan untuk menggambarkan serta mengatur informasi mengenai buku kesukaan individu. Melalui penggunaan struktur data, aplikasi ini memfasilitasi pengguna untuk menyimpan atribut-atribut terkait dengan buku, seperti judul, pengarang, penerbit, jumlah halaman, dan harga, dengan cara yang terstruktur dan teratur.

Berikut adalah penjelasan baris per baris dari kode tersebut:

>#include <iostream>: Ini adalah direktif pra-prosesor yang menyertakan file header <iostream>, yang memungkinkan program untuk menggunakan fungsi input-output standar dari C++.

>using namespace std;: Baris ini mendeklarasikan penggunaan namespace std, yang berarti bahwa kita dapat menggunakan nama-nama yang didefinisikan dalam namespace std tanpa menambahkan awalan std:: di depannya.

>struct buku { ... };: Ini mendefinisikan sebuah struktur (struct) bernama buku, yang berisi beberapa atribut atau properti seperti judulBuku, pengarang, penerbit, tebalHalaman, dan hargaBuku.

>int main() { ... }: Ini adalah fungsi utama dari program, yang merupakan tempat dimulainya eksekusi program.

>buku favorit;: Ini mendeklarasikan variabel bernama favorit dengan tipe data buku, yang merupakan instansi atau objek dari struktur buku.

>Pengisian data ke dalam variabel favorit:
favorit.judulBuku = "TRIK AHLI NERAKA";: Mengisi atribut judulBuku dari variabel favorit dengan nilai "TRIK AHLI NERAKA".

>favorit.pengarang = "Abdul munib";: Mengisi atribut pengarang dari variabel favorit dengan nilai "Abdul munib".

>favorit.penerbit = "Gagas Media";: Mengisi atribut penerbit dari variabel favorit dengan nilai "Gagas Media".

>favorit.tebalHalaman = 50000;: Mengisi atribut tebalHalaman dari variabel favorit dengan nilai 50000.

>favorit.hargaBuku = 79000;: Mengisi atribut hargaBuku dari variabel favorit dengan nilai 79000.

Berukut KOde Untuk Menampilkan informasi buku favorit:

>cout << "\tPengarang : " << favorit.pengarang << endl;: Menampilkan nama pengarang buku favorit yang disimpan dalam variabel favorit.pengarang.

>cout << "\tPenerbit : " << favorit.penerbit << endl;: Menampilkan nama penerbit buku favorit yang disimpan dalam variabel favorit.penerbit.

>cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;: Menampilkan jumlah halaman buku favorit yang disimpan dalam variabel favorit.tebalHalaman.

>cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;: Menampilkan harga buku favorit yang disimpan dalam variabel favorit.hargaBuku.

>return 0;: Ini adalah pernyataan yang mengindikasikan bahwa program telah berhasil dijalankan dan keluar dengan kode keluaran 0.

### Guided 2

#### Kode Program 
```C++
#include <iostream>
using namespace std;

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
    hewanDarat darat;
    hewanLaut laut;
};

int main() {
    hewan serigala;
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    serigala.darat.jumlahKaki = 4;
    serigala.darat.menyusui = true;
    serigala.darat.suara = "Auuu";

    cout << "\t\tHewan" << endl;
    cout << "\tNama hewan : " << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tNama hewan : " << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl;
    cout << "\tJumlah kaki : " << serigala.darat.jumlahKaki << endl;
    cout << "\tMenyusui : " << (serigala.darat.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << serigala.darat.suara << endl << endl;

    hewanLaut ikan;
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    cout << "\t\tHewan Laut" << endl;
    cout << "\tNama hewan : Ikan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}

```
#### Output
![Screenshot 2024-04-29 125917](https://github.com/sudolmunib/tugas-praktikum-5-Struct/assets/162574378/d6f4c1a1-f0b7-4501-855e-f4aaa63206c3)

#### Interpretasi 

Kode diatas menggunakn Struktur yang digunakan untuk menggabungkan berbagai jenis data menjadi satu kesatuan. Dalam contoh ini, tiga struktur didefinisikan:

hewanDarat: Menyimpan detail hewan darat seperti jumlah kaki, apakah hewan tersebut menyusui, dan suara yang dihasilkan.

hewanLaut: Berisi informasi tentang hewan laut seperti bentuk sirip dan pertahanan diri.

hewan: Menggabungkan informasi tentang hewan, baik darat maupun laut, serta atribut tambahan seperti nama, jenis kelamin, cara berkembang biak, alat pernafasan, tempat hidup, dan apakah hewan tersebut karnivora.

Di dalam fungsi main(), beberapa variabel dari struktur hewan dan hewanLaut diinisialisasi dan diisi dengan data. Selanjutnya, informasi dari variabel-variabel ini ditampilkan menggunakan perintah cout.

Secara keseluruhan, kode tersebut menunjukkan penggunaan struktur untuk mengatur dan menyimpan data yang saling terkait, serta cara mengakses dan menampilkan informasinya.




## Unguided 

### Unguided 1
[1]
Modifikasi tugas gided pertama, sehingga setiap item yang terdapat pada sruct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan. 

### Input
```C++
#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    Buku favorit;

    for (int i = 0; i < 5; ++i) {
        cout << "Masukkan informasi buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, favorit.judulBuku[i]);
        cout << "Pengarang: ";
        getline(cin, favorit.pengarang[i]);
        cout << "Penerbit: ";
        getline(cin, favorit.penerbit[i]);
        cout << "Tebal Halaman: ";
        cin >> favorit.tebalHalaman[i];
        cout << "Harga Buku: Rp ";
        cin >> favorit.hargaBuku[i];
        cin.ignore(); 
    }
    
    cout << "\nInformasi buku favorit:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku : " << favorit.judulBuku[i] << endl;
        cout << "Pengarang : " << favorit.pengarang[i] << endl;
        cout << "Penerbit : " << favorit.penerbit[i] << endl;
        cout << "Tebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "Harga Buku : Rp " << favorit.hargaBuku[i] << endl << endl;
    }

    return 0;
}
```
###### Interpretasi
Kode diatas program sederhana yang memungkinkan pengguna untuk memasukkan informasi tentang lima buku favorit mereka, seperti judul buku, pengarang, penerbit, tebal halaman, dan harga. Setelah informasi dimasukkan, program akan menampilkan kembali informasi tersebut.

Berikut adalah interpretasi langkah demi langkah dari kode tersebut:

Sebuah struktur bernama Buku didefinisikan. Struktur ini memiliki lima array untuk masing-masing atribut buku: judulBuku, pengarang, penerbit, tebalHalaman, dan hargaBuku.

Di dalam fungsi main(), sebuah objek favorit dari tipe Buku dibuat.
Sebuah loop for digunakan untuk meminta pengguna memasukkan informasi tentang lima buku favorit mereka. Loop berjalan dari 0 hingga 4 (lima kali), sesuai dengan indeks array.

Di setiap iterasi loop, program meminta pengguna untuk memasukkan informasi tentang buku ke-i:

Judul buku dimasukkan dengan menggunakan getline() karena judul buku bisa terdiri dari beberapa kata.

Pengarang, penerbit, tebal halaman, dan harga buku dimasukkan melalui input standar menggunakan operator >>.

Setelah memasukkan harga buku, cin.ignore() digunakan untuk membersihkan newline character (\n) dari input buffer sehingga getline() pada iterasi selanjutnya tidak langsung membaca newline character tersebut.

Setelah lima buku dimasukkan, program menampilkan informasi tentang buku-buku favorit tersebut. Ini dilakukan melalui loop for kedua yang juga berjalan dari 0 hingga 4.

Di setiap iterasi loop kedua, program menampilkan informasi tentang buku ke-i yang telah dimasukkan pengguna sebelumnya.
Program ini memungkinkan pengguna untuk dengan mudah memasukkan dan melihat informasi tentang beberapa buku favorit mereka.

User
Parafrase teks berikut: Kode tersebut adalah program sederhana yang memungkinkan pengguna untuk memasukkan informasi tentang lima buku favorit mereka, seperti judul buku, pengarang, penerbit, tebal halaman, dan harga. Setelah informasi dimasukkan, program akan menampilkan kembali informasi tersebut.
###### Output
![Screenshot 2024-04-29 131636](https://github.com/sudolmunib/tugas-praktikum-5-Struct/assets/162574378/93dd910a-7d0a-4361-acbc-4101791c6712)

### Unguided 2
[2]
Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided berjenis array. Bagaimana cara mengisi dan menampilkannya.

##### Jawab
Jika deklarasi variabel struct yang dibuat pada tugas guided memiliki jenis array, maka setiap elemen array akan menjadi instance terpisah dari struct tersebut. Artinya, kita akan memiliki beberapa instance dari struct tersebut yang dapat diakses menggunakan indeks array.

Untuk mengisi dan menampilkan data dari array variabel struct, kita dapat menggunakan pendekatan yang mirip dengan array biasa, namun dengan tambahan akses ke anggota-anggota struct.

Berikut adalah langkah-langkah umum untuk mengisi dan menampilkan data dari array variabel struct:

### Mengisi Data:
1. Lakukan iterasi melalui indeks array dari 0 hingga n-1, di mana n adalah ukuran array.
2. Di setiap iterasi, masukkan data ke setiap anggota struct menggunakan indeks array.
3. Ulangi langkah 2 untuk setiap anggota struct.
### Menampilkan Data:
1. Lakukan iterasi melalui indeks array dari 0 hingga n-1, di mana n adalah ukuran array.
2. Di setiap iterasi, tampilkan data dari setiap anggota struct menggunakan indeks array.
3. Ulangi langkah 2 untuk setiap anggota struct.

```cpp
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
```

###### Interpretasi

Deklarasi struktur buku: Struktur ini memiliki beberapa anggota seperti judulBuku, pengarang, penerbit, tebalHalaman, dan hargaBuku. Ini digunakan untuk menyimpan informasi tentang buku.

Di dalam fungsi main(), sebuah konstanta JUMLAH_BUKU dideklarasikan dengan nilai 3, menentukan jumlah buku yang akan dimasukkan oleh pengguna.

Array favorit dari tipe buku dideklarasikan dengan ukuran JUMLAH_BUKU. Ini akan digunakan untuk menyimpan informasi tentang beberapa buku favorit yang dimasukkan pengguna.

Sebuah loop for digunakan untuk meminta pengguna memasukkan informasi tentang buku-buku favorit mereka. Loop ini berjalan dari 0 hingga JUMLAH_BUKU - 1, sesuai dengan jumlah buku.

Di setiap iterasi loop, program meminta pengguna untuk memasukkan informasi tentang buku ke-i:

Judul buku dimasukkan menggunakan getline() karena judul buku mungkin terdiri dari beberapa kata.

Pengarang, penerbit, tebal halaman, dan harga buku dimasukkan melalui input standar menggunakan operator >>.

Setelah memasukkan harga buku, cin.ignore() digunakan untuk membersihkan newline character (\n) dari input buffer sehingga getline() pada iterasi berikutnya tidak terpengaruh.

Setelah informasi buku dimasukkan, program menampilkan informasi tentang buku-buku favorit tersebut. Ini dilakukan melalui loop for kedua yang juga berjalan dari 0 hingga JUMLAH_BUKU - 1.

Pada setiap iterasi loop kedua, program menampilkan informasi tentang buku ke-i yang telah dimasukkan pengguna sebelumnya.


###### Output
![Screenshot 2024-04-29 133445](https://github.com/sudolmunib/tugas-praktikum-5-Struct/assets/162574378/1efae444-5f62-44d7-9b04-0f837ead5f57)

## Kesimpulan 

Struct dalam bahasa pemrograman C++ adalah fitur yang memungkinkan pembuatan tipe data baru dengan menggabungkan beberapa jenis data, termasuk tipe data primitif seperti int dan float, serta tipe data lainnya seperti string. Fungsi utama dari struct adalah untuk mengelompokkan data terkait menjadi satu kesatuan, mempermudah pengelolaan dan manipulasi data dalam program.


## Daftar Pustaka 

[1] Tim Asisten Praktikum. 2010. Modul 1 Struct, Array, Pointer. Malang: Unversitas 
Negeri Malang.

[2] Ariffaiuddin, Samsul dan Budijono. 2018. “Rancang Bangun Prototype Alat Untuk Meningkatkan
Energi Listrik Alternatif Menggunakan Flywheel Generator”. Universitas Negeri Surabaya