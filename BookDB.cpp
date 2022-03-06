/**
 * @Author: Cooper Nasiedlak
 * @NETID: nasiedlak
 * @ID#: 9082213803
 * @Source(s): Stackoverflow.com, Geeksforgeeks.com, & Piazza
 * @Description: this source file contain the function definitions needed for the Book database vector
 */

#include "BookDB.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int addBook(unsigned bookID, unsigned year, double rating, std::vector<Book> &db) {
    // searches for the given bookID in the database
    for(auto &i : db) {
        if (i.id == bookID) {
            return 0;
        }
    }
    // adds a Book to the database
    struct Book book = {bookID, year, rating};
    db.push_back(book);
    return 1;
}

int updateBook(unsigned bookID, unsigned year, double rating, std::vector<Book> &db) {
    // searches for the given bookID and updates respective items
    for(auto &i : db) {
        if (i.id == bookID) {
            i.rating = rating;
            i.year = year;
            return 1;
        }
    }
    return 0;
}

int deleteBook(unsigned bookID, std::vector<Book> &db) {
    // searches and erases the Book with the given bookID
    for(auto itr = db.begin(); itr != db.end(); ++itr) {
        if(itr->id == bookID) {
            db.erase(itr);
            return 1;
        }
    }
    return 0;
}

std::vector<Book>* findBooks(unsigned year, const std::vector<Book> &db) {
    std::vector<Book> *books = new std::vector<Book>;
    // adds all Book's in the given year to the books vector
    for(auto &i : db) {
        if (i.year == year) {
            books->push_back(i);
        }
    }
    return books;
}

double calculateAverageRating(const std::vector<Book> &db) {
    if(db.size() == 0) {
        return -1.0;
    }
    double total = 0;
    // sums the rating of every Book in the database
    for(auto &i : db) {
        total += i.rating;
    }
    return total / db.size();
}

void print(const std::vector<Book> &db) {
    if(db.size() == 0) {
        std::cout << "No entries\n";
    }
    for(auto &i : db) {
        std::cout << i.id << ", " << i.year << ", " << i.rating << "\n";
    }
}

/*
 * comparison helper functions for the sort functionality
 */
bool compareID(const Book &x, const Book &y) {
    return x.id < y.id;
}

bool compareYear(const Book &x, const Book &y) {
    if(x.year == y.year) {
        return x.id < y.id;
    }
    return x.year < y.year;
}

bool compareRating(const Book &x, const Book &y) {
    if(x.rating == y.rating) {
        return x.id < y.id;
    }
    return x.rating < y.rating;
}
/*
 * end helper functions
 */

int sortDB(std::vector<Book> &db, short sortingMethod) {
    // sorts based on the inputted sortingMethod
    if(sortingMethod == 1) {
        std::sort(db.begin(), db.end(), compareID);
        return 1;
    }
    else if (sortingMethod == 2) {
        std::sort(db.begin(), db.end(), compareYear);
        return 1;
    }
    else if (sortingMethod == 3) {
        std::sort(db.begin(), db.end(), compareRating);
        return 1;
    }
    return 0;
}