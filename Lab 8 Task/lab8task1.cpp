#include<iostream>
#include<math.h>
using namespace std;

class Complex{
private:
int realno;
int imagno;
public:
void input(){
 cout << "Enter real and imaginery number respectively " << endl;
 cin >> realno;
 cin >> imagno;
}

Complex operator+(Complex Obj){
    Complex temp;
    temp.realno=realno+Obj.realno;
    temp.imagno=imagno+Obj.imagno;
    return temp;
}

Complex operator/(Complex Obj){
    Complex temp;
    temp.realno=realno/Obj.realno;
    temp.imagno=imagno/Obj.imagno;
    return temp;
}

Complex operator-(Complex Obj){
    Complex temp;
    temp.realno=realno-Obj.realno;
    temp.imagno=imagno-Obj.imagno;
    return temp;
}

Complex operator*(Complex Obj){
    Complex temp;
    temp.realno=realno*Obj.realno;
    temp.imagno=imagno*Obj.imagno;
    return temp;
}

void operator==(Complex Obj){
    if (realno==Obj.realno && imagno==Obj.imagno){
     cout << "Both Complex Numbers are Equal " << endl;
    }
        else exit;
}
void operator!=(Complex Obj){
    if (realno!=Obj.realno && imagno!=Obj.imagno){
    cout << " Complex Numbers are not Equal "  << endl;
    }
    else exit;
}

friend double magnitude(Complex& obj){
    double b=(obj.realno*obj.realno)+(obj.imagno*obj.imagno);
    cout << "Magnitude: " << sqrt(b) << endl;
    return 0;
}

friend ostream& operator<<(ostream &os,Complex &Obj){
os << Obj.realno;
 if (Obj.imagno>=0){
    os <<"+" << Obj.imagno << "i";
 }
 else {
 os << Obj.imagno << "i";
 }
 return os;
}
};

int main(){
    Complex com1,com2,res;
    com1.input();
    com2.input();
    magnitude(com1);
    magnitude(com2);
    res=com1+com2;
    cout << res;
    cout << "\n" ;
    res=com1-com2;
    cout << res;
    cout << endl;
    res=com1*com2;
    cout << res;
    cout << endl;
    res=com1/com2;
    cout << res;
    cout << endl;
    com1==com2;
    com1!=com2;
    return 0;
}