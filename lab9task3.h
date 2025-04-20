#ifndef COURSE
#define COURSE
#include<iostream>
using namespace std;

class Course{
public:
string CourseCode;
int credits;
Course(string CC,int c) : CourseCode(CC), credits(c){}

virtual void calGrade(double num)=0;
virtual void display()=0;

};
class LectureCourse:public Course{
public:
string Grade;
LectureCourse(string CC,int c) : Course(CC,c) {}
void calGrade(double num){
    if(num>90 && num<=100)
     Grade="A+";
    if (num>86 && num<=90)
     Grade ="A";
    if (num>82 && num<=86)
     Grade ="A-";
    if (num>=80 && num<=82)
    Grade="B";
    if (num<80)
    Grade="C";
}
void display(){
    cout << "Course Code: " << CourseCode << "\nCredits: " << credits << "Grade: " << Grade << endl;
}
};

class LabCourse:public Course{
    public:
    string Grade;
    LabCourse(string CC,int c) : Course(CC,c) {}
    void calGrade(double num){
        if(num>=86 && num<=100)
         Grade="A+";
        if (num>=78 && num<86)
         Grade ="A";
        if (num>=70 && num<78)
         Grade ="A-";
        if (num>=60 && num<70)
        Grade="B";
        if (num<60)
        Grade="C";
    }
    void display(){
        cout << "Course Code: " << CourseCode << "\nCredits: " << credits << "\nGrade: " << Grade << endl;
    }
    };

#endif