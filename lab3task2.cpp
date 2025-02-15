#include<iostream>
using namespace std;

class FitnessTracker{
    public:
    float weight;
    int stepTaken;
    string username;
    int distance;
    int dailyStepGoal;
    int calorieBurned;
    int duration;
    float distancefeet;
    void stepsTaken(){
     cout << "Enter the distance in metres you walk today" << endl;
     cin >> distance;
     stepTaken=distance*1.3;// Approx 1300 steps in 1 kilometre.
    }
    void dailyStepsGoal(){
        cout << "Enter the daily walking goal in steps" << endl;
        cin >> dailyStepGoal;
    }
    int caloriesBurned(){
    cout << "Enter your duration of walking in minutes" << endl;
    cin >> duration;
       cout << "Enter your weight in kgs" << endl;
    cin >> weight;
    distancefeet=distance*3.281;
    calorieBurned=(duration*2.3*3.5*weight)/200;
    cout << "You burned " << calorieBurned << " calories by walking " << stepTaken << " steps" << endl;
    return 0;
    }

    void status(){
        if(stepTaken>=dailyStepGoal && calorieBurned>=250){
            cout << "You achieve their fitness goal for the day" << endl;
        }
        else 
          cout << "You are not achieve your fitness goal for the day" << endl;
    }
};

int main(){
 FitnessTracker u1;
u1.dailyStepsGoal();
u1.stepsTaken();
u1.caloriesBurned();
u1.status();
  return 0;
}
