# Book Inventory System (RAII & Destructors)

**Author:** Henoc Kabeya
**Date:** October 26, 2026
**Course:** CS 272

---

## 📌 Overview

This project is a simple C++ console program that manages a collection of books using **RAII (Resource Acquisition Is Initialization)**.

Instead of manually deleting every book when the program ends, the `Inventory` class takes full ownership of all dynamic memory. When the inventory object goes out of scope, its **destructor (`~Inventory()`)** automatically cleans up all dynamically allocated memory to prevent memory leaks.

---

## 💡 What is RAII?

**RAII** is a fundamental C++ concept where the lifetime of a resource (like dynamic memory allocated with `new`) is tied to the lifetime of an object:
1. **Acquisition:** We dynamically allocate a new `Book` object using `new` and store its memory address in the `Inventory`.
2. **Release:** When the `Inventory` object is destroyed (for example, when `main()` finishes), its destructor automatically loops through all stored pointers and frees them using `delete`.

---

## 🏗️ System Structure

The system consists of two main classes:

### 1. `Book` Class
Stores basic information about an individual book:
* **Title** (`std::string`)
* **Author** (`std::string`)
* **Price** (`double`)
* **Method:** `displayInfo()` prints the book details to the console.

### 2. `Inventory` Class
Manages the lifetime and collection of dynamically allocated books:
* **Private Storage:** `std::vector<Book*> books` holds pointers to heap-allocated books.
* **`addBook(Book* bookPtr)`:** Adds a dynamic `Book` pointer to the vector.
* **`displayAll()`:** Displays details for every book in the inventory.
* **`removeBook(int index)`:** Deallocates memory for a specific book using `delete` and removes it from the vector.
* **`~Inventory()` (Destructor):** Automatically loops through all pointers in `books` and deletes them when the inventory object goes out of scope.

---

## 📂 File Breakdown

| File Name | Description |
| :--- | :--- |
| `Book.h` | Header file containing the `Book` class declaration. |
| `Book.cpp` | Source file containing implementations for `Book` constructor and display method. |
| `Inventory.h` | Header file declaring the `Inventory` class and destructor signature. |
| `Inventory.cpp` | Source file implementing inventory operations and RAII destructor cleanup logic. |
| `main.cpp` | Interactive menu-driven console application. |

---
