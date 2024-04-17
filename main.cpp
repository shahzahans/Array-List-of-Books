#include "book.h"
#include "booklist.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::stringstream;
using std::setw;
using std::left;

void Test(bool condition, const char* message, unsigned int& passedTests);
bool DoubleEquals(double a, double b, double epsilon=1e-6);
void RunTests();
void MenuBasedProgram();
int Menu();

int main() {

    cout << " Welcome to the Bookstore Program" << endl;
    cout << "**********************************" << endl << endl;
    int runOption;
    cout << "1. Run a Menu Based Program" << endl;
    cout << "2. Run the Test Script (The one that is graded)" << endl;
    cout << "Your Option: ";
    cin >> runOption;
    while (cin.fail()){
        cerr << endl << "Invalid Input" << endl;
        cout << endl << "Your Option: ";
        cin.clear();
        cin.ignore(255, '\n');
        cin >> runOption;
    }
    if (runOption == 1)
        MenuBasedProgram();
    else if (runOption == 2)
        RunTests();
    else
        cerr << "Not a menu option, goodbye" << endl;
    return 0;
}

/**
 * *****************************************
 * DO NOT CHANGE ANYTHING ON THIS FUNCTION *
 * *****************************************
 */
void RunTests() {
    unsigned int passedTests = 0;
    cout << "========================" << endl;
    cout << "   Start Test Scripts   " << endl;
    cout << "------------------------" << endl;
    cout << endl << endl;
    cout << " Book Class Tests" << endl;
    cout << "- - - - - - - - - -" << endl;

    Book* bookA = nullptr;
    Book* bookB = nullptr;
    Book* bookC = nullptr;
    Book* bookD = nullptr;

    bookA = new Book("My First Book", 1980, 2.44);
    Test(bookA->ToString() == "(My First Book, 1980, 2.44)", "Book::ToString()", passedTests);
    Test(bookA->ToJSON() == "{\"name\":\"My First Book\", \"year\":1980, \"price\":2.44}", "Book::ToJSON()", passedTests);
    Test(DoubleEquals(bookA->GetPrice(), 2.44), "Book::GetPrice()", passedTests);
    bookA->SetPrice(2.5);
    Test(DoubleEquals(bookA->GetPrice(), 2.5), "Book::GetPrice()", passedTests);

    bookB = new Book("Another Book", 2000, 12.99);
    bookC = new Book(*bookA);
    bookD = new Book("My First Book", 1800, 0.44);

    Test(!bookA->Equals(*bookB), "Book::Equals() is false", passedTests);
    Test(bookA->Equals(*bookC), "Book::Equals() is true", passedTests);
    Test(bookA->Equals(*bookD), "Book::Equals() is true", passedTests);
    stringstream stream("The Little Prince,1850,9.95");
    bookA->Read(stream);
    Test(bookA->ToString() == "(The Little Prince, 1850, 9.95)", "Book::Read()", passedTests);

    stream.str("");
    stream.clear();
    bookA->Write(stream);
    Test(stream.str() == "The Little Prince,1850,9.95", "Book::Write()", passedTests);

    delete bookA;
    delete bookB;
    delete bookC;
    delete bookD;

    cout << endl << endl;
    cout << " BookList Class Tests" << endl;
    cout << "- - - - - - - - - - - -" << endl;
    BookList bookstore;

    Test(bookstore.BookCount() == 0, "BookList::BookCount() == 0", passedTests);
    Test(bookstore.AddBook(Book("Foundation", 1970, 4.95)), "BookList::Add(Book)", passedTests);
    Test(bookstore.BookCount() == 1, "BookList::BookCount() == 1", passedTests);
    Test(bookstore.AddBook("Enders Game", 1975, 6.95), "BookList::Add(Name, Year, Price)", passedTests);
    Test(bookstore.BookCount() == 2, "BookList::BookCount() == 2", passedTests);

    for (int i = 0; i < 8; ++i) {
        stringstream bss;
        bss << "Book " << (i + 2);
        Test(bookstore.AddBook(bss.str(), 1980+i, 0.95), "BookList::Add(Name, Year, Price) +", passedTests);
    }
    Test(bookstore.BookCount() == 10, "BookList::BookCount() == 10", passedTests);
    Test(!bookstore.AddBook(Book("Empty", 0, 0)), "List full, unable to add", passedTests);

    Test(bookstore.FindBook("Enders Game")->ToString() == "(Enders Game, 1975, 6.95)", "BookList::Find() Found", passedTests);
    Test(bookstore.FindBook("Shadow Puppet") == nullptr, "BookList::Find() Not Found", passedTests);
    Test(bookstore.GetBook(0)->ToString() == "(Foundation, 1970, 4.95)", "BookList::GetBook() valid position", passedTests);
    Test(bookstore.GetBook(9)->ToString() == "(Book 9, 1987, 0.95)", "BookList::GetBook() valid position", passedTests);
    Test(bookstore.GetBook(10) == nullptr, "BookList::GetBook() invalid position", passedTests);

    bookA = bookstore.RemoveBook(10);
    Test(bookA == nullptr, "BookList::Remove() invalid position", passedTests);
    bookA = bookstore.RemoveBook(0);
    Test(bookA->ToString() == "(Foundation, 1970, 4.95)", "BookList::Remove() Book Reference OK", passedTests);
    delete bookA;
    Test(bookstore.BookCount() == 9, "BookList::Remove() Size decreased", passedTests);
    Test(bookstore.GetBook(0)->ToString() == "(Enders Game, 1975, 6.95)", "BookList::Remove() New First Element", passedTests);
    Test(bookstore.GetBook(8)->ToString() == "(Book 9, 1987, 0.95)", "BookList::Remove() last position", passedTests);
    Test(bookstore.GetBook(9) == nullptr, "BookList::GetBook() invalid position", passedTests);

    BookList ioList;
    stringstream input(
            "Bible,2000,19.99\n"
                "Little Prince,1999,2.95\n"
                "Titanic,1980,0.99\n"
                "I Love you yesterday,2001,7.49\n"
            );
    ioList.Read(input);
    Test(ioList.BookCount() == 4, "BookList::Read() Count is correct", passedTests);
    Test(ioList.GetBook(0)->ToString() == "(Bible, 2000, 19.99)", "BookList::Read() Element 0", passedTests);
    Test(ioList.GetBook(1)->ToString() == "(Little Prince, 1999, 2.95)", "BookList::Read() Element 1", passedTests);
    Test(ioList.GetBook(2)->ToString() == "(Titanic, 1980, 0.99)", "BookList::Read() Element 2", passedTests);
    Test(ioList.GetBook(3)->ToString() == "(I Love you yesterday, 2001, 7.49)", "BookList::Read() Element 3", passedTests);
    Test(ioList.GetBook(4) == nullptr, "BookList::GetBook() invalid position", passedTests);

    stringstream output;
    ioList.Write(output);
    Test(output.str() == "Bible,2000,19.99\n"
         "Little Prince,1999,2.95\n"
         "Titanic,1980,0.99\n"
         "I Love you yesterday,2001,7.49\n","BookList::Write()", passedTests);
    Test(ioList.ToJSON() == "[{\"name\":\"Bible\", \"year\":2000, \"price\":19.99}, {\"name\":\"Little Prince\", \"year\":1999, \"price\":2.95}, {\"name\":\"Titanic\", \"year\":1980, \"price\":0.99}, {\"name\":\"I Love you yesterday\", \"year\":2001, \"price\":7.49}}","BookList::ToJSON()", passedTests);
    Test(ioList.ToString() == "4: ((Bible, 2000, 19.99), (Little Prince, 1999, 2.95), (Titanic, 1980, 0.99), (I Love you yesterday, 2001, 7.49))","BookList::ToString()", passedTests);
}

void MenuBasedProgram() {
    cout << "============================" << endl;
    cout << "    Welcome to Bookstore    " << endl;
    cout << "----------------------------" << endl;
    int menuOption;
    while ((menuOption = Menu()) != 7) {
        if (menuOption == 1){           // Load from file
        // TODO Load from File menu option
        }else if (menuOption == 2){     // Save to file
        // TODO Save to file menu option
        }else if (menuOption == 3){     // List all books
        // TODO List all Books in BookList instance
        }else if (menuOption == 4){     // Add Book
        // TODO Add a book to the BookList instance
        }else if (menuOption == 5){     // Remove Book
        // TODO Remove a book from the BookList instance
        }else if (menuOption == 6){     // Find book
        // TODO Find a book on the BookList instance
        }else{
            cerr << "This should never happen!" << endl;
        }
    }
}

int Menu(){
    int menuOption;
    cout << "1. Load a File of Books" << endl;
    cout << "2. Store to a File of Books" << endl;
    cout << "3. List All Books" << endl;
    cout << "4. Add a Book" << endl;
    cout << "5. Remove a Book" << endl;
    cout << "6. Find a Book" << endl;
    cout << "7. Exit" << endl;
    cout << "Your Option: ";
    cin >> menuOption;
    while (cin.fail()){
        cerr << endl << "Invalid Input" << endl;
        cout << endl << "Your Option: ";
        cin.clear();
        cin.ignore(255, '\n');
        cin >> menuOption;
    }
    while (menuOption < 1 || menuOption > 7){
        cerr << endl << "Invalid Menu Option" << endl;
        cin >> menuOption;
        while (cin.fail()){
            cerr << endl << "Invalid Input" << endl;
            cout << endl << "Your Option: ";
            cin.clear();
            cin.ignore(255, '\n');
            cin >> menuOption;
        }
    }
    return menuOption;
}
bool DoubleEquals(double a, double b, double epsilon){
    return fabs(a - b) < epsilon;
}

void Test(bool condition, const char* message, unsigned int& passedTests){
    if (condition){
        cout << "TEST PASSED (" << left << setw(40) << message << ") Total Passed: " << ++passedTests << endl;
    }else{
        cout << "TEST FAILED (" << message << ")" << endl;
    }
}