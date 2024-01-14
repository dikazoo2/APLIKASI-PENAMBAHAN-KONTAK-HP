#include <iostream>
#include <vector>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phoneNumber;
};

bool compareContacts(const Contact& contact1, const Contact& contact2) {
    return contact1.name < contact2.name;
}

int main() {
    std::vector<Contact> contacts;

    // Menambahkan beberapa kontak untuk percobaan
    contacts.push_back({"John Doe", "123-456-7890"});
    contacts.push_back({"Jane Smith", "987-654-3210"});
    contacts.push_back({"Bob Johnson", "555-123-4567"});

    // Mengurutkan daftar kontak berdasarkan nama
    std::sort(contacts.begin(), contacts.end(), compareContacts);

    // Menampilkan daftar kontak yang sudah diurutkan
    std::cout << "Daftar Kontak:\n";
    for (const auto& contact : contacts) {
        std::cout << contact.name << ": " << contact.phoneNumber << "\n";
    }

    // Menambahkan kontak baru
    Contact newContact;
    std::cout << "\nTambahkan Kontak Baru:\n";
    std::cout << "Nama: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Nomor Telepon: ";
    std::getline(std::cin, newContact.phoneNumber);

    contacts.push_back(newContact);

    // Mengurutkan ulang daftar kontak setelah penambahan kontak baru
    std::sort(contacts.begin(), contacts.end(), compareContacts);

    // Menampilkan daftar kontak yang sudah diurutkan setelah penambahan
    std::cout << "\nDaftar Kontak Setelah Penambahan:\n";
    for (const auto& contact : contacts) {
        std::cout << contact.name << ": " << contact.phoneNumber << "\n";
    }

    return 0;
}