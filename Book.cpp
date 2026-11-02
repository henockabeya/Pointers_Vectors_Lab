//
// Created by Henoc Kabeya on 10/30/26.
//

#include "Book.h"
#include <iostream>
using namespace std;

/**
 * @brief Parameterized constructor assigning specified field values.
 * @details Initializes title, author, and price using a member initializer list.
 * @param t Title of the book.
 * @param a Author of the book.
 * @param p Retail price of the book.
 */
Book::Book(string t, string a, double p): title(t), author(a), price(p){}

/**
 * @brief Displays the book's details to standard output.
 * @details Outputs the formatted title, author, and price to std::cout on a single line.
 */
void Book::displayInfo() const {
    cout << "Title: " << title << "| Author: " << author << "| Price: $" << price << endl;
}
