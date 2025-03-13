#include<iostream>
using namespace std;
class Level{
public:
string level[10];
 int NoOfLevels;
 Level(){}
Level(int nol){
    NoOfLevels=nol;}
void display(){
    for (int i=0;i<NoOfLevels;i++){
        cout << "Detail of level "  << i+1 << " :" << endl;
        cin >> level[i];
     }
     for(int i=0;i<NoOfLevels;i++){
        cout << "Level " << i+1 << " Details :" << level[i] << endl;
    }
}};
class Game{
public:
string Name;
Level L1;
Game(string n,int noOfLevels) : Name(n),  L1(noOfLevels) {}
void display(){
    cout << "Game Name: " << Name << endl;
    L1.display();
}};
int main(){
Game G1("Counter Strike",4);
G1.display();}