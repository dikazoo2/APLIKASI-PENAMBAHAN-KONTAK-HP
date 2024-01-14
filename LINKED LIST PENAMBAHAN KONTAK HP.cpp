#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    string nomor;
    Node* next;
};


class PhoneBook {
private:
    Node* head;

public:

    PhoneBook() : head(NULL) {}


    ~PhoneBook() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void tambahKontak(string nama, string nomor) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nomor = nomor;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void tampilkanKontak() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Nama: " << temp->nama << ", Nomor: " << temp->nomor << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.tambahKontak("Edo", "123456789");
    phoneBook.tambahKontak("Sasuke", "987654321");
    phoneBook.tambahKontak("Naruto", "555555555");
    phoneBook.tambahKontak("Sinta", "777777777");

    phoneBook.tampilkanKontak();

    return 0;
}
