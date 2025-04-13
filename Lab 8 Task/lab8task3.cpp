#include<iostream>
using namespace std;

class Vector2D{
private:
double xcor;
double ycor;
public:
Vector2D(){}
Vector2D (double xc,double yc) : xcor(xc),ycor(yc) {}
Vector2D operator+(Vector2D &A){
    Vector2D temp;
    temp.xcor=xcor+A.xcor;
    temp.ycor=ycor+A.ycor;
    return temp;
}
Vector2D operator-(Vector2D &A){
    Vector2D temp;
    temp.xcor=xcor-A.xcor;
    temp.ycor=ycor-A.ycor;
    return temp;
}
Vector2D operator*(Vector2D &A){
    double num;
    cout << "Enter scalar number for multiplication" << endl;
    cin >> num;
    Vector2D temp;
    temp.xcor=num*A.xcor;
    temp.ycor=num*A.ycor;
    return temp;
}
friend  void dotproduct(Vector2D &Obj1,Vector2D &Obj2){
cout << "Dot Product: " << (Obj1.xcor*Obj2.xcor)+(Obj1.ycor*Obj2.ycor) << endl;
}

friend ostream& operator<<(ostream &os,Vector2D &A){
    os <<"(" << A.xcor << ",";
    os << A.ycor << ")";
    return os;
}
};

int main(){
 Vector2D V1(4,3),V2(7,2),res;
 dotproduct(V1,V2);
 res=V1+V2;
 cout << res;
 res=V1-V2;
 cout << res;
 res=V1;
 cout << res;

}