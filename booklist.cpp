/**
 * Title:   Lab 3 - BookList class implementation: booklist.cpp
 * Purpose: ** Book List class manages list of 'Book' objects, providing methods to add, remove, find, and manipulate books, as well as to convert the book list to string and JSON formats **
 * Course:  CSC 2430 Spring 2022
 * Author:  ** Shadman Shahzahan**
 *
 */
#include "booklist.h"

#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::istream;
using std::ostream;
using std::endl;

// TODO BookList default constructor
BookList::BookList() : _size(0) {} // Constructor for BookList, initializes size to 0

// TODO BookList destructor
BookList::~BookList() {
    for (size_t i = 0; i < _size; ++i){ // Destructor for BookList, deallocates memory for all books
        delete _books[i];
    }
}
// TODO BookList::AddBook(book) method
bool BookList::AddBook(const Book &book) { // Method to add a book to the list (copy constructor)
    if (_size >= MAX_BOOKS){
        return false; // Array is full
    }
    _books[_size++] = new Book(book); // Create a copy of the book and add it to the array
    return true;

}

// TODO BookList::AddBook(name, year, price) method
bool BookList::AddBook(const string &name, unsigned int year, double price) { // Method to add a book to the list (parameterized constructor)
    if(_size >= MAX_BOOKS){
        return false; // Array is full
    }
    _books[_size++] = new Book(name, year, price); // Create a new book and add it to the array
    return true;
}

// TODO BookList::RemoveBook method
Book *BookList::RemoveBook(size_t position) { // Method to remove a book from the list
    if (position >= _size){
        return nullptr; // Invalid position
    }
    Book *removedBook = _books[position]; // Get a pointer to the book to be removed
    for (size_t i = position; i < _size - 1; ++i){
        _books[i] = _books[i+1]; // Shift elements to fill the gap
    }
    _size --; // Update the size of the array
    return removedBook;
}

// TODO BookList::FindBook method
const Book *BookList::FindBook(const string &name) const { // Method to find a book by name
    for (size_t i = 0; i < _size; ++i){
        if (_books[i]->GetName() == name ) {
            return _books[i]; // Return a pointer to the book if found
        }
    }
    return nullptr;

}

// TODO BookList::GetBook method
const Book *BookList::GetBook(size_t position) const { // Method to get a book at a specific position in the list
    if(position >= _size){
        return nullptr; // Invalid position
    }
    return _books[position]; // Return a pointer to the book at the specified position

}

// TODO BookList::BookCount method
size_t BookList::BookCount() const { // Method to get the number of books in the list
    return _size; // Return the number of books in the array
}

// TODO BookList::Read method
size_t BookList::Read(istream &input) { // Method to read books from an input stream
    size_t count = 0;
    string line;
    while (getline(input, line)){
        stringstream ss(line);
        string name;
        unsigned int year;
        double price;
        getline(ss, name, ',');
        ss >> year;
        ss.ignore();
        ss >> price;
        if (AddBook(name, year, price)){
            count++;
        }

    }
    return count;
}

// TODO BookList::Write method
size_t BookList::Write(ostream &output) const { // Method to write books to an output stream
    for (size_t i = 0; i < _size; ++i){
         _books[i]->Write(output); // Calls write fuction from book.cpp
         output << endl;
    }
    return _size; // Return the number of books written
}

// TODO BookList::ToString method
string BookList::ToString() const { // Method to convert the book list to a string
    stringstream ss;
    ss << _size << ": (";
    for (size_t i = 0; i < _size; ++i){
        ss << _books[i]->ToString();
        if (i < _size - 1 ){
            ss << ", ";
        }
    }
    ss << ")";
    return ss.str();
}

// TODO BookList::ToJSON method
string BookList::ToJSON() const { // Method to convert the book list to JSON format
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < _size; ++i) {
        ss << _books[i]->ToJSON();
        if (i < _size - 1) {
            ss << ", ";
        }
    }
    ss << "}";
    return ss.str();
}
