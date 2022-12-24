#include<iostream>
#include<string>
using namespace std;
class Book{
    string title;
    string author;
    public:
    Book(){
        title="Percy Jackson & the Olympians";
        author="Rick Riordan";
    }
     string book_title(){
        return title;
    }
    string book_author(){
        return author;
    }
    void display(){
        cout<<"The book '"<< book_title() <<"' was written by author "<<book_author()<<endl;
    }
};
class Fiction : public Book{
    int reading_level;
    public:
    Fiction(){
        reading_level=5;
    }
    int book_rlvl(){
        return reading_level;
    }
    void display(){
        Book::display();
        cout<<"This book has a reading level of: "<<book_rlvl()<<endl;
    }
};
class Non_Fiction : public Book{
    int pages;
    public:
    Non_Fiction(){
        pages=500;
    }
    int book_pages(){
        return pages;
    }
    void display(){
        Book::display();
        cout<<"This book has " <<book_pages()<<" no of pages"<<endl;
    }
};
int main(){
    Book book;
    cout<<"First: "<<endl;
    book.display();
    cout<<"\nSecond: "<<endl;
    Fiction fiction;
    fiction.display();
    cout<<"\nThird: "<<endl;
    Non_Fiction nonfiction;
    nonfiction.display();
    return 0;
}