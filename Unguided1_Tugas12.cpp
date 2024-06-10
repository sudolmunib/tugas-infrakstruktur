#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int MUNIB_2311110004; // Variabel untuk menyimpan NIM (meskipun tidak digunakan dalam kode ini)

    int num_nodes;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> num_nodes;

    // Vector untuk menyimpan nama simpul (kota)
    vector<string> nodes(num_nodes);

    // Map untuk menyimpan bobot antar simpul (jarak antar kota)
    map<pair<string, string>, int> edges;

    // Meminta pengguna untuk memasukkan nama simpul (kota)
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Meminta pengguna untuk memasukkan bobot antar simpul (jarak antar kota)
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            cout << nodes[i] << "--> " << nodes[j] << " = ";
            int weight;
            cin >> weight;
            edges[make_pair(nodes[i], nodes[j])] = weight;
        }
    }

    // Output Program
    cout << "\nOutput Program:\n";
    cout << "\t";
    for (int i = 0; i < num_nodes; i++) {
        cout << nodes[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < num_nodes; i++) {
        cout << nodes[i] << "\t";
        for (int j = 0; j < num_nodes; j++) {
            cout << edges[make_pair(nodes[i], nodes[j])] << "\t";
        }
        cout << endl;
    }

    return 0;
}
