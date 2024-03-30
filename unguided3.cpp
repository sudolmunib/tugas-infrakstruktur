#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;
    char characters[n];
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }
    cout << "Urutan karakter sebelum sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    sort(characters, characters + n);
    cout << "Karakter setelah diurutkan secara ascending: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    sort(characters, characters + n, greater<char>());
    cout << "Karakter setelah diurutkan secara descending: ";
    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    
    return 0;
}
