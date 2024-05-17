Laporan Praktikum Modul 9 Priority Queue dan Heaps
Nama: Ika Wida Nuragustin

NIM: 231111000

Kelas: SISD-04A

Dasar Teori
Priority Queue adalah struktur data yang menerapkan prinsip operasi FIFO (First In First Out) dimana elemen data yang masuk pertama akan keluar pertama. Namun, dalam Priority Queue, elemen-elemen yang dimasukkan memiliki prioritas yang berbeda, sehingga elemen dengan prioritas tertinggi akan diproses terlebih dahulu [1]. Implementasi Priority Queue dapat dilakukan menggunakan algoritma heap, yang memungkinkan elemen dengan prioritas tertinggi untuk dihapus terlebih dahulu.

Heaps adalah struktur data yang digunakan untuk implementasi Priority Queue. Heaps adalah tipe data yang memungkinkan elemen-elemen untuk disimpan dan diurutkan berdasarkan prioritas. Heaps dapat digunakan untuk menampung elemen-elemen yang memiliki prioritas yang berbeda dan memungkinkan elemen dengan prioritas tertinggi untuk dihapus terlebih dahulu [2].

Dalam implementasi Priority Queue menggunakan Heaps, elemen-elemen yang dimasukkan diurutkan berdasarkan prioritas, dan elemen dengan prioritas tertinggi akan diproses terlebih dahulu. Heaps memungkinkan operasi penyisipan elemen baru dan penghapusan elemen yang memiliki prioritas tertinggi, sehingga memungkinkan implementasi Priority Queue yang efisien dan efektif.

Dalam sintesis, dasar teori Priority Queue dan Heaps adalah tentang implementasi struktur data yang memungkinkan elemen-elemen untuk disimpan dan diurutkan berdasarkan prioritas, serta memungkinkan elemen dengan prioritas tertinggi untuk dihapus terlebih dahulu [3]. Implementasi Priority Queue menggunakan Heaps memungkinkan efisiensi dan efektifitas dalam penggunaan Priority Queue, terutama dalam aplikasi yang memerlukan proses elemen dengan prioritas tertinggi terlebih dahulu.

Priority Queue adalah struktur data yang menyimpan elemen dengan setiap elemen memiliki prioritas yang terkait. Operasi utama pada priority queue meliputi:

Insert: Menambahkan elemen dengan prioritas tertentu.
Find-Min/Find-Max: Mengambil elemen dengan prioritas tertinggi atau terendah tanpa menghapusnya.
Extract-Min/Extract-Max: Menghapus dan mengembalikan elemen dengan prioritas tertinggi atau terendah.
Decrease-Key/Increase-Key: Mengubah prioritas dari elemen yang ada.
Priority queue banyak digunakan dalam algoritma graf seperti Dijkstra untuk menemukan jalur terpendek dan Prim untuk menemukan minimum spanning tree [4].

Heaps
Heap adalah struktur data berbasis pohon yang memiliki properti heap. Ada dua jenis heap utama:

Min-Heap: Setiap node memiliki nilai yang lebih kecil atau sama dengan nilai anak-anaknya, dengan elemen terkecil di root.
Max-Heap: Setiap node memiliki nilai yang lebih besar atau sama dengan nilai anak-anaknya, dengan elemen terbesar di root.
Heap umumnya diimplementasikan sebagai pohon biner lengkap yang disimpan dalam array untuk efisiensi. Indeks dalam array membantu menentukan posisi anak-anak dan orang tua dengan rumus sederhana [4].

Implementasi Priority Queue Menggunakan Heaps
Priority queue sering diimplementasikan menggunakan heap karena operasi pada heap sangat efisien:

Insert:
Extract-Min/Extract-Max:
Peek/Find-Min/Find-Max:
Operasi Dasar pada Binary Heap
Insert: Menambahkan elemen di akhir heap dan "bubble up" untuk memulihkan properti heap.
Extract-Min/Extract-Max: Menghapus root dan menggantinya dengan elemen terakhir, kemudian "bubble down" untuk memulihkan properti heap.
Heapify: Mengubah array menjadi heap dalam waktu linear
dengan cara "bubble down" dari elemen terakhir yang bukan daun hingga ke root [5].
Aplikasi Priority Queue dan Heaps
Algoritma Penjadwalan: Mengatur urutan eksekusi proses di sistem operasi.
Algoritma Graf: Dijkstra dan Prim menggunakan priority queue untuk efisiensi.
Simulasi Acara: Mengelola kejadian dalam simulasi berbasis waktu di mana kejadian diproses sesuai urutan waktu.
Langkah Praktikum
Guided 1
Kode Program
// Guided 1
```C++
#include <iostream>
#include <algorithm>

int H[50]; 
int heapSize = -1; 

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) { 
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
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

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Output
Screenshot 2024-05-14 061308

Interpretasi
Penjelasan Kode Program:

Program yang disajikan mengimplementasikan priority queue menggunakan struktur data max-heap dalam bahasa C++. Heap diimplementasikan dengan menggunakan array H yang mampu menampung hingga 50 elemen, dan heapSize yang melacak ukuran heap saat ini.

Beberapa fungsi dasar disediakan untuk mengakses dan memodifikasi heap, seperti parent(int i), leftChild(int i), dan rightChild(int i), yang mengembalikan indeks orang tua, anak kiri, dan anak kanan dari elemen pada indeks i. Fungsi shiftUp(int i) dan shiftDown(int i) digunakan untuk mempertahankan properti max-heap setelah penambahan atau penghapusan elemen dengan menggeser elemen ke atas atau ke bawah hingga elemen tersebut berada di posisi yang benar.

Operasi utama heap termasuk insert(int p) untuk menambahkan elemen baru p ke dalam heap, extractMax() untuk menghapus dan mengembalikan elemen dengan prioritas tertinggi, changePriority(int i, int p) untuk mengubah prioritas elemen pada indeks i menjadi p, getMax() untuk mendapatkan elemen dengan prioritas tertinggi tanpa menghapusnya, dan remove(int i) untuk menghapus elemen pada indeks i dari heap.

Dalam fungsi main, beberapa elemen dimasukkan ke dalam heap, dan berbagai operasi dilakukan untuk mendemonstrasikan fungsionalitas heap. Setelah memasukkan elemen, program menampilkan elemen-elemen heap yang tersusun sesuai dengan properti max-heap. Program kemudian menghapus elemen dengan prioritas tertinggi (root heap), mengubah prioritas salah satu elemen, dan menghapus elemen lain, menampilkan kondisi heap setelah setiap operasi.

Penjelasan Output:

Priority Queue : 45 31 14 20 12 7 11 13 7:

Elemen-elemen dimasukkan dan disusun sehingga memenuhi properti max-heap.
Node with maximum priority : 45:

Elemen dengan prioritas tertinggi (root heap) adalah 45, yang kemudian dihapus.
Priority queue after extracting maximum: 31 20 14 13 12 7 11 7:

Setelah menghapus elemen 45, elemen-elemen disusun ulang sehingga heap tetap valid.
Priority queue after priority change : 49 31 14 13 20 7 11 7 12:

Prioritas elemen di indeks 2 diubah menjadi 49, menyebabkan elemen tersebut digeser ke atas untuk memenuhi properti heap.
Priority queue after removing the element : 49 31 14 12 20 7 11 7:

Elemen di indeks 3 dihapus, heap disusun ulang sehingga tetap valid.
Tugas Praktikum
1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user!
JAWAB:

Kode Program
// 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user!
```C++
#include <iostream>
#include <algorithm>

int H[50]; 
int heapSize = -1; 

// Fungsi untuk mengembalikan indeks parent dari suatu indeks i
int parent(int i) {
    return (i - 1) / 2;
}

// Fungsi untuk mengembalikan indeks child kiri dari suatu indeks i
int leftChild(int i) { 
    return ((2 * i) + 1);
}

// Fungsi untuk mengembalikan indeks child kanan dari suatu indeks i
int rightChild(int i) {
    return ((2 * i) + 2);
}

// Fungsi untuk melakukan operasi shift-up (mengubah posisi elemen ke atas)
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// Fungsi untuk melakukan operasi shift-down (mengubah posisi elemen ke bawah)
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

// Fungsi untuk menambahkan elemen baru ke dalam heap
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

// Fungsi untuk mengeluarkan elemen dengan prioritas tertinggi dari heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

// Fungsi untuk mengubah prioritas suatu elemen dalam heap
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

// Fungsi untuk mendapatkan elemen dengan prioritas tertinggi tanpa menghapusnya dari heap
int getMax() {
    return H[0];
}

// Fungsi untuk menghapus suatu elemen dari heap
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    // Meminta pengguna untuk memasukkan jumlah elemen yang ingin dimasukkan ke dalam heap
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    // Meminta pengguna untuk memasukkan nilai-nilai elemen
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

    // Menampilkan isi heap setelah mengeluarkan elemen dengan prioritas tertinggi
    std::cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    // Mengubah prioritas suatu elemen dalam heap
    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << " \n";

    // Menghapus suatu elemen dari heap
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Output
Screenshot 2024-05-14 061225

Interpretasi
Penjelasan Kode Program:

Program dimulai dengan inisialisasi variabel H yang digunakan untuk menyimpan elemen-elemen heap, serta variabel heapSize yang mengindikasikan jumlah elemen dalam heap. Kemudian, terdapat fungsi-fungsi dasar seperti parent, leftChild, dan rightChild untuk menentukan indeks parent, left child, dan right child dari suatu elemen dalam heap. Fungsi shiftUp dan shiftDown digunakan untuk mempertahankan properti heap setelah operasi penambahan dan penghapusan elemen. Operasi-operasi dasar pada heap seperti insert, extractMax, changePriority, dan remove diimplementasikan dengan fungsi-fungsi yang sesuai.

Fungsi utama main bertanggung jawab untuk mengatur interaksi dengan pengguna. Pengguna diminta untuk memasukkan jumlah elemen yang ingin dimasukkan ke dalam heap, dan kemudian diminta untuk memasukkan nilai-nilai elemen tersebut. Setelah heap terbentuk, isi heap ditampilkan. Program juga melakukan operasi ekstraksi elemen dengan prioritas tertinggi dari heap, pengubahan prioritas suatu elemen, dan penghapusan elemen dari heap, serta menampilkan hasil setiap operasi tersebut. Dengan demikian, program ini memberikan fleksibilitas kepada pengguna untuk mengelola heap sesuai kebutuhan dengan operasi-operasi dasar yang tersedia.

Penjelasan Output:

Berdasarkan dari output diatas diketahui bahwa pengguna meemilih untuk memasukkan 10 elements yaitu sebagai berikut: 13 45 27 33 25 11 7 3 55 31. Dari element-element yang dimasukkan tersebut, terbentuklah output untuk priority queue, Node with maximum priority, Priority queue after extracting maximum, Priority queue after priority change, dan Priority queue after removing the element sebagai berikut sesuai dengan program.

Berikut adalah penjelasan dari output-outputnya:

Priority Queue:

Setelah semua elemen dimasukkan, heap terbentuk dengan elemen-elemen berikut:
55 45 27 33 31 11 7 3 13 25
Ini menunjukkan bahwa elemen dengan nilai tertinggi (55) berada di posisi pertama, diikuti oleh elemen-elemen lainnya yang diatur sedemikian rupa sehingga memenuhi properti heap maksimal.
Node with maximum priority:

Elemen dengan nilai tertinggi dihapus dari heap, yang dalam kasus ini adalah 55.
Output menunjukkan:
Node with maximum priority : 55
Priority queue after extracting maximum:

Setelah penghapusan elemen tertinggi, heap tersisa dengan elemen-elemen berikut:
45 33 27 25 31 11 7 3 13
Struktur heap telah diubah sedemikian rupa agar tetap memenuhi sifat heap maksimal setelah penghapusan.
Priority queue after priority change:

Tidak ada perubahan dalam struktur heap setelah operasi perubahan prioritas, karena nilai baru (49) tetap berada di bawah nilai tertinggi saat itu (55).
Output menunjukkan bahwa struktur heap tidak berubah:
Priority queue after priority change : 55 45 27 33 31 11 7 3 13
Priority queue after removing the element:

Setelah menghapus elemen pada posisi ke-3, heap tersisa dengan elemen-elemen berikut:
55 45 27 33 13 11 7 3
Struktur heap telah diubah sedemikian rupa agar tetap memenuhi sifat heap maksimal setelah penghapusan elemen pada posisi ke-3.
Kesimpulan
Berikut adalah kesimpulan yang dapat diambil dari materi Priority Queue dan Heaps:

Priority Queue:

Priority queue adalah struktur data yang mengatur elemen-elemen berdasarkan prioritas mereka, di mana elemen dengan prioritas tertinggi dapat diakses dan dihapus terlebih dahulu.
Ini adalah struktur data yang penting dan sering digunakan dalam berbagai aplikasi, seperti algoritma greedy, penjadwalan, dan antrian yang mengutamakan pelayanan.
Dalam priority queue, elemen-elemen tidak disusun dalam urutan linear seperti dalam array atau daftar, tetapi dalam struktur yang lebih kompleks yang memungkinkan akses dan manipulasi cepat terhadap elemen dengan prioritas tertinggi.
Heaps:

Heap adalah struktur data yang efisien untuk mewakili priority queue.
Heap sering kali diimplementasikan sebagai pohon biner lengkap yang memenuhi properti heap, yaitu properti di mana setiap simpul (node) memiliki nilai lebih besar (atau lebih kecil, tergantung pada jenis heap) daripada nilai-nilai anak-anaknya.
Heap bisa menjadi maksimal (max heap), di mana elemen dengan nilai tertinggi berada di atas, atau minimal (min heap), di mana elemen dengan nilai terendah berada di atas.
Operasi-operasi seperti penyisipan (insertion), penghapusan (deletion), dan pembaruan prioritas (priority update) dapat dilakukan dengan cepat pada heap.
Heap dapat digunakan untuk menyelesaikan berbagai masalah seperti pencarian elemen dengan prioritas tertinggi, penjadwalan acara, dan algoritma Dijkstra.
Dengan menggunakan struktur data priority queue dan implementasinya yang efisien menggunakan heap, kita dapat mengoptimalkan berbagai algoritma dan solusi masalah yang melibatkan pengurutan dan pemrosesan data berdasarkan prioritas.

Daftar Pustaka
[1] A. Nurcholis, S. Batara, and M. Octamanullah, "Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n)", Jurnal Laboratorium Ilmu dan Rekayasa Komputasi, vol. 1, no. 1, pp. 1-4, 2023.

[2] T. A. Assegie and H. D. Bizuneh, "Improving network performance with an integrated priority queue and weighted fair queue scheduling", Indonesian Journal of Electrical Engineering and Computer Science , vol. 19, no. 1, pp. 241-247, July 2020.

[3] R. Setyawatu and A. B. Maulachela, "Penerapan Algoritma Dynamic Priority Scheduling Pada Aplikasi Antrian Pencucian Mobil Berbasis Mobile (Implementation of Dynamic Priority Scheduling Algorithm in Mobile Car Queue Washing Applications)", JTIM: Jurnal Teknologi Informasi dan Multimedia, vol. 2, no. 1, pp. 29-35, May 2020.

[4] J. Wise, J. Bader, C. Wong, J. Aldrich, É. Tanter, and J. Sunshine, "Gradual verification of recursive heap data structures", Proc. ACM Program. Lang. , vol. 4, no. 228, pp. 1-28, Oct. 2020.

[5] M. Lutfi and F. A. Setyaningsih, "Implementasi Metode K-Medoids dan Heap Sort dalam Pengelompokan Siswa Penerima Dana Bantuan Operasional Sekolah di SMA N 1 Pemangkat", Coding: Jurnal Komputer dan Aplikasi, vol. 11, no. 03, pp. 368-379, 2023.