//Telefonski_imenik.js
const contacts = [];

        function addContact() {
            const name = document.getElementById("name").value;
            const phone = document.getElementById("phone").value;

            if (name && phone) {
                contacts.push({ name, phone });
                displayContacts();
                clearInputs();
            } else {
                alert("Unesite ime i prezime te telefonski broj.");
            }
        }

        function displayContacts() {
            const contactList = document.getElementById("contactList");
            contactList.innerHTML = "";

            for (const contact of contacts) {
                const row = document.createElement("tr");
                row.innerHTML = `
                    <td>${contact.name}</td>
                    <td>${contact.phone}</td>
                    <td><button onclick="deleteContact(${contacts.indexOf(contact)})">Izbriši</button></td>
                `;
                contactList.appendChild(row);
            }
        }

        function deleteContact(index) {
            contacts.splice(index, 1);
            displayContacts();
        }

        function clearInputs() {
            document.getElementById("name").value = "";
            document.getElementById("phone").value = "";
        }

        displayContacts();
