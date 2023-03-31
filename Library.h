#ifndef UNTITLED2_LIBRARY_H
#define UNTITLED2_LIBRARY_H

#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    string category;
    int pagescount;
    bool isborrowed;

    Book(string t = "", string a = "", string c = "", int num = 0, bool isb = false)
    {
        title = t;
        author = a;
        category = c;
        pagescount = num;
        isborrowed = isb;
    }

    friend ostream& operator<<(ostream& s, const Book& book)
    {
        s << "Title: " << book.title << ", Author: " << book.author << ", Category: " << book.category << ", " << book.pagescount << " pages, Borrowed: ";
        if (book.isborrowed)
        {
            s << "YES";
        }
        else
        {
            s << "NO";
        }
        return s;
    }
};

#endif
