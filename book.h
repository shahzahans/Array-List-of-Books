/**
 * Title:   Lab 3 - Book class declaration: book.h
 * Purpose: declares the class Book that represents a book
 * Course:  CSC 2430 Spring 2022
 * Author:  Carlos R. Arias
 *
 * **********************************************************************
 * You can ADD to the class, but you cannot change or remove anything  **
 * that is already here.                                               **
 * **********************************************************************
 */

#ifndef BOOK_ARRAYLIST_BOOK_H
#define BOOK_ARRAYLIST_BOOK_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Book {
private:
    string _name;
    unsigned int _year;
    double _price;
public:
    Book(const string& name, unsigned int year, double price);
    Book(const Book& book);
    string ToString()const;
    string ToJSON()const;
    double GetPrice()const;
    void SetPrice(double price);
    bool Equals(const Book& rhs)const;
    istream& Read(istream& input);
    ostream& Write(ostream& output)const;
    string GetName () const;
};


#endif
