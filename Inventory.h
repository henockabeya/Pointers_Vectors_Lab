//
// Created by Henoc Kabeya on 10/30/26.
//

#ifndef POINTERS_INVENTORY_H
#define POINTERS_INVENTORY_H

#include <vector>
using namespace std;

#include "Book.h"

/**
 * @class Inventory
 * @brief Manages a collection of dynamically allocated Book objects using RAII.
 */

class Inventory {
    private:
    vector <Book *> books; /**< Container of pointers to dynamically allocated Book instances. */
    public:

    /**
     * @brief Adds a dynamically allocated Book pointer to the inventory.
     * @param bookPtr Pointer to the heap-allocated Book instance.
     */

    void addBook(Book *bookPtr);

    /**
     * @brief Displays details of all books currently managed in the inventory.
     */

    void displayAll() const;

    /**
     * @brief Deallocates dynamic memory and removes the book at the specified index.
     * @param index Zero-based index of the book to remove.
     */

    void removeBook(int index);

    /**
     * @brief Destructor that deallocates all dynamic Book pointers managed by the inventory.
     * @details Implements core RAII cleanup by looping through `books` and calling `delete`
     *          on every element before destroying the Inventory object.
     */

    ~Inventory();

};

#endif //POINTERS_INVENTORY_H
