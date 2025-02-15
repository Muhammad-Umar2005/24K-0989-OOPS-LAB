#include<iostream>
#include<string>
using namespace std;

struct book{
string title;
string author;
int year;
};
 
void allocate(book** books,int numberofbook){
    *books=new book[numberofbook];
    cin.ignore();
    for(int i=0;i<numberofbook;i++){
        cout << "Enter the title of book" << i+1 << endl;
        getline(cin,books[i]->title);
         cout << "Enter the author of book" << i+1 << endl;
        getline(cin,books[i]->author);
         cout << "Enter the year of book" << i+1 << endl;
        cin >> books[i]->year;
    }
}
void displaybooks(book* books,int year,int numberofbook){
 cout << "Enter the specified year to check the books after it" << endl;
 cin >> year;
 for (int i=0;i<numberofbook;i++){
    if (year>books[i].year)
    cout << "Book Title : " << books[i].title << "\nBook Author : " << books[i].author <<"\nBook year of publish" << books[i].year << endl;
 }
}
void deletememory(book* books){
   delete[] books;
}

int main(){
    int numberofbook,year;
    book* books;
    cout << "Enter the number of books you want to add" << endl;
    cin >> numberofbook;
    allocate(&books,numberofbook);
    displaybooks(books,year,numberofbook);
    deletememory(books);
    return 0;
}
