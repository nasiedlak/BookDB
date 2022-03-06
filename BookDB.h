/**
 * @Author: Cooper Nasiedlak
 * @NETID: nasiedlak
 * @ID#: 9082213803
 * @Source(s): Stackoverflow.com, Geeksforgeeks.com, & Piazza
 * @Description: This header file includes the function prototypes and strucutre needed for Book the database vector.
 */

#ifndef BOOKDB_H
#define BOOKDB_H
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/**
 * This structure contains the members (elements) of a Book
 */
struct Book {
    unsigned id; // book ID
    unsigned year; // publication year
    double rating; // book rating
};

/**
 * This function searches the database vector for the given bookID; if no book with the given bookID is found, a
 * book with the given bookID, year, and rating to the database vector (returns 1); otherwise, the function returns 0.
 * @param bookID - the given bookID for which to search/add
 * @param year - the given year to add
 * @param rating - the given rating to add
 * @param db - the given database to add onto
 * @return 1 if a new book is added; 0, otherwise
 */
int addBook(unsigned bookID, unsigned year, double rating, std::vector<Book> &db);

/**
 * This function searches the database vector for the given bookID and updates its rating and year if the
 * given bookID is found (returns 1); otherwise, the function returns 0.
 * @param bookID - the given bookID for which to search
 * @param year - the given year to update
 * @param rating - the given rating to update
 * @param db - the given database
 * @return 1 if a book is updated; 0, otherwise
 */
int updateBook(unsigned bookID, unsigned year, double rating, std::vector<Book> &db);

/**
 * This function searches the database vector for the given bookID and removes the given Book if the given
 * bookID is found (returns 1); otherwise, the function returns 0.
 * @param bookID - the given bookID for which to search
 * @param db - the given database
 * @return 1 if a Book is removed; 0, otherwise
 */
int deleteBook(unsigned bookID, std::vector<Book> &db);

/**
 * This function returns a pointer to the vector of Books published in the year specified by
 * the year parameter; otherwise, the function returns -1.0.
 * @param year - the given year of publishing
 * @param db - the given Book vector to search
 * @return a pointer to the vector of Books published in year; -1.0, otherwise
 */
std::vector<Book>* findBooks(unsigned year, const std::vector<Book> &db);

/**
 * This function calculates the average rating of all the Books in the database vector; otherwise, the
 * function returns -1.0.
 * @param db - the given database of which to take the average
 * @return the average rating of all the Books in the database vector
 */
double calculateAverageRating(const std::vector<Book> &db);

/**
 * This function prints the contents of the database vector. otherwise, the function returns "No entries\n".
 * @param db - the give database vector to print; "No entries\n", otherwise
 */
void print(const std::vector<Book> &db);

/**
 * This function sorts the database vector with the given sortingMethod; otherwise, the function returns 0.
 * @param db - the given database vector to sort
 * @param sortingMethod - the given sorting method
 * @return the sorted database vector; 0, otherwise
 */
int sortDB(std::vector<Book> &db, short sortingMethod);

#endif /* BOOKDB_H */