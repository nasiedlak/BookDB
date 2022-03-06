/**
 * @Author: Marc Renault & Cooper Nasiedlak
 * @NETID: nasiedlak
 * @ID#: 9082213803
 * @Source(s): Stackoverflow.com, Geeksforgeeks.com, & Piazza
 * @Description: The source file contains sample testing code for the implementation of the Book database vector.
 */

#include "BookDB.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {

    vector<Book> db;

    unsigned id, year;
    double rating;
    char c;
    int retVal(1);
    do {
        cout << "> ";
        cin >> c;
        switch(c) {
            case 'p':
                print(db);
                break;
            case 'a':
                cin >> id >> year >> rating;
                retVal = addBook(id, year, rating, db);
                if(retVal) cout << "Book " << id << " added\n";
                break;
            case 'd':
                cin >> id;
                retVal = deleteBook(id, db);
                if(retVal) cout << "Book " << id << " removed\n";
                break;
            case 'u':
                cin >> id >> year >> rating;
                retVal = updateBook(id, year, rating, db);
                if(retVal) cout << "Book " << id << " updated\n";
                break;
            case 'c':
            {
                double avg = calculateAverageRating(db);
                if(avg > -1) {
                    cout << "Average rating = " << avg << "\n";
                } else {
                    retVal = 0;
                }
            }
                break;
            case 'f':
            {
                cin >> year;
                vector<Book>* b = findBooks(year, db);
                print(*b);
                free(b); // prevents memory leak
            }
                break;
            case 's':
            {
                short sortOpt;
                cin >> sortOpt;
                retVal = sortDB(db, sortOpt);
            }
                break;
            case 'q':
                break;
            default:
                cout << "Unknown command\n";
                break;
        }
        if(!retVal) {
            cout << "Error processing command\n";
            retVal = 1;
        }
    } while (c != 'q');
    cout << "quit\n";
}