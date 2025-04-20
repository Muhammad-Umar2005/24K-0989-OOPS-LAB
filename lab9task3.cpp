#include "lab9task3.h"
#include<iostream>
using namespace std;

int main(void){
    Course *c1=new LectureCourse("SS2013",2);
    c1->calGrade(78);
    c1->display();
    c1=new LabCourse("SL1013",1);
    c1->calGrade(83);
    c1->display();
}
