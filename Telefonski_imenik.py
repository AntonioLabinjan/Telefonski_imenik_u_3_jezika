class Contact:
    def __init__(self, name, phone_number):
        self.name = name
        self.phone_number = phone_number

contacts = []

def add_contact():
    name = input("Unesite ime i prezime: ")
    phone_number = int(input("Unesite telefonski broj: "))
    new_contact = Contact(name, phone_number)
    contacts.append(new_contact)
    print("Kontakt dodan.")

def edit_contact():
    index = int(input("Unesite indeks kontakta za izmjenu: "))
    if 0 <= index < len(contacts):
        new_name = input("Unesite novo ime i prezime: ")
        new_phone_number = int(input("Unesite novi telefonski broj: "))
        contacts[index].name = new_name
        contacts[index].phone_number = new_phone_number
        print("Kontakt izmijenjen.")
    else:
        print("Indeks nije valjan.")

def delete_contact():
    index = int(input("Unesite indeks kontakta za brisanje: "))
    if 0 <= index < len(contacts):
        del contacts[index]
        print("Kontakt obrisan.")
    else:
        print("Indeks nije valjan.")

def list_contacts():
    if not contacts:
        print("Telefonski imenik je prazan.")
        return
    print("Popis kontakata:")
    for i, contact in enumerate(contacts):
        print(f"[{i}] Ime: {contact.name}, Broj: {contact.phone_number}")

def main():
    while True:
        print("Odaberite opciju:")
        print("1. Dodaj kontakt")
        print("2. Izmijeni kontakt")
        print("3. Obriši kontakt")
        print("4. Pregled svih kontakata")
        print("5. Izlaz")
        choice = int(input("Vaš odabir: "))

        if choice == 1:
            add_contact()
        elif choice == 2:
            edit_contact()
        elif choice == 3:
            delete_contact()
        elif choice == 4:
            list_contacts()
        elif choice == 5:
            print("Hvala na korištenju!")
            break
        else:
            print("Neispravan odabir. Pokušajte ponovno.")

if __name__ == "__main__":
    main()
