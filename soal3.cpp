#include <iostream>
#include <map>

int main() {
    // Membuat map untuk menyimpan data
    std::map<int, int> data;

    // Menambahkan data ke map
    data[1] = 10;
    data[2] = 20;
    data[3] = 30;
    data[4] = 40;
    data[5] = 50;

    // Mengakses dan mencetak nilai dalam map
    std::cout << "Nilai data dengan kunci 3: " << data[3] << std::endl;

    // Mengubah nilai dalam map
    data[3] = 35;

    // Mencetak semua nilai dalam map
    std::cout << "Nilai dalam map: ";
    for (std::map<int, int>::iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
}
