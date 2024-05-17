# <h1 align="center">Laporan Praktikum 9 PRIORITY QUEUE DAN HEAPS</h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

Dasar Teori

Priority queue adalah jenis antrean di mana setiap elemen memiliki kunci yang terkait dengannya dan antrean mengembalikan elemen sesuai dengan kunci tersebut, tidak seperti antrean tradisional yang bekerja berdasarkan siapa cepat dia dapat.


Jadi, priority queue  maksimal mengembalikan elemen dengan kunci maksimum terlebih dahulu sedangkan priority queue  min mengembalikan elemen dengan kunci terkecil terlebih dahulu seperti contoh pada gambar dibawah ini:

![Screenshot 2024-05-17 134041](https://github.com/sudolmunib/tugas-praktikum-9-PRIORITY-QUEUE-DAN-HEAPS/assets/162574378/9526cc6f-1966-473d-afe3-7ece3a01aeba)

priority queue digunakan dalam banyak algoritma seperti Kode Huffman, algoritma Prim, dll. Antrian ini juga digunakan dalam proses penjadwalan untuk komputer, dll.

Heap sangat bagus untuk mengimplementasikan priority queue karena elemen terbesar dan terkecil ada di akar pohon untuk max-heap dan min-heap. Kami menggunakan max-heap untuk antrean prioritas maksimal dan min-heap untuk antrean prioritas minimum.

Ada 4 operasi yang dari 

priority queue:

1. Insert → Untuk menyisipkan elemen baru ke dalam antrian.

2. Maksimum/Minimum → Untuk mendapatkan elemen maksimum dan minimum dari antrian prioritas maks dan antrian prioritas minimum.

3. Ekstrak Maksimum/Minimum → Untuk menghapus dan mengembalikan elemen maksimum dan minimum dari antrian prioritas maks dan antrian prioritas minimum.

4. Increse/Decrease key → Untuk menambah atau mengurangi kunci elemen apa pun dalam antrian.

priority queue menyimpan datanya dalam urutan tertentu sesuai dengan kunci elemen. Jadi, memasukkan data baru harus dilakukan pada tempat sesuai urutan yang ditentukan. Inilah yang dilakukan operasi penyisipan.

Inti dari priority queue adalah untuk mendapatkan data sesuai dengan kunci data dan Maksimum/Minimum dan Ekstrak Maksimum/Minimum melakukan ini untuk kita.


Dengan operasi ini, kami telah memenuhi sebagian besar permintaan priority queue kami, yaitu memasukkan data ke dalam antrian dan mengambil data dari antrian. Tapi kita mungkin juga menghadapi situasi di mana kita perlu mengubah kunci suatu elemen, jadi kunci Kenaikan/Penurunan digunakan untuk melakukan itu.

Kode Pseudo yang diberikan di bawah ini adalah untuk antrian prioritas maksimal. Namun, kode lengkap dalam C, Java, dan Python diberikan untuk antrian prioritas maksimal dan prioritas minimum di akhir artikel ini.

Seperti yang dinyatakan sebelumnya, kita akan menggunakan heap untuk antrian prioritas.

Maksimum/Minimum
Kita tahu bahwa elemen maksimum (atau minimum) dari antrian prioritas berada di akar max-heap (atau min-heap). Jadi, kita hanya perlu mengembalikan elemen di akar heap seperti contoh berikut :
![Screenshot 2024-05-17 135859](https://github.com/sudolmunib/tugas-praktikum-9-PRIORITY-QUEUE-DAN-HEAPS/assets/162574378/f696ed7d-2212-4bcb-a1b6-7d081275f00c)

#### Guided 1
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);

    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);

    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
```
Output
![Screenshot 2024-05-17 140415](https://github.com/sudolmunib/tugas-praktikum-9-PRIORITY-QUEUE-DAN-HEAPS/assets/162574378/0c4e8618-dc53-4845-82f6-c668e2118c93)

Interpretasi:

Program yang disajikan mengimplementasikan priority queue menggunakan struktur data max-heap dalam bahasa C++. Heap diimplementasikan dengan menggunakan array H yang mampu menampung hingga 50 elemen, dan heapSize yang melacak ukuran heap saat ini.

Beberapa fungsi dasar disediakan untuk mengakses dan memodifikasi heap, seperti parent(int i), leftChild(int i), dan rightChild(int i).

Fungsi shiftUp(int i) dan shiftDown(int i) digunakan untuk mempertahankan properti max-heap setelah penambahan atau penghapusan elemen dengan menggeser elemen ke atas atau ke bawah hingga elemen tersebut berada di posisi yang benar. shiftUp akan menukar elemen dengan parent-nya jika elemen tersebut lebih besar dari parent-nya hingga berada di posisi yang benar. Sedangkan shiftDown akan menukar elemen dengan child yang lebih besar jika elemen tersebut lebih kecil dari salah satu child-nya.

Operasi utama heap termasuk:

> insert(int p) untuk menambahkan elemen baru p ke dalam heap. Elemen baru ditempatkan di akhir array, lalu dipindahkan ke posisi yang benar menggunakan shiftUp.

> extractMax() untuk menghapus dan mengembalikan elemen dengan prioritas tertinggi. Elemen root diganti dengan elemen terakhir di heap, lalu dipindahkan ke posisi yang benar menggunakan shiftDown.

>changePriority(int i, int p) untuk mengubah prioritas elemen pada indeks i menjadi p. Jika prioritas baru lebih tinggi, elemen dipindahkan ke atas dengan shiftUp; jika lebih rendah, dipindahkan ke bawah dengan shiftDown.

>getMax() untuk mendapatkan elemen dengan prioritas tertinggi tanpa menghapusnya.

>remove(int i) untuk menghapus elemen pada indeks i dari heap dengan menaikkan elemen ke root menggunakan shiftUp dan kemudian menghapusnya dengan extractMax.

Dalam fungsi main, beberapa elemen dimasukkan ke dalam heap, dan berbagai operasi dilakukan untuk mendemonstrasikan fungsionalitas heap:

Output Output:

Setelah memasukkan elemen-elemen 45, 20, 14, 12, 31, 7, 11, 13, dan 7 ke dalam heap menggunakan fungsi insert, heap yang terbentuk adalah [45, 31, 14, 13, 20, 7, 11, 12, 7].
Heap ini diatur sedemikian rupa sehingga setiap parent lebih besar dari child-nya, mempertahankan properti max-heap.

elemen maksimum (45) dihapus, elemen terakhir (7) dipindahkan ke posisi root. Untuk mempertahankan properti max-heap, shiftDown dilakukan untuk menempatkan elemen tersebut di posisi yang sesuai.

Priority queue after extracting maximum: 31 20 14 13 7 7 11 12

Elemen pada indeks ke-3 (nilai 13) dihapus menggunakan fungsi remove. Prosesnya melibatkan peningkatan nilai elemen tersebut agar lebih besar dari nilai maksimum (49), lalu elemen dipindahkan ke root menggunakan shiftUp, dan akhirnya dihapus menggunakan extractMax. Setelah itu, properti max-heap dipertahankan dengan melakukan shiftDown.

Priority queue after removing the element: 49 20 31 12 7 7 11

Tugas Praktikum
[1]
Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user!

#### Unguided 1

```C++
#include <iostream>
#include <algorithm>

int H[50]; 
int heapSize = -1; 

// Fungsi int parent untuk mengembalikan indeks parent dari suatu indeks i
int parent(int i) {
    return (i - 1) / 2;
}

// Fungsi int leftchild untuk mengembalikan indeks child kiri dari suatu indeks i
int leftChild(int i) { 
    return ((2 * i) + 1);
}

// Fungsi rightchild untuk mengembalikan indeks child kanan dari suatu indeks i
int rightChild(int i) {
    return ((2 * i) + 2);
}

// Fungsi shiftup untuk melakukan operasi shift-up (mengubah posisi elemen ke atas)
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// Fungsi shiftDown untuk melakukan operasi shift-down (mengubah posisi elemen ke bawah)
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Fungsi Insert untuk menambahkan elemen baru ke dalam heap
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// Fungsi extractMax untuk mengeluarkan elemen dengan prioritas tertinggi dari heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// Fungsi ChangePriority untuk mengubah prioritas suatu elemen dalam heap
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// Fungsi getMax untuk mendapatkan elemen dengan prioritas tertinggi tanpa menghapusnya dari heap
int getMax() {
    return H[0];
}

// Fungsi remove untuk menghapus suatu elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    // Meminta pengguna untuk menginputkan jumlah elemen yang ingin dimasukkan ke dalam heap
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    // Meminta pengguna untuk menginputkan nilai-nilai elemen
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        insert(element);
    }

    // Menampilkan isi heap setelah diisi dengan elemen-elemen dari pengguna
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    // Mengeluarkan elemen dengan prioritas tertinggi dari heap
    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    // Fungsi ini untuk Menampilkan isi heap setelah mengeluarkan elemen dengan prioritas tertinggi
    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    // changepriority untuk Mengubah prioritas suatu elemen dalam heap
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    // fungsi remove untuk Menghapus suatu elemen dari heap
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Output
![Screenshot 2024-05-17 153057](https://github.com/sudolmunib/tugas-praktikum-9-PRIORITY-QUEUE-DAN-HEAPS/assets/162574378/4401de36-8187-4bc4-a980-8027898277ca)

Interpretasi
Setelah memasukkan semua elemen, heap terbentuk dengan elemen-elemen berikut:

Priority Queue : 24 22 18 16 21 15 16 8 10 9 14 5 11 12 12

Ini menunjukkan bahwa elemen dengan nilai tertinggi (24) berada di posisi pertama, diikuti oleh elemen-elemen lainnya yang diatur sedemikian rupa sehingga memenuhi properti heap maksimal.

Node with Maximum Priority:
Elemen dengan nilai tertinggi dihapus dari heap, yaitu 24.

Node with maximum priority : 24
Ini menunjukkan bahwa elemen 24 dihapus dari heap.

Setelah menghapus elemen tertinggi, heap tersisa dengan elemen-elemen berikut:

Priority queue after extracting maximum: 22 21 18 16 14 15 16 8 10 9 12 5 11 12

Struktur heap telah diubah sedemikian rupa agar tetap memenuhi sifat heap maksimal setelah penghapusan.

Priority Queue after Priority Change:
Tidak ada perubahan dalam struktur heap setelah operasi perubahan prioritas, karena nilai baru (49) tetap berada di bawah nilai tertinggi saat itu (24).

Priority queue after priority change : 49 21 22 16 14 15 16 8 10 9 12 5 11 12

Output menunjukkan bahwa struktur heap tidak berubah setelah perubahan prioritas.

Setelah menghapus elemen pada posisi ke-3, heap tersisa dengan elemen-elemen berikut:

Priority queue after removing the element : 49 21 22 12 14 15 16 8 10 9 12 5 11

Struktur heap telah diubah sedemikian rupa agar tetap memenuhi sifat heap maksimal setelah penghapusan elemen pada posisi ke-3.

Kesimpulan:
Hasil hasil tersebut menunjukkan penggunaan struktur data priority queue dan implementasinya menggunakan heap. Priority queue digunakan untuk mengatur elemen berdasarkan prioritas, sedangkan heap digunakan sebagai struktur data yang efisien untuk mewakili priority queue.

Heap adalah struktur data yang efisien untuk mewakili priority queue. Heap sering kali diimplementasikan sebagai pohon biner lengkap yang memenuhi properti heap, yaitu properti di mana setiap simpul (node) memiliki nilai lebih besar daripada nilai-nilai anak-anaknya.

Dengan menggunakan struktur data priority queue dan implementasinya yang efisien menggunakan heap, kita dapat mengoptimalkan berbagai algoritma dan solusi masalah yang melibatkan pengurutan dan pemrosesan data berdasarkan prioritas.

Daftar Pustaka
[1] Goodrich, Tamassia, Mount. Data Structure
and Algorithms in C++, Wiley, 2004

[2] Munir, Rinaldi. Diktat Kuliah IF2251 Strategi
Algoritmik, 2005.

[3] Schildt, Herbert, The Complete Reference
Java, Mc.Graw Hill, 2005. 

[4] Sedgewick, Robert. Algorithms in C, 1990.

