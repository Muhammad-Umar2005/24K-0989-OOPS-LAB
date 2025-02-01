#include<iostream>
#include<string>
using namespace std;
 string event1[5],event2[5],name;
 int size1=1,size2=1,donation=0,temp1,temp2,camp1,camp2,k=1,b=1;

void inputdata(string event1[],string event2[]) {
    char a='Y';
    cout << "Enter the name of members participate in event 1"<< endl;
    cout << "Enter the name of member 1"<< endl;
    cin >> event1[0];
    while(a=='Y'|| a=='y' && k<5){
    cout << "Do you want to add more members. Press (y) for yes and (n) for no:"<< endl;
    cin >> a;
    if (a=='Y' || a=='y'){
    cout << "Enter member name:" << endl;
    cin >> event1[size1];
    size1++;
    k++;
    }
    }
    cout <<" "<< k <<" members are participate in event 1" <<endl;
    cout << "Enter the name of members participate in event 2"<< endl;
    cout << "Enter the name of member 1"<< endl;
    
    cin >> event2[0];
    a='Y';
    while(a=='Y'|| a=='y' && k<5){
    cout << "Do you want to add more members. Press (y) for yes and (n) for no: "<< endl;
    cin >> a;
    if (a=='Y' || a=='y'){
   cout << "Enter member name:" << endl;
    cin >> event2[size2];
    b++,size2++;
    }
    }
    cout <<" "<< b <<" members are participate in event 2" <<endl;
    temp1=size1-1;
    temp2=size2;
    camp1=size1;
    camp2=size2;
}

void check(string event1[],string event2[],string name){
    int k=0;
    cout << "Enter your name for attendance!";
    cin >> name;
    cout << endl;
  for (int i=0;i<5;i++){
    if (name==event1[i]){
    cout << "You are registered in event 1"<< endl;
    k++;
      }
    if (name==event2[i]){
    cout << "You are registered in event 2 "<< endl;
    k++;
    }
  }
      if (k==0)
    cout << "You are not registered for any event:" << endl;
}
void calculate(int size1,int size2){
    while (size1>0){
            donation+=10;
            size1--;
            }
    while (size2>0){
            donation+=10;
            size2--;
            }
     cout <<"Total amount of donations is " << donation <<"$"<< endl;
}

void reverseprint(string event1[],string event2[],int temp1,int temp2){   
        cout << "Members of first event" << endl;
        while(temp1>=0){
            cout<< event1[temp1] << endl;
            temp1--;
            }
        cout << "Members of second event" << endl;
        while(temp2>=0){
             cout<< event2[temp2] << endl;
            temp2--;
            }
         }

void barchart(int camp1,int camp2){
  cout << "Event bar chart" << endl;
  cout << "Event 1: ";
  while(camp1>0){
        cout<<"* ";
        camp1--;
        }
  cout << "( " << k << " parcipitants)" << endl;
  cout << "\n";
  cout << "Event 2: ";
   while(camp2>0){
        cout<<"* ";
        camp2--;
        }
  cout << "( " << b << " parcipitants)" << endl;
  cout << "\n";
}
    int main (){
    inputdata(event1,event2);
    check(event1,event2,name);
    calculate(size1,size2);
    reverseprint(event1,event2,temp1,temp2);
    barchart(camp1,camp2);
    return 0;
    }
