#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
class Book
{
private:
    string title_;
    string author_;
    int year_;
    int pages_;
    bool is_available_;
    bool isValidData(string title, string author, int year, int pages) const;

public:
    Book(string title, string author, int year, int pages);

    string title() const;
    string author() const;
    int year() const;
    int pages() const;
    bool isAvailable() const;
    void checkout();
    void returnBook();

    void updateTitle(string new_title);
    void updateAuthor(string author);
    void updateYear(int year);
    void updatePages(int new_pages);
};

string formatBookInfo(const Book& book);
bool isClassic(const Book& book);
double readingTime(const Book& book, int pages_per_day);
bool isOlder(const Book& first, const Book& second);

#endif