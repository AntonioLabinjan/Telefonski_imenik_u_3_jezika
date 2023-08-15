#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    int phoneNumber;
};

vector<Contact> contacts;

void addContact() {
    Contact newContact;
    cout << "Unesite ime i prezime: ";
    cin.ignore(); 
    getline(cin, newContact.name);
    cout << "Unesite telefonski broj: ";
    cin >> newContact.phoneNumber;
    contacts.push_back(newContact);
    cout << "Kontakt dodan." << endl;
}

void editContact() {
    int index;
    cout << "Unesite redni broj kontakta za izmjenu: ";
    cin >> index;
    if (index >= 0 && index < contacts.size()) {
        cout << "Unesite novo ime i prezime: ";
        cin.ignore(); 
        getline(cin, contacts[index].name);
        cout << "Unesite novi telefonski broj: ";
        cin >> contacts[index].phoneNumber;
        cout << "Kontakt izmijenjen." << endl;
    } else {
        cout << "Redni broj nije valjan." << endl;
    }
}

void deleteContact() {
    int index;
    cout << "Unesite redni broj kontakta za brisanje: ";
    cin >> index;
    if (index >= 0 && index < contacts.size()) {
        contacts.erase(contacts.begin() + index);
        cout << "Kontakt obrisan." << endl;
    } else {
        cout << "Redni broj nije valjan." << endl;
    }
}

void listContacts() {
    if (contacts.empty()) {
        cout << "Telefonski imenik je prazan." << endl;
        return;
    }
    cout << "Popis kontakata:" << endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "[" << i << "] Ime: " << contacts[i].name << ", Broj: " << contacts[i].phoneNumber << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Odaberite opciju:" << endl;
        cout << "1. Dodaj kontakt" << endl;
        cout << "2. Izmijeni kontakt" << endl;
        cout << "3. Obriši kontakt" << endl;
        cout << "4. Pregled svih kontakata" << endl;
        cout << "5. Izlaz" << endl;
        cout << "Vaš odabir: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                editContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                listContacts();
                break;
            case 5:
                cout << "Hvala na korištenju!" << endl;
                return 0;
            default:
                cout << "Neispravan odabir. Pokušajte ponovno." << endl;
        }
    }

    return 0;
}
