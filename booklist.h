/**
 * Title:   Lab 3 - BookList class declaration: booklist.h
 * Purpose: declares the class BookList that will hold an array
 * of pointers to Book.
 * Course:  CSC 2430 Spring 2022
 * Author:  Carlos R. Arias
 *
 * **********************************************************************
 * You can ADD to the class, but you cannot change or remove anything  **
 * that is already here.                                               **
 * **********************************************************************
 */
#ifndef BOOK_ARRAYLIST_BOOKLIST_H
#define BOOK_ARRAYLIST_BOOKLIST_H

#include "book.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

const int MAX_BOOKS = 10;

class BookList {
private:
    Book* _books[MAX_BOOKS];
    size_t _size;
public:
    BookList();
    ~BookList();
    bool AddBook(const Book& book);
    bool AddBook(const string& name, unsigned int year, double price);
    Book* RemoveBook(size_t position);
    const Book* FindBook(const string& name)const;
    const Book* GetBook(size_t position)const;
    size_t BookCount()const;
    size_t Read(istream& input);
    size_t Write(ostream& output)const;
    string ToString()const;
    string ToJSON()const;
};


#endif
