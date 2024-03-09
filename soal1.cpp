#include <iostream>

// Fungsi untuk menghitung luas persegi panjang
double hitungLuasPersegiPanjang(double panjang, double lebar) {
    return panjang * lebar;
}

// Fungsi untuk menghitung volume balok
double hitungVolumeBalok(double panjang, double lebar, double tinggi) {
    return panjang * lebar * tinggi;
}

int main() {
    double panjang, lebar, tinggi;

    // Input dari pengguna
    std::cout << "Masukkan panjang persegi panjang: ";
    std::cin >> panjang;
    std::cout << "Masukkan lebar persegi panjang: ";
    std::cin >> lebar;
    std::cout << "Masukkan tinggi balok: ";
    std::cin >> tinggi;

    // Hitung dan tampilkan luas persegi panjang
    double luas = hitungLuasPersegiPanjang(panjang, lebar);
    std::cout << "Luas persegi panjang: " << luas << std::endl;

    // Hitung dan tampilkan volume balok
    double volume = hitungVolumeBalok(panjang, lebar, tinggi);
    std::cout << "Volume balok: " << volume << std::endl;

return 0;
}