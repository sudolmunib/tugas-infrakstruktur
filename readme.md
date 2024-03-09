# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Abdul Munib</p>
<p align="center">2311110004</p>

## Dasar Teori
tipe data adalah sebuah komponen dari potongan data yang memberikan sinyal pada komputer terkait cara mengartikan data tersebut. Hasil tafsir dari tipe data tersebut akan memastikan bahwa proses pengumpulan datanya menggunakan format serta nilai yang sesuai dengan keinginan.

Singkatnya, tipe data digunakan untuk menentukan nilai suatu objek yang terdapat dalam sebuah sistem pemrograman. Atau lebih spesifik tipe data ini merupakan tempat penyimpanan dari sebuah data yang dapat berisi nilai atau tipe tertentu.

Secara umum, jenis tipe data itu dibedakan menjadi dua, yakni tipe data sederhana, tipe data composite dan tipe data lainya. Untuk lebih jelas, berikut penjelasanya:
- data primitif                                                
Merupakan tipe data yang mampu menyimpan suatu nilai dari setiap variable. Tipe ini merupakan dasar yang sering dipakai oleh programmer. Contohnya adalah tipe numeric (integer dan real), tipe data karakter/char, dan tipe data Boolean.

- data composite                                               
data composite Yaitu tipe data yang dapat menampung banyak nilai seperti Array yang merupakan tipe data yang sudah terstruktur dengan baik dan sederhana. Array ini dapat menyimpan beberapa data yang samadan satu variable, misalnya integer saja. 

## Guided

### 1. [Tipe Data primitif]

```C++
#include <iostream>
using namespace std;
// Main program
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
    cout << num1 + num2;
    break;
    // If user enter -
    case '-':
    cout << num1 - num2;
    break;
    // If user enter *
    case '*':
    cout << num1 * num2;
    break;
    // If user enter /
    case '/':
    cout << num1 / num2;
    break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
    cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```
### 2. [Tipe data abstrak]

```C++
#include <stdio.h>
//Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
### 3.[Tipe data koleksi]

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}

```
#### Output:
![Soal1](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/d36281ed-d155-44a3-b6e1-08b57f0e4885)

Kode di atas digunakan untuk menghitung luas persegi panjang dan volume balok berdasarkan input yang dimasukan dan hasil yang dimasukkan akan menghitung dengan ketentuan panjang * lebar * tinggi.

#### Full code Screenshot:
![Soal2](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/6e6b0609-4095-42e6-81d7-aae6744eb845)


Kode tersebut adalah kode yang menggunakan struktur (struct) untuk menyimpan informasi mahasiswa dan kemudian mencetak informasi tersebut ke layar. 

#### Full code Screenshot:
![Soal3](https://github.com/sudolmunib/tugas-praktikum-munib/assets/162574378/1912c079-a026-4fbe-8dd1-9646df13b072)

Program di atas adalah sebuah contoh sederhana dalam bahasa C++ yang menggunakan struktur data std::map. std::map adalah struktur data yang memetakan kunci (key) ke nilai (value) yang terkait. Program ini mengilustrasikan cara membuat, mengakses, mengubah, dan mencetak nilai-nilai dalam std::map.

## Kesimpulan
Kode tersebut mencakup dua konsep yang berbeda dalam penggunaan struktur data: pertama, menggunakan struktur (struct) untuk menyimpan informasi mahasiswa, dan kedua, menggunakan struktur data std::map untuk menyimpan pasangan kunci-nilai (key-value pair).

Penggunaan struktur untuk mahasiswa memberikan cara yang terstruktur untuk menyimpan dan mengakses informasi individu, seperti nama, alamat, dan umur. Ini memungkinkan program untuk mengorganisir data dengan baik dan memudahkan dalam mengelola informasi mahasiswa.

Sementara itu, penggunaan std::map memberikan cara yang efisien untuk menyimpan dan mengelola data dalam bentuk pasangan kunci-nilai. Dengan std::map, program dapat mengaitkan nilai-nilai dengan kunci tertentu, sehingga memungkinkan untuk melakukan operasi pencarian dan pembaruan data dengan cepat dan efisien.

Kombinasi dari kedua konsep ini mengilustrasikan bagaimana struktur data yang tepat dapat digunakan untuk menyimpan informasi dengan cara yang terstruktur dan efisien dalam bahasa pemrograman C++. Dengan menggunakan struktur dan std::map, program dapat mengelola data dengan baik dan melakukan operasi yang diperlukan dengan efisien.

## Referensi
[1] https://www.jurnalponsel.com/pengertian-tipe-data/