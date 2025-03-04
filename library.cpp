#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    bool isIssued;

    friend class Library; 

public:
    Book(int id, const std::string &t, const std::string &a) 
        : bookID(id), title(t), author(a), isIssued(false) {}

    void displayBookDetails() const {
        std::cout << "Book ID: " << bookID << "\n"
                  << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Status: " << (isIssued ? "Issued" : "Available") << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;

    static int totalBooks;
    static int issuedBooks;

public:
    
    void addBook(const Book &book) {
        books.push_back(book);
        totalBooks++;
    }

    void issueBook(int bookID) {
        for (auto &book : books) {
            if (book.bookID == bookID) {
                if (book.isIssued) {
                    std::cout << "Book is already issued.\n";
                } else {
                    book.isIssued = true;
                    issuedBooks++;
                    std::cout << "Book issued successfully.\n";
                }
                return;
            }
        }
        std::cout << "Book with ID " << bookID << " not found.\n";
    }

    void returnBook(int bookID) {
        for (auto &book : books) {
            if (book.bookID == bookID) {
                if (book.isIssued) {
                    book.isIssued = false;
                    issuedBooks--;
                    std::cout << "Book returned successfully.\n";
                } else {
                    std::cout << "Book was not issued.\n";
                }
                return;
            }
        }
        std::cout << "Book with ID " << bookID << " not found.\n";
    }

    void displayAllBooks() const {
        for (const auto &book : books) {
            book.displayBookDetails();
            std::cout << "-------------------\n";
        }
    }

    static void displayStatistics() {
        std::cout << "Total Books: " << totalBooks << "\n";
        std::cout << "Issued Books: " << issuedBooks << "\n";
    }
};

int Library::totalBooks = 0;
int Library::issuedBooks = 0;

int main() {
    Library lib;
    lib.addBook(Book(101, "The Alchemist", "Paulo Coelho"));
    lib.addBook(Book(102, "The god of small things", "Arundhati Roy"));
    lib.addBook(Book(103, "Oppenhiemer", "Dr. Robert J. Oppenheimer"));

    std::cout << "Library initialized.\n";

    
    lib.displayAllBooks();

  
    std::cout << "\nIssuing Book with ID 102...\n";
    lib.issueBook(102);


    std::cout << "\nIssuing Book with ID 102 again...\n";
    lib.issueBook(102);

   
    std::cout << "\nReturning Book with ID 102...\n";
    lib.returnBook(102);

    
    std::cout << "\nLibrary Statistics:\n";
    Library::displayStatistics();

    return 0;
}
