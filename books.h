#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
using namespace std;

class books
{
   public:

        void getbookdetails();
        void displaydetails();
        void searchbook();
        void purchase();
        void update();
        void changeprice();
        void addbooks();
        books();
        void showmybooks();
        void addcopies();

    private:
            struct test
        {
            int stock;
            int price;
            string author;
            string title;
            string publisher;

        };
        string titles;
        string auth;
        int hold;
        int stock[5];
        int price[5];
        string title[10];
        string authors[10];
        string publish[10];
        int x;

        int static success;
        int static fail;
        int static counter;

};

#endif // BOOKS_H
