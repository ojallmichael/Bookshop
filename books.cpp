///Ojall Michael Omondi P15/31821/2015
///A Bookshop Inventory for checking stock status, updating price...
#include "books.h"
#include <iostream>
#include <fstream>

using namespace std;

int books::success;
int books::fail;
int books::counter;


void books::getbookdetails()
{
    test book[3];
    int x;

    for (x=0; x<3; x++)
    {

        cout << "id: 00"<<x+1;
        cout <<"\nenter title name\n";
        cin >> book[x].title;
        cout <<"enter author name\n";
        cin >> book[x].author;
        cout <<"enter publisher\n";
        cin >> book[x].publisher;
        cout <<"enter price\n";
        cin >> book[x].price;
        cout <<"enter stock\n";
        cin >> book[x].stock;
        cout << "\n\n";
        counter ++;
    }

         for(x=0; x<3; x++)
        {
            title[x] =book[x].title;
            authors[x] =book[x].author;
            price[x] =book[x].price;
            stock[x] =book[x].stock;
            publish[x] =book[x].publisher;
        }


    ofstream myfile ("file.txt");
    while(myfile.is_open())
    {
        x=0;
        while(x != counter)
        {
            myfile << "book: " << x+1 << "\n" << "Title: "<<title[x]<<"\n" <<"Author: "<<authors[x] <<"\n"<<"publisher: "<<publish[x] <<"\n" <<"price: @"<<price[x] <<"\n" <<"stock: "<<stock[x] <<"\n\n\n" ;
            x++;
        }
        myfile.close();
        cout << "it works\n";
    }


}

void books::displaydetails()
{
    int x;
    //test book[10];

    for (x=0; x<counter; x++)
    {

        cout << "\nbook id : 00" << x+1;
        cout << "\ntitle: "<< title[x]<<"\n";
        cout << "author: "<< authors[x]<<"\n";
        cout << "publisher: "<< publish[x]<<"\n";
        cout << "price: @"<<price[x] <<"\n";
        cout << stock[x]<<" copies in stock.\n";
    }
}

void books::searchbook()
{
    int x;
    //test book[3];

    cout << "book title: ";
    cin >> titles;
    cout << "author name: ";
    cin >> auth;

    for(x=0; x<counter; x++)
    {
        if(authors[x] == auth)
        {
            if (title[x] == titles)
            {
                cout <<"\n"<< title[x] <<" by "<< authors[x] <<"\ncurrent price is "<<price[x]<<" per copy\n"<< stock[x]<<" copies in stock";
                hold = x;
                break;
            }
            else
            {
                continue;
            }

        }

        else if(x == counter-1)
        {
            cout << "book not found\n";
            break;
        }
        else
        {
            continue;
        }
    }

}

void books::purchase()
{
    int y, x, rem, tprice;


    while (x == hold)
    {
        cout << "\ncopies: ";
        cin >>y;
        if (y > stock[x])
        {
            cout << "stock aint enough\n";

            fail ++;
            break;
        }
        else
        {
            rem = stock[x] - y;
            cout << "books available\n";

            tprice = y * price[x];

            cout << "total price for "<< y << " books is " << tprice <<"\n";

            stock[x] = rem;

            success ++;
            break;
        }
    }

    cout << "\nnumber of successful transactions: " << success;
    cout << "\nnumber of failed transactions: " << fail << "\n";

    books::update();

}

void books::update()
{
    ofstream myfile ("file.txt");
    while(myfile.is_open())
    {
        x=0;
        while(x != counter)
        {
            myfile << "book: " << x+1 << "\n" << "Title: "<<title[x]<<"\n" <<"Author: "<<authors[x] <<"\n"<<"publisher: "<<publish[x] <<"\n" <<"price: @"<<price[x] <<"\n" <<"stock: "<<stock[x] <<"\n\n\n" ;
            x++;
        }
        myfile.close();
        cout << "it works\n";
    }
}


void books::changeprice()
{
    int x, newprice;
    cout << "price change\n";

    while (x == hold)
    {
        cout << "set new price: ";
        cin >> newprice;

        price[x] = newprice;
        cout << "\nprice updated successfully\n";
        break;

    }

          update();
}

void books::addbooks()
{
    cout << "\n\n New Books. \n";
     int x ,y, cont;

     cout << "how many books: ";
     cin >> y;


    test book[5];

    for (x=3; x<y+3; x++)
    {
        cout <<"enter title name\n";
        cin >> book[x].title;

        cout <<"enter author name\n";
        cin >> book[x].author;

        cout <<"enter publisher\n";
        cin >> book[x].publisher;

        cout <<"enter stock\n";
        cin >> book[x].stock;

        cout <<"enter price\n";
        cin >> book[x].price;

        counter ++;

    }

     for(x=3; x<y+3; x++)
        {
            title[x] =book[x].title;

            authors[x] =book[x].author;


            price[x] =book[x].price;


            stock[x] =book[x].stock;


            publish[x] =book[x].publisher;

        }

    update();



}

books::books()
{
    new test;
}

void books::showmybooks()
{
    string data;

     // open a file in read mode.
    //string data;

     // open a file in read mode.
   ifstream myfile("file.txt");
    if (myfile.is_open())
    {
        while(getline(myfile, data))
        {
            cout << data << "\n";
        }
        myfile.close();
    }

    else
    {
        cout << "unable to open file\n";
    }


   // again read the data from the file and display it.
   //myfile >> data;
   //cout << data << endl;

   // close the opened file.
   //myfile
   myfile.close();
}

void books::addcopies()
{
    int x, newstock;
    cout << "stock increase\n";
    //searchbook();

    while (x == hold)
    {
        cout << "\nNumber of copies: ";
        cin >> newstock;

        stock[x] = stock[x] + newstock;
        cout << "\nupdated successful\n";
        break;

    }

          update();
}
return 0;
