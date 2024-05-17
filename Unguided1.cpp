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