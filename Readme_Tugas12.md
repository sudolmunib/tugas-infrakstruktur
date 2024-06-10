# <h1 align="center">Laporan Praktikum 12 Graph dan Tree </h1>

<p align="center">Nama: Abdul Munib</p>
<p align="center">NIM: 2311110004</p>
<p align="center">Kelas: SISD-04A</p>

Dasar Teori
#### GRAPH

Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge).

- G = (V, E)
- Dimana :
- G = Graph
- V = Simpul atau Vertex, atau Node, atau Titik
- E = Busur atau Edge, atau arc

Graf merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan dengan bantuan graf. Seringkali graf digunakan untuk merepresentasikan suaru jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut.

Ada beberapa cara untuk menyimpan graph di dalam sitem komputer. Struktur data bergantung pada struktur graph dan algoritma yang digunakan untuk memanipulasi graph. Secara teori salah satu dari keduanya dapat dibedakan antara struktur list dan matriks, tetapi dalam penggunaannya struktur terbaik yang sering digunakan adalah kombinasi keduanya.

a.    Graph tak berarah (undirected graph atau non-directed graph) :
-          Urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1 dapat disebut busur AB atau BA
b.    Graph berarah (directed graph) :
-          Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.


c.    Graph Berbobot (Weighted Graph)
-          Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot.
-          Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll.

2). Istilah – Istilah Dalam Graph

Terdapat istilah – istilah yang berkaitan dengan graph, yaitu :
- a.    Vertex

Vertex adalah himpunan node/titik pada sebuah graph.
- b.    Edge

Edge adalah garis yang menghubungkan tiap node/vertex.
- c.    Adjacent

Adjacent adalah dua buah titik dikatakan berdekatan juka dua buah titik tersebut terhubung dengan sebuah sisi.

- d.    Weight

Sebuah graph dikatakan berbobot apabila terdapat sebuah fungsi bobot bernilai real pada himpunan Edge.

- e.    Path

Path adalah walk dengan setiap vertex berbeda. Walk didefinisikan sebagai ururtan vertex dan edge. Diawali dengan origin vertex dan diakhiri dengan terminus vertex.

- f.     Cycle
Cycle adalah siklus atau sirkuit yang berawal dan berakhir pada simpul yang sama.

3). Representasi Graph

Dalam pemrograman, agar data yang ada dalam graph dapat diolah, maka graph harus dinyatakan dalam suatu struktur data yang dapat mewakili graph tersebut. Dalam hal ini graph perlu direpresentasikan kedalam bentuk array dan dimensi yang sering disebut matrix atau direpresentasikan dalam bentuk linked list. Bentuk mana yang dipilih biasanya tergantung kepada efisiensi dan kemudahan dalam membuat program. Berikut ini beberapa bentuk representasi graph :

3.1). Representasi dalam bentuk matrix

a.    Adjacency Matrix Graph tak berarah

Matrik yang digambarkan pada gambar 1b merupakan representasi dalam bentuk Adjacency Matrik dari graf yang digambarkan pada gambar 1a. Beberapa hal yang dapat dilihat atau dapat diterangkan pada Adjacency Matrik tersebut adalah sebagai berikut :
1.      Matrik yang terbentuk adalah matrik bujur sangkar n x n, dimana n = jumlah simpul yang ada dalam graf tersebut. Matrik ini menyatakan hubungan antara simpul satu dengan simpul lainnya.
2.      Matrik yang terbentuk adalah matrik simetris dengan sumbu simetris adalah diagonal dari titik kiri atas ke titik kanan bawah.
3.      Data yang tedapat baik dalam baris maupun kolom, dapat menyatakan degree sebuah simpul. Contoh : baik pada baris D maupun kolom D jumlah angka 1 nya adalah 3 buah, dimana jumlah ini menyatakan degree simpul D.
b.    Adjacency Matrix Graf Berarah

Matrik yang digambarkan pada gambar 2b merupakan representasi dalam bentuk Adjacency Matrik dari graf yang digambarkan pada gambar 2a. Beberapa hal yang dapat dilihat atau dapat diterangkan pada Adjacency Matrik tersebut adalah sebagai berikut :
1.      Matrik yang terbentuk adalah matrik bujur sangkar n x n, dimana n = jumlah simpul yang ada dalam graf tersebut. Matrik ini menyatakan hubungan antara simpul satu dengan simpul lainnya.
2.      Matrik yang terbentuk mungkin simetris mungkin juga tidak simetris. Menjadi Simetris bila hubungan antara dua buah simpul (v1 dan v2) terdapat busur dari v1 ke v2 dan juga sebaliknya.
3.      Hal pokok yang dinyatakan oleh matrik ini adalah : busur yang ’keluar’ dari suatu simpul. Dengan demikian, data yang terdapat dalam suatu baris, dapat menyatakan outdegree simpul yang bersangkutan.
Contoh : Jumlah elemen yang nilainya = 1 pada baris B ada 3 elemen,ini menyatakan jumlah outdegree simpul B adalah 3 buah.
4.      Data yang terdapat dalam suatu kolom, dapat menyatakan indegree simpul bersangkutan.
Contoh : Jumlah elemen yang nilainya 1 pada kolom B ada 2 elemen, ini menyatakan indegree simpul B adalah 2 buah.

c.     Adjacency Matrix Graph berbobot tak Berarah
Nilai yang ada dalam tiap elemen matrik, menyatakan bobot busur yang menghubungkan dua buah simpul yang bersangkutan. Untuk dua buah simpul yang tidak berhubungan langsung oleh sebuah busur, maka dianggap dihubungkan oleh sebuah busur yang nilai bobotnya tidak terhingga. Dalam pemograman, karena keperluan algoritma, maka dari total bobot seluruh busur yang ada atau yang mungkin ada.

Contoh: pada gambar 3a simpul A dan C tidak berhubungan langsung melalui sebuah busur, maka untuk elemen matrik yang bersangkutan diisi dengan nilai 999 karena nilai 999 dalam kasus ini cukup mewakili nilai tidak terhingga.

 graph adalah cara mewakili hubungan yang ada di antara pasangan objek.Graph adalah seperangkat objek, yang disebut simpul (vertex), bersama dengankumpulan koneksi berpasangan di antara mereka, yang disebut edge (edge).Graphmemiliki aplikasi dalam pemodelan banyak domain, termasuk pemetaan, transportasi, jaringan komputer, dan teknik listrik.Graph G adalah kumpulan V dari simpul dankumpulan E dari pasangan simpul dari V, yang disebut edge. Dengan demikian,graph adalah cara untuk mewakili koneksi atau hubungan antara pasangan objek dari beberapa set V.Secara kebetulan, beberapa buku menggunakan terminologi berbeda untuk graph dan merujuk pada apa yang kita sebut vertex sebagai node dan yang kita sebut edge sebagai arc.


Guided 1

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[5] = {
    "jambi", "medan", "pekanbaru", "padang", "palembang"
};

int busur[5][5] = {
    {0, 7, 8, 0, 0},
    {0, 0, 5, 0, 15},
    {0, 6, 0, 0, 5},
    {0, 5, 0, 0, 2},
    {23, 0, 0, 10, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 5; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 5; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ") ";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Output
Screenshot 2024-06-04 062827

Interpretasi
Program ini bertujuan untuk menampilkan informasi graf berbobot yang merepresentasikan hubungan antar kota dan bobot (jarak) dari setiap hubungan tersebut. Graf diimplementasikan menggunakan array untuk menyimpan nama kota (simpul) dan matriks dua dimensi untuk menyimpan bobot antara setiap pasangan kota (busur). 

Berikut adalah penjelasan lebih rinci tentang bagaimana program ini bekerja:

Deklarasi dan Inisialisasi Variabel:

Program mendefinisikan array simpul yang berisi nama-nama kota.

Program juga mendefinisikan matriks dua dimensi busur yang menyimpan bobot antara setiap pasangan kota. 

Matriks ini diinisialisasi dengan nilai-nilai yang menunjukkan jarak antara kota-kota tertentu. Jika tidak ada jarak yang ditentukan antara dua kota, maka nilai yang disimpan adalah 0.

Fungsi tampilGraph:

Fungsi tampilGraph digunakan untuk menampilkan graf dalam format yang mudah dibaca. Fungsi ini menggunakan loop bersarang untuk iterasi melalui setiap simpul dan setiap busur yang terhubung.

Nama kota (simpul) dicetak diikuti oleh kota-kota tujuan yang terhubung beserta bobotnya.

##### Cara Kerja Program
Program menginisialisasi array simpul dengan lima nama kota: "jambi", "medan", "pekanbaru", "padang", dan "palembang".

Matriks busur diinisialisasi dengan bobot yang merepresentasikan jarak antara kota-kota tertentu. Sebagai contoh, busur[0][1] bernilai 7 menunjukkan bahwa jarak dari "jambi" ke "medan" adalah 7 satuan.

Fungsi tampilGraph iterasi melalui setiap baris dan kolom matriks busur. Jika ditemukan nilai yang bukan 0, fungsi ini akan mencetak nama kota tujuan dan bobotnya.

Guided 2 Program Tree
Kode Program
#include <iostream>
using namespace std;

```cpp
#include <iostream> // Tambahkan ini
#include <cstddef>  // Tambahkan ini untuk NULL

using namespace std; // Tambahkan ini

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL; // Gunakan NULL
        right = NULL; // Gunakan NULL
    }
};

void preOrder(TNode *node) {
    if (node != NULL) { // Gunakan NULL
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) { // Gunakan NULL
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) { // Gunakan NULL
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine->left = eight;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5
    // /
    // 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```
Output
Screenshot 2024-06-04 062855

Interpretasi
Program ini bekerja dengan mendefinisikan dan mengimplementasikan sebuah struktur data tree biner. Struktur data ini diwakili oleh kelas TNode, yang berisi atribut data untuk menyimpan nilai integer dari node, serta dua pointer left dan right untuk menunjuk ke anak kiri dan anak kanan dari node tersebut. Kelas ini juga memiliki konstruktor yang menginisialisasi nilai data dan mengatur pointer left dan right ke NULL.

Dalam fungsi main, program pertama-tama membuat beberapa node dengan nilai 0, 1, 5, 7, 8, dan 9. Node-node ini kemudian dihubungkan untuk membentuk sebuah tree biner dengan struktur tertentu. Node seven dijadikan root dari tree, dengan one sebagai anak kiri dan nine sebagai anak kanan. Anak kiri dari one adalah zero dan anak kanannya adalah five. Anak kiri dari nine adalah eight. Struktur tree yang terbentuk adalah sebagai berikut:

    7
   / \
  1   9
 / \  /
0   5 8
Setelah tree terbentuk, program melakukan tiga jenis traversal: preorder, inorder, dan postorder. Fungsi preOrder mengunjungi node saat ini terlebih dahulu, kemudian anak kiri, dan terakhir anak kanan. Fungsi inOrder mengunjungi anak kiri terlebih dahulu, kemudian node saat ini, dan terakhir anak kanan. Fungsi postOrder mengunjungi anak kiri terlebih dahulu, kemudian anak kanan, dan terakhir node saat ini. Masing-masing fungsi traversal ini menggunakan rekursi untuk mengunjungi setiap node dalam tree.

Hasil dari masing-masing traversal dicetak ke layar. Traversal preorder mengunjungi node dalam urutan 7 1 0 5 9 8, traversal inorder menghasilkan urutan 0 1 5 7 8 9, dan traversal postorder menghasilkan urutan 0 5 1 8 9 7. Traversal dilakukan dengan mengunjungi node sesuai urutan yang ditentukan oleh metode traversal, mencetak nilai node, dan menggunakan rekursi untuk melanjutkan ke anak kiri dan anak kanan hingga seluruh node dalam tree telah dikunjungi.

Tugas Praktikum
Cantumkan NIM pada salah satu variabel didalam program.

Unguided 1
Soal

Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
Kode Program

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    // NIM
    int MUNIB_2311110004; // Variabel untuk menyimpan NIM
    
    // Meminta pengguna untuk memasukkan jumlah simpul (kota)
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
            string from, to;
            cout << nodes[i] << "--> " << nodes[j] << " = ";
            cin >> edges[{nodes[i], nodes[j]}];
        }
    }

    // Output Program
    // Menampilkan nama simpul (kota) di atas matriks
    cout << "\nOutput Program:\n";
    cout << "\t";
    for (int i = 0; i < num_nodes; i++) {
        cout << nodes[i] << "\t";
    }
    cout << endl;

    // Menampilkan matriks jarak antar simpul (jarak antar kota)
    for (int i = 0; i < num_nodes; i++) {
        cout << nodes[i] << "\t"; // Menampilkan nama simpul (kota) di samping matriks
        for (int j = 0; j < num_nodes; j++) {
            cout << edges[{nodes[i], nodes[j]}] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```
Output
Screenshot 2024-06-04 063014

Interpretasi
Program tersebut terdiri dari beberapa fungsi yang saling berinteraksi untuk memungkinkan pengguna memasukkan informasi tentang kota-kota dan jarak antara mereka. Pertama, program meminta pengguna untuk memasukkan jumlah kota yang ingin dimasukkan. Setelah itu, pengguna diminta untuk memasukkan nama kota satu per satu. Setelah nama kota dimasukkan, program meminta pengguna untuk memasukkan jarak antara setiap pasang kota.

Program menggunakan struktur data vektor untuk menyimpan nama kota dan map untuk menyimpan jarak antara kota-kota. Setelah selesai memasukkan data, program mencetak output yang menampilkan matriks dua dimensi. Nama kota-kota ditampilkan di atas matriks sebagai judul kolom dan di samping matriks sebagai judul baris. Di dalam matriks, setiap elemen mewakili jarak antara pasangan kota yang sesuai.

Output program adalah matriks dua dimensi yang menampilkan jarak antara setiap pasangan kota. Struktur matriks ini memungkinkan pengguna untuk dengan mudah melihat dan memahami hubungan jarak antara kota-kota yang telah dimasukkan.

Di atas matriks, terdapat judul kolom yang merupakan nama-nama kota yang dimasukkan oleh pengguna. Setiap nama kota menjadi judul kolom yang terletak di atas kolom matriks yang sesuai dengan kota tersebut.
Di samping matriks, terdapat judul baris yang juga merupakan nama-nama kota yang dimasukkan oleh pengguna. Setiap nama kota menjadi judul baris yang terletak di samping baris matriks yang sesuai dengan kota tersebut.
Di dalam matriks, setiap elemen mewakili jarak antara pasangan kota yang sesuai. Elemen di baris i dan kolom j menunjukkan jarak antara kota i dan kota j.
Unguided 2
Soal

Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
Kode Program

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Struktur Node Tree
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Class untuk merepresentasikan Tree
class Tree {
private:
    TreeNode *root;

public:
    // Constructor
    Tree() {
        root = NULL;
    }

    // Fungsi untuk menambahkan node ke dalam Tree
    void insert(int value) {
        TreeNode *newNode = new TreeNode(value);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Fungsi untuk menampilkan child nodes dari suatu node
    void displayChildNodes(int value) {
        TreeNode *current = root;
        queue<TreeNode *> q;
        bool found = false;

        // Traversal level-order untuk mencari node yang diberikan
        q.push(current);
        while (!q.empty() && !found) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->data == value) {
                current = temp;
                found = true;
            } else {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        // Menampilkan child nodes jika node ditemukan
        if (found) {
            cout << "Child nodes dari " << value << ": ";
            if (current->left)
                cout << current->left->data << " ";
            if (current->right)
                cout << current->right->data << " ";
            cout << endl;
        } else {
            cout << "Node tidak ditemukan!" << endl;
        }
    }

    // Fungsi untuk menampilkan descendant nodes dari suatu node
    void displayDescendantNodes(int value) {
        TreeNode *current = root;
        queue<TreeNode *> q;
        bool found = false;

        // Traversal level-order untuk mencari node yang diberikan
        q.push(current);
        while (!q.empty() && !found) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->data == value) {
                current = temp;
                found = true;
            } else {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        // Menampilkan descendant nodes jika node ditemukan
        if (found) {
            cout << "Descendant nodes dari " << value << ": ";
            queue<TreeNode *> q_desc;
            q_desc.push(current);
            while (!q_desc.empty()) {
                TreeNode *temp = q_desc.front();
                q_desc.pop();
                cout << temp->data << " ";
                if (temp->left)
                    q_desc.push(temp->left);
                if (temp->right)
                    q_desc.push(temp->right);
            }
            cout << endl;
        } else {
            cout << "Node tidak ditemukan!" << endl;
        }
    }

    // Fungsi untuk menampilkan node-node secara inorder
    void inorder(TreeNode *node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Fungsi untuk menampilkan node-node secara postorder
    void postorder(TreeNode *node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Fungsi untuk menampilkan node-node secara preorder
    void preorder(TreeNode *node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Fungsi untuk menampilkan seluruh tree secara inorder
    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Fungsi untuk menampilkan seluruh tree secara postorder
    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    // Fungsi untuk menampilkan seluruh tree secara preorder
    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree;

    // Input data tree dari user
    int num_nodes;
    cout << "Masukkan jumlah node pada tree: ";
    cin >> num_nodes;
    cout << "Masukkan nilai-nilai dari node-node tersebut:" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        int value;
        cin >> value;
        tree.insert(value);
    }

    // Menampilkan child nodes dan descendant nodes dari node yang diinputkan oleh user
    int target;
    cout << "Masukkan node untuk menampilkan child dan descendant nodes-nya: ";
    cin >> target;
    tree.displayChildNodes(target);
    tree.displayDescendantNodes(target);

    // Menampilkan inorder, postorder, dan preorder traversal dari tree
    tree.displayPreorder();
    tree.displayInorder();
    tree.displayPostorder();

    return 0;
}
```
Output
Screenshot 2024-06-04 063107

Interpretasi
Setiap node dalam tree direpresentasikan oleh struktur TreeNode, yang memiliki tiga atribut: data, left, dan right, yang mewakili nilai data dari node, pointer ke node anak kiri, dan pointer ke node anak kanan secara berturut-turut.

Kelas Tree bertanggung jawab atas pengelolaan keseluruhan struktur tree. Ketika objek Tree dibuat, root dari tree diinisialisasi sebagai NULL. Fungsi insert digunakan untuk menambahkan node baru ke dalam tree dengan menggunakan pendekatan level-order traversal menggunakan queue.

Program ini juga menyediakan fungsi displayChildNodes dan displayDescendantNodes untuk menampilkan child nodes dan descendant nodes dari suatu node yang ditentukan oleh pengguna. Kedua fungsi ini menggunakan pendekatan level-order traversal untuk menemukan node yang dimaksud, lalu menampilkan informasi yang relevan.

Selain itu, program ini memiliki fungsi inorder, postorder, dan preorder untuk melakukan traversal tree secara inorder, postorder, dan preorder. Masing-masing fungsi ini menggunakan pendekatan rekursif untuk mengunjungi setiap node dalam tree dan menampilkan nilainya sesuai dengan urutan traversal yang diinginkan.

Dalam fungsi main, pengguna diminta untuk memasukkan jumlah node pada tree dan nilai-nilai dari setiap node. Kemudian, pengguna diminta untuk memasukkan node untuk menampilkan child dan descendant nodes-nya. Setelah itu, program menampilkan informasi yang diminta oleh pengguna, termasuk child nodes, descendant nodes, serta hasil dari traversal tree secara inorder, postorder, dan preorder.

Output program adalah dua jenis penampilan dari tree yang dibuat oleh pengguna, yaitu child nodes dan descendant nodes, serta traversal dari tree tersebut.

Child Nodes dan Descendant Nodes:

Child nodes dari suatu node ditampilkan sebagai nilai-nilai node yang langsung terhubung ke node tersebut. Jika node tidak memiliki child nodes, pesan "Node tidak memiliki child nodes" akan ditampilkan.
Descendant nodes dari suatu node adalah semua node yang berada di bawahnya dalam tree, termasuk child nodes, child nodes dari child nodes, dan seterusnya. Informasi ini memberikan gambaran yang lebih lengkap tentang struktur hierarki dari node yang dipilih.
Traversal Tree:

Preorder traversal menampilkan urutan kunjungan dari akar ke kiri kemudian ke kanan, yaitu mulai dari node itu sendiri, kemudian node kiri, dan akhirnya node kanan.
Inorder traversal menampilkan urutan kunjungan node dari kiri ke kanan, yaitu mulai dari node kiri, kemudian node itu sendiri, dan akhirnya node kanan.
Postorder traversal menampilkan urutan kunjungan dari kiri ke kanan kemudian ke akar, yaitu mulai dari node kiri, kemudian node kanan, dan akhirnya node itu sendiri.
Kesimpulan
Berikut adalah kesimpulan mengenai materi graph dan juga tree:

Graph dan tree adalah dua jenis struktur data non-linear yang esensial dalam ilmu komputer dan pemrograman. Graph terdiri dari simpul (vertex) dan sisi (edge) yang menghubungkan simpul-simpul tersebut, dan digunakan untuk merepresentasikan objek-objek diskrit serta hubungan antar mereka. Ada beberapa jenis graf, termasuk directed graph (graf berarah), undirected graph (graf tak berarah), weighted graph (graf berberat), dan unweighted graph (graf tak berberat), yang masing-masing memiliki aplikasi spesifik seperti jaringan sosial, aliran data, dan optimasi jaringan. Tree, di sisi lain, adalah struktur hierarki yang terdiri dari node yang dihubungkan dalam bentuk seperti pohon, dengan satu node khusus disebut root dan yang lainnya child. Jenis-jenis tree termasuk binary tree, binary search tree (BST), balanced tree (AVL Tree dan Red-Black Tree), full binary tree, complete binary tree, perfect binary tree, general tree, N-ary tree, trie, dan segment tree. Tree sering digunakan dalam pengembangan game, pengindeksan database, analisis keputusan, dan pemetaan domain. Keduanya, graph dan tree, adalah alat penting yang digunakan untuk memecahkan berbagai masalah komputasi dengan cara yang efisien dan terstruktur.

Daftar Pustaka
[1] Y. Jason, "Parsing kode sumber Ecmascript2015 ke dalam Abstract Syntax Tree dan Control Flow Graph," Undergraduate thesis, 2020.

[2] J. Zhang, L. Wang, R. K.-W. Lee, Y. Bin, Y. Wang, J. Shao, and E.-P. Lim, "Graph-to-Tree Learning for Solving Math Word Problems," in Proceedings of the 58th Annual Meeting of the Association for Computational Linguistics, pp. 3928-3937, 2020.

[3] Quinn, R., Advanced C++ Programming Cookbook. United Kingdoms: Packt Publishing Ltd., 2020.

[4] Sedgewick, R., Algorithms in C++ Part 5: Graph Algorithms 3rd Edition. Boston: Addison-Wesley Professional, 2020.

[5] L. Benny and C. V. Monti, "Aplikasi Permainan Mandarin Scrabble bagi Pemula dengan Algoritma Directed Acyclic Word Graph," Riset dan E-Jurnal Manajemen Informatika Komputer, vol. 6, no. 1, pp. 48, 2021.

[6] H. Lubis and D. B. Srisulistiowati, "Algoritma Prim dan Kruskal dalam Mencari Minimum Spanning Tree pada Bahasa Pemrograman C," JSI: Jurnal Sistem Informasi, vol. 8, no. 2, 2021.

[7] R. A. M. Makalew, C. E. J. C. Montolalu, and M. L. Mananohas, "Lintasan Hamiltonian pada Graf 4-Connected," d'CartesiaN Jurnal Matematika dan Aplikasi, pp. 181-188, 2020.

[8] Zheng Li dkk, C++ Programming. Republic State of China: De Gruyter, 2019.