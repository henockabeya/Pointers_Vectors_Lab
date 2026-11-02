/**
 * @brief Interactive console controller for the Book Inventory Management System using RAII.
 * @author Henoc Kabeya
 * @date October 31, 2026
 *
 * ====================================================================================
 * PURPOSE:
 * ------------------------------------------------------------------------------------
 * - Encapsulate individual book data (title, author, price) within a Book class.
 * - Manage dynamic allocations of Book objects on the heap using vector<Book*>.
 * - Implement RAII (Resource Acquisition Is Initialization) via ~Inventory() to ensure
 *   automatic, complete deallocation of dynamically allocated Book objects upon scope exit.
 * - Provide an interactive, menu-driven CLI for book creation, inventory display,
 *   and record removal.
 * ====================================================================================
 */

#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"

using namespace std;

int main() {
    Inventory store; // Single Inventory object on the stack
    int choice = 0;

    do {
        cout << "\n===============================\n";
        cout << "     BOOK INVENTORY SYSTEM     \n";
        cout << "===============================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Remove Book\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                string title, author;
                double price;

                cout << "Enter title: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(std::cin, title);

                cout << "Enter author: ";
                getline(std::cin, author);

                cout << "Enter price: $";
                cin >> price;

                // Dynamically allocate new Book and store pointer in inventory
                store.addBook(new Book(title, author, price));
                cout << "Book added successfully!\n";
                break;
            }
            case 2:
                store.displayAll();
                break;

            case 3: {
                int index;
                cout << "Enter index to remove (1-based index): ";
                cin >> index;
                store.removeBook(index - 1); // Convert 1-based display index to 0-based vector index
                break;
            }
            case 4:
                cout << "Exiting program. Cleaning up memory...\n";
                break;

            default:
                cout << "Invalid choice. Please select 1-4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
    // When main ends, 'store' goes out of scope,
    // automatically invoking ~Inventory() to free all heap memory!
}