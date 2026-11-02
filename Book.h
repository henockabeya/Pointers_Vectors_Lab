//
// Created by Henoc Kabeya on 10/30/26.
//

#ifndef POINTERS_BOOK_H
#define POINTERS_BOOK_H
#include <string>

using namespace std;

/**
 * Creation of the class Book to represent an individual book item within the inventory system.
 */
class Book {
private:
    string title; // title of the book
    string author; // Name of Book's author
    double price; // Price of the book

public:
    /**
    * @brief Parameterized constructor initializing a Book instance.
    * @param t Title of the book.
    * @param a Author of the book.
    * @param p Retail price of the book.
    */
    Book(string t, string a, double p); //

    /**
     * @brief Displays the book's details to standard output.
     * @details Prints title, author, and price formatted as a single log line.
     */
    void displayInfo() const;

};
#endif //POINTERS_BOOK_H
