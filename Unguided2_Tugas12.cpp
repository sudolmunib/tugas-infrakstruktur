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