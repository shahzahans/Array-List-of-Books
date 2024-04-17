[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j3vppHnb)
# BUG BUG BUG
Need to rerun the solved code to update the correct output. ToJSON of BookList ends with } when it should end with ]
Need to update the corresponding test Line 151 on main.cpp


# Lab 3: A List of Books Using an Array

## Introduction
This lab will require you to code a simple list using an array. The elements of the array are going to be pointers to Book (`Book*`). This is because the class Book does not have a default constructor.

## Learning Goals

* Practice programming using multiple files
* Practice programming using dynamic memory
* Create a module for a list of Books using an array

## The Target
You are to develop two classes: `Book` and `BookList`. The class `Book` is a simple class that stores the name, year and price of a book. Class `BookList` represents a fixed size array of Books where you can insert, remove, retrieve, etc. books.

## What you are given
You are given the following files:
* `main.cpp` This file contains a menu based part and the tests for your classes. You are expected to write the `MenuBasedProgram` function. You should not modify anything else from this file.
* `book.h` and `book.cpp`, these are the `Book` class files. This class represents a book. In our abstraction the book has a name, a price and a publication year. You may add methods to this class (no accessors or mutators though), but you may not remove or modify any of the given methods.
* `booklist.h` and `booklist.cpp`, these are the `BookList` class files. This class represents the list of books, it will implement operations to interact with the list: add, remove, find, get, count, read, write, string and json representation. You may add methods to this class (no accessors or mutators though), but you may not remove or modify any of the given methods.

## Your objective

Implement all the methods of the `Book` and `BookList` classes, additionally write the code necessary for the menu based program. Notice that your "todo" tasks are marked in the code, you can take advantage of CLion to find the things that you need to do.

Your have two goals:
1. Pass all the tests
2. Finish the menu based program

See below in "Program Execution" for what your program run should look like.

## Class Descriptions

### Book

#### Data Members
* `_name` is a string that represents the name of the book. The name of the book may contain spaces.
* `_year` is an unsigned int that represents the publication date
* `_price` is a double that represents the price of the book

#### Methods
* `Book(const string& name, unsigned int year, double price)` constructor of the class, takes in all information necessary to set the values of the data members.
* `Book(const Book& book)` copy constructor, it does a shallow copy of the parameter
* `string ToString()const` returns a string representation of the Book. The output for the following code would be: `(Dark Plane, 2001, 19.95)`
```c++
Book book("Dark Plane", 2001, 19.95);
cout << book.ToString() << endl;
```
* `string ToJSON()const` returns a JSON representation of the object. The output for the following code would be: `{"name":"Dark Plane", "year":2001, "price":19.95}`
```c++
Book book("Dark Plane", 2001, 19.95);
cout << book.ToJSON() << endl;
```
* `double GetPrice()const` accessor method to retrieve the price of the book. This is the only accessor method you are allowed to write.
* `void SetPrice(double price)` mutator method to change the price of the book.
* `bool Equals(const Book& rhs)const` this method returns `true` if `this` and the parameter `rhs` are the same book. It does this by comparing the name of the books. It does not compare year or price.
* `istream& Read(istream& input)` reads a book from an input stream. The format of the stream is going to be a comma separated values format. So, a book on an input stream would look like: `Shadow Puppets,1980,9.99\n`. You may assume that a single book is ended with a newline character. 
* `ostream& Write(ostream& output)const` writes a book into a stream. The book will be represented with comma separated values of the data members. This means that whatever you Write into a stream, you should be able to Read it later.

### BookList

#### Data Members
* `_books` this is a fixed size array of pointers to books. Your assignment sets the size of the array to `MAX_BOOKS` with value 10. Since `Book` does not have a default constructor this is an array of `Book*`, therefore, you will need to dynamically allocate a Book to insert the address of that book into the array.
* `_size` it keeps track on how many books are actually in the array. This value can never be greater than 10, as this is the maximum number of books set for this array.
 
#### Methods
* `BookList()` default constructor, initializes the size of the list to zero.
* `~BookList()` destructor of the class. Since our books are being dynamically allocated, before the program finishes they need to be deallocated. This method will take care of deleting all the existing books in the list.
* `bool AddBook(const Book& book)` adds a book to the array. The method returns `true` if it was able to add a book (if there was enough space in the array), and `false` if the array is full. Keep in mind, this method takes in a book, so you will need to dynamically allocate a copy of the parameter and add that address to the array - only if it fits -. When adding a book, you always add at the end of the list.
* `bool AddBook(const string& name, unsigned int year, double price)` this method takes in the information necessary to create a book, so you can create the book with the parameters and then insert it into the array. Like the previous `AddBook` method returns `true` when it is able to insert and `false` otherwise.
* `Book* RemoveBook(size_t position)` this method removes a book from the list. The method takes in the position of the book to be removed. If the position is valid, the address of the removed book is returned and the elements of the array are shifted accordingly. If the position was not valid then the method returns `nullptr`.
* `const Book* FindBook(const string& name)const` returns a pointer to the book that has the name sent as parameter. If the book is not found (there is no book with the given name in the list), then the method returns `nullptr`.
* `const Book* GetBook(size_t position)const` returns a pointer to the book in the given position. If the position was not valid it returns `nullptr`.
* `size_t BookCount()const` returns the number of elements in the list.
* `size_t Read(istream& input)` reads books from a stream, it will continue to read until the list is full or the end of the stream has been reached.
* `size_t Write(ostream& output)const` writes books to a stream.
* `string ToString()const` returns a string representation of the book list. This is an example of a possible string returned by this method: `4: ((Bible, 2000, 19.99), (Little Prince, 1999, 2.95), (Titanic, 1980, 0.99), (I Love you yesterday, 2001, 7.49))`. Note that each book is there with their string representation, and that at the beginning of the string there is a number that represents the number of elements in the list.
* `string ToJSON()const` returns a JSON representation of the book list. This is an example of a possible string returned by this method: `[{"name":"Bible", "year":2000, "price":19.99}, {"name":"Little Prince", "year":1999, "price":2.95}, {"name":"Titanic", "year":1980, "price":0.99}, {"name":"I Love you yesterday", "year":2001, "price":7.49}}`. Note that the list is contained between `[]` and the elements are separated by `,`.


## Grading

* Test Script, The total number of tests you will need to pass are 44, if you get all 44 then your raw grade will be 80, assuming you don't get any deduction on good programming practices.
* Menu Implementation, we will run your menu implementation and check some operations, this part will have 20 points of your lab grade. If you can make your menu run like the one presented below you should get those points (assuming your program doesn't crash.)

## Deductions

* For each infraction on good programming practices there will be a deduction of 5 points
* If the program has a runtime error (the program crashes) there will be a deduction of 10 points
* If the program does not have comment headers there will be a deduction of 5 points
* If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
* If the program does not follow instructions, for instance if you did not implement any of the requested functions, there will be a deduction of 5 points per ignored instruction
* If the program does not compile, the grade will be zero.

> NOTE: Remember to check the Canvas Page about Programming Practices and the course coding conventions.

## A Possible Workflow
This is one possible way to tackle this lab:
1. Implement the `Book` class methods, then run the _Test Script_ to check the results of this part. The first 9 tests are about the `Book` class.
2. Implement the `BookList` class methods:
   1. Batch 1 (5 more tests)
      1. `BookCount`
      2. `AddBook` the two versions
   2. Batch 2 (15 more tests)
      1. `FindBook`
      2. `GetBook`
   3. Batch 3 (6 more tests)
      1. `RemoveBook`
   4. Batch 4 (9 more tests)
      1. `Write`
      2. `Read`
      3. `ToString`
      4. `ToJSON`

Please note this workflow is based on the order that the tests are executed in the Test Script option, you can always follow this pattern for future labs.

## Academic Integrity

This programming assignment is to be done on an **individual** basis. At the same time, it is understood that learning from your peers is valid, and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.

Hence, the following guidelines are established:
* Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
* Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem solving: control the urge to show them what to do by writing the code for them.
* If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
* If there is any evidence that a program or other written assignment was copied from another student (or from any source), neither student will receive any credit for it. This rule will be enforced.
* Protect yourself: Handle throw-away program listings carefully.
* Remember to read the Academic Integrity guidelines provided in the class syllabus.
* DO NOT copy code from any source, **ALL** the submitted code should be written by you (except the code that is given).



## Program Execution

### Menu Based Execution
```
 Welcome to the Bookstore Program
**********************************

1. Run a Menu Based Program
2. Run the Test Script (The one that is graded)
Your Option: 1
============================
    Welcome to Bookstore
----------------------------
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 1
Input file name: nothere
Could not open nothere
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 4
Please input name year and price (Separated by space): Mamma 1990 15.95
Book added Successfully
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3
(Mamma, 1990, 15.95)

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 4
Please input name year and price (Separated by space): Pappa 1991 9.99
Book added Successfully
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3
(Mamma, 1990, 15.95)
(Pappa, 1991, 9.99)

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 4
Please input name year and price (Separated by space): Sister 1992 14.11
Book added Successfully
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 4
Please input name year and price (Separated by space): Brother 1993 5.45
Book added Successfully
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3
(Mamma, 1990, 15.95)
(Pappa, 1991, 9.99)
(Sister, 1992, 14.11)
(Brother, 1993, 5.45)

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 6
What is the book's name: Cousin
Cousin not found in the list
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 6
What is the book's name: Mamma
Found: (Mamma, 1990, 15.95)
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 5
0	(Mamma, 1990, 15.95)
1	(Pappa, 1991, 9.99)
2	(Sister, 1992, 14.11)
3	(Brother, 1993, 5.45)
Select the index of the book to be removed: 2
(Sister, 1992, 14.11) removed from the list
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3
(Mamma, 1990, 15.95)
(Pappa, 1991, 9.99)
(Brother, 1993, 5.45)

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 2
Input file name: family.txt
3 records written to file

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 7
```
Run again...
```
 Welcome to the Bookstore Program
**********************************

1. Run a Menu Based Program
2. Run the Test Script (The one that is graded)
Your Option: 1
============================
    Welcome to Bookstore
----------------------------
1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 1
Input file name: family.txt
Successfully read 3 books

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 3
(Mamma, 1990, 15.95)
(Pappa, 1991, 9.99)
(Brother, 1993, 5.45)

1. Load a File of Books
2. Store to a File of Books
3. List All Books
4. Add a Book
5. Remove a Book
6. Find a Book
7. Exit
Your Option: 7
```
### Test Script Execution
```
 Welcome to the Bookstore Program
**********************************

1. Run a Menu Based Program
2. Run the Test Script (The one that is graded)
Your Option: 2
========================
   Start Test Scripts
------------------------


 Book Class Tests
- - - - - - - - - -
TEST PASSED (Book::ToString()                        ) Total Passed: 1
TEST PASSED (Book::ToJSON()                          ) Total Passed: 2
TEST PASSED (Book::GetPrice()                        ) Total Passed: 3
TEST PASSED (Book::GetPrice()                        ) Total Passed: 4
TEST PASSED (Book::Equals() is false                 ) Total Passed: 5
TEST PASSED (Book::Equals() is true                  ) Total Passed: 6
TEST PASSED (Book::Equals() is true                  ) Total Passed: 7
TEST PASSED (Book::Read()                            ) Total Passed: 8
TEST PASSED (Book::Write()                           ) Total Passed: 9


 BookList Class Tests
- - - - - - - - - - - -
TEST PASSED (BookList::BookCount() == 0              ) Total Passed: 10
TEST PASSED (BookList::Add(Book)                     ) Total Passed: 11
TEST PASSED (BookList::BookCount() == 1              ) Total Passed: 12
TEST PASSED (BookList::Add(Name, Year, Price)        ) Total Passed: 13
TEST PASSED (BookList::BookCount() == 2              ) Total Passed: 14
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 15
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 16
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 17
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 18
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 19
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 20
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 21
TEST PASSED (BookList::Add(Name, Year, Price) +      ) Total Passed: 22
TEST PASSED (BookList::BookCount() == 10             ) Total Passed: 23
TEST PASSED (List full, unable to add                ) Total Passed: 24
TEST PASSED (BookList::Find() Found                  ) Total Passed: 25
TEST PASSED (BookList::Find() Not Found              ) Total Passed: 26
TEST PASSED (BookList::GetBook() valid position      ) Total Passed: 27
TEST PASSED (BookList::GetBook() valid position      ) Total Passed: 28
TEST PASSED (BookList::GetBook() invalid position    ) Total Passed: 29
TEST PASSED (BookList::Remove() invalid position     ) Total Passed: 30
TEST PASSED (BookList::Remove() Book Reference OK    ) Total Passed: 31
TEST PASSED (BookList::Remove() Size decreased       ) Total Passed: 32
TEST PASSED (BookList::Remove() New First Element    ) Total Passed: 33
TEST PASSED (BookList::Remove() last position        ) Total Passed: 34
TEST PASSED (BookList::GetBook() invalid position    ) Total Passed: 35
TEST PASSED (BookList::Read() Count is correct       ) Total Passed: 36
TEST PASSED (BookList::Read() Element 0              ) Total Passed: 37
TEST PASSED (BookList::Read() Element 1              ) Total Passed: 38
TEST PASSED (BookList::Read() Element 2              ) Total Passed: 39
TEST PASSED (BookList::Read() Element 3              ) Total Passed: 40
TEST PASSED (BookList::GetBook() invalid position    ) Total Passed: 41
TEST PASSED (BookList::Write()                       ) Total Passed: 42
TEST PASSED (BookList::ToJSON()                      ) Total Passed: 43
TEST PASSED (BookList::ToString()                    ) Total Passed: 44
```
