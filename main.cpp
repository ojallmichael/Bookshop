//Ojall Michael Omondi P15/31821/2015
// A program that maintains an inventory record of a bookshop by updating and checking stock status.
#include <iostream>
#include <fstream>
#include "books.h"
#include "books.cpp"

using namespace std;

int main()
{
    int choice;
    books values;
    cout << "Welcome\n";

    values.getbookdetails();
    cout << "====================================\n\n";

    while (choice != 6)
    {
        cout << "Choose action.\n";
        cout << "1. Display books in stock.\n";
        cout << "2. Make a purchase.\n";
        cout << "3. Change price of a book.\n";
        cout << "4. Add stock copies\n";
        cout << "5. Add book(s)\n";
        cout << "6. EXIT.\n";

        cin >> choice;

        switch(choice)
        {
        case 1:
            values.displaydetails();
            cout << "==================================\n\n";
            break;

        case 2:
            values.searchbook();
            values.purchase();
            cout << "===================================\n\n";
            break;

        case 3:
            values.searchbook();
            values.changeprice();
            cout << "===================================\n\n";


            break;

        case 4:
            values.searchbook();
            values.addcopies();
            cout << "===================================\n\n";
            break;


        case 5:
            values.addbooks();
            cout << "===================================\n\n";
            break;

        }

    }

    values.searchbook();

    return 0;
}
