#include <iostream>
#include <string>

using namespace std;

// Node untuk BST
struct TreeNode {
    string name;
    string phoneNumber;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string n, string num) : name(n), phoneNumber(num), left(NULL), right(NULL) {}
};

// Kelas untuk BST
class PhoneBook {
private:
    TreeNode* root;

    // Fungsi rekursif untuk menambahkan nomor telepon ke dalam BST
    TreeNode* insert(TreeNode* node, string name, string phoneNumber) {
        if (node == NULL) {
            return new TreeNode(name, phoneNumber);
        }

        if (name < node->name) {
            node->left = insert(node->left, name, phoneNumber);
        } else if (name > node->name) {
            node->right = insert(node->right, name, phoneNumber);
        } else {
            // Jika nama sudah ada, update nomor telepon
            node->phoneNumber = phoneNumber;
        }

        return node;
    }

    // Fungsi rekursif untuk mencari nomor telepon berdasarkan nama
    string search(TreeNode* node, string name) {
        if (node == NULL) {
            return "Nomor telepon tidak ditemukan.";
        }

        if (name == node->name) {
            return "Nomor telepon untuk " + name + ": " + node->phoneNumber;
        } else if (name < node->name) {
            return search(node->left, name);
        } else {
            return search(node->right, name);
        }
    }

public:
    PhoneBook() : root(NULL) {}

    // Fungsi untuk menambahkan nomor telepon
    void addPhoneNumber(string name, string phoneNumber) {
        root = insert(root, name, phoneNumber);
    }

    // Fungsi untuk mencari nomor telepon berdasarkan nama
    string findPhoneNumber(string name) {
        return search(root, name);
    }
};

int main() {
    PhoneBook phoneBook;

    // Menambahkan beberapa nomor telepon ke dalam aplikasi
    phoneBook.addPhoneNumber("Barang", "123-456-7890");
    phoneBook.addPhoneNumber("Siapa", "987-654-3210");
    phoneBook.addPhoneNumber("Barang Gwe", "555-123-4567");

    // Mencari nomor telepon berdasarkan nama
    cout << phoneBook.findPhoneNumber("Barang") << endl;
    cout << phoneBook.findPhoneNumber("Siapa") << endl;
    cout << phoneBook.findPhoneNumber("Barang Gwe") << endl;
    cout << phoneBook.findPhoneNumber("Alice Minotaur") << endl;

    return 0;
}
