#include<iostream>
using namespace std;
class Student{
public:
   string Id;
   string Name;
   int* score;
Student (string id,string n,int sco[5]){
      Id=id;
     Name=n;
     score=new int;
    for (int i=0;i<5;i++){
     score[i]=sco[i];
    }
    };
Student(Student &c){
    this->Id=c.Id;
    this->Name=c.Name;
     score=new int[5];
    for (int i=0;i<5;i++){
    score[i]=c.score[i];
    }
}

~Student(){
    delete score;
}
void details(){
cout << "Id: " << Id << "\nName: " << Name << endl;
for(int i=0;i<5;i++){
    cout << "Subject " << i+1 << " marks: " << score[i] << endl;
}}};
int main(){
int numbers[5]={93,78,75,87,69};
Student s1("A1-22","Sameer",numbers);
s1.details();
Student s2=s1;
s2.score[0]=79;
s2.score[1]=85;
s2.score[2]=91;
s2.score[3]=75;
s2.score[4]=87;
cout << "____________________" << endl;
s1.details();
s2.details();
return 0;
}