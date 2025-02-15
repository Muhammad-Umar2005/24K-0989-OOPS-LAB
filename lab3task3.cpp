#include<iostream>
#include<string>
using namespace std;

class Library {
public:
    string booklist[25];
    char a;
    int i = 5;

    void Addbooks() {
        booklist[0]="Avengers";
        booklist[1]="7Wonders";
        booklist[2]="Seerat-un-Nabi(S.A.W)";
        booklist[3]="CreationOfPakistan";
        booklist[4]="LifeOfQuaid-e-Azam";

        for (i=5;i<25;i++) {
            cout <<"Do you want to add more books in library (Press y for yes and n for no): " << endl;
            cin >> a;
            if (a=='y'|| a=='Y') {
                cin>>booklist[i];
            }else{
                break;
            }
        }
    }

    string Lendbook[25];

    void lendBook() {
        int c=0,k,p=0;
        cout << "Do you want to borrow a book (Press y for yes and n for no): " << endl;
        cin>>a;
        
        if (a=='y' || a=='Y') {
            cout << "Enter the name of the book you want to borrow: " << endl;
            cin >> Lendbook[c];
            for (int j=0;j<i;j++) {
                if (Lendbook[c]==booklist[j]) {
                    cout << "Book borrowed successfully" << endl;
                    p++;
                    k=j;
                    break;
                }
            }

            if (p == 1) {
                booklist[k] ="Borrowed"; 
            } else {
                cout << "Sorry, the book is not available in the library." << endl;
            }
        }
    }

    void availablebook(){
        cout << "___Available Books____" << endl;
        for (int j=0;j<i;j++){
            cout << booklist[j] << endl;
        }
    }
};

int main(){
    Library u1;
    u1.Addbooks();
    u1.lendBook();
    u1.availablebook();
    return 0;
}
