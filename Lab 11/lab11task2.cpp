#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class ExceptionHandler:public exception{
string message;
public:
ExceptionHandler(string mess) : message(mess) {}
const char* what()const noexcept {
    return message.c_str();
}
};
template <class T>
class Queue{
public:;
int MAXSIZE=20;
T s;
public:
Queue(T s) : s(s) {}
void checkcapacity(){
    if(s>MAXSIZE)
    throw ExceptionHandler("Exception Occured in Queue Overflow\n");
    if(s<=0)
    throw ExceptionHandler("Exception Occured in Queue Underflow\n");
}


};
int main(){
    //int MAXSIZE=20;
try{
Queue<int> Q1(-6);
Q1.checkcapacity();
}catch(const ExceptionHandler& e){
    cout << e.what() << endl;
}
}