#include "Library.h"
#include "Map.h"

using namespace std;

Map<int, Book> mylib;

void addBooks()
{
    Book b1 = Book("Pan Tadeusz", "Adam Mickiewicz", "Poem", 376);
    mylib.add(1, b1);

    Book b2 = Book("TITLE BOOK2", "AUTHOR2", "Adventure", 420, true);
    mylib.add(2, b2);

    Book b3 = Book("TITLE BOOK3", "AUTHOR3", "Crime", 230);
    mylib.add(3, b3);

    Book b4 = Book("TITLE BOOK4", "AUTHOR4", "Fantasy", 480, true);
    mylib.add(4, b4);
}

void printBooks()
{
    cout << "Books in library: " << endl << mylib << endl;
}

void modifyBook()
{
    Book* bookptr;
    bookptr = mylib.find(1);
    bookptr->pagescount = 9999;
    bookptr->category = "Comedy";
    bookptr->title = "Jakas ksiazka";
    bookptr->author = "Jan Kochanowski";
    bookptr->isborrowed = true;

    Book* bookptr2 = mylib.find(4);
    bookptr2->pagescount = 12345;
    bookptr2->title = "SOME";
    bookptr2->category = "SOMETHING";
    bookptr2->author = "SOMEONE";
    bookptr2->isborrowed = false;
}

int main() {

    addBooks();
    printBooks();
    modifyBook();
    cout << "AFTER MODIFYING" << endl;
    printBooks();

    return 0;
}