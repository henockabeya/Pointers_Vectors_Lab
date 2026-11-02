//
// Created by Henoc Kabeya on 10/30/26.
//

#include "Inventory.h"
#include <iostream>
using namespace std;

// Destructor: Cleans up ALL dynamically allocated Book objects (RAII)
Inventory::~Inventory() {
    for (Book* bookPtr : books) {
        delete bookPtr; // Free heap memory for each book
    }
    books.clear(); // Clear the vector of pointers
}

// Add a new dynamically allocated book pointer
void Inventory::addBook(Book* bookPtr) {
    books.push_back(bookPtr);
}

// Display all books in the inventory
void Inventory::displayAll() const {
    if (books.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }

    cout << "\n=== Book Inventory ===" << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". ";
        books[i]->displayInfo(); // Use arrow operator (->) for pointers!
    }
}

// Remove a book at a specific index
void Inventory::removeBook(int index) {
    if (index >= 0 && index < static_cast<int>(books.size())) {
        delete books[index]; // 1. Free memory of the pointed-to object
        books.erase(books.begin() + index); // 2. Remove pointer from vector
        cout << "Book removed successfully!" << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}