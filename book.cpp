/**
 * Title:   Lab 3 - Book class implementation: book.cpp
 * Purpose: ** Book file creates a class to create, copy, manipulate, and display book objects book objects using various formats such as string and JSON  **
 * Course:  CSC 2430 Spring 2022
 * Author:  ** Shadman Shahzahan**
 *
 */

#include "book.h"

#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::stringstream;
using std::setprecision;
using std::fixed;
using std::stod;
using std::stoi;
using std::getline;


// TODO Book Constructor
Book::Book(const string &name, unsigned int year, double price)
    : _name(name), _year(year), _price(price) {} // Constructs a new book object with the given name, publication year, and price.

// TODO Book Copy Constructor
Book::Book(const Book &book)
        : _name(book._name), _year(book._year), _price(book._price){} // Copy contructor for Book objects

// TODO Book::ToString method
string Book::ToString() const {
    // // Returns a string representation of the book in the format (name, year, price)
    stringstream ss;
    ss << "(" << _name << ", " << _year << ", " << fixed << setprecision(2) << _price << ")";
    return ss.str();
}

// TODO Book::ToJSON method
string Book::ToJSON() const {
    // Returns a JSON representation of the book in the format {"name":"<name>", "year":<year>, "price":<price>}.
    stringstream ss;
    ss << "{\"name\":\"" << _name << "\", \"year\":" << _year << ", \"price\":" << fixed << setprecision(2) << _price << "}";

    return ss.str();
}

// TODO Book::GetPrice method
double Book::GetPrice() const {
    // Returns the price of the book
    return _price;
}

// TODO Book::SetPrice method
void Book::SetPrice(double price) {
    // Sets the price of the book to the specified value
    _price = price;
}

// TODO Book::Equals method
bool Book::Equals(const Book &rhs) const {
    // Checks if this book is equal to another book (based on name)
    return _name == rhs._name;
}

// TODO Book::Read method
istream &Book::Read(istream &input) {
    // Reads a line from the input stream in the format name,year,price and sets the book's properties accordingly
    string line;
    getline (input, line);

    stringstream ss(line);
    string name;
    unsigned int year;
    double price;

    getline(ss, name, ',');
    ss >> year;
    ss.ignore();
    ss >> price;

    _name = name;
    _year = year;
    _price = price;

    return input;
}
// TODO Book::Write method
ostream &Book::Write(ostream &output)const {
    // Writes the book's properties to the output stream in the format name,year,price
    output << _name << "," << _year << "," << fixed << setprecision(2) << _price;
    return output;
}

string Book:: GetName () const {
    // Returns the name of the book
    return _name;
}