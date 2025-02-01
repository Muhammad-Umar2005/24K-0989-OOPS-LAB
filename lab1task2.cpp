#include"iostream"
#include"string"
using namespace std;

float avg[4],avglweek[4];
void inputrecord(int arr[4][7]){
  for (int i=1;i<=4;i++){
 cout << "Enter the record of city "<< i << endl;
 for (int j=1;j<=7;j++){
  cout << "Enter the record of Day " << j << endl;
  cin >> arr[i-1][j-1];
 }
}
for (int i=0;i<4;i++){
avg[i]=0;
for (int j=0;j<7;j++){
avg[i]+=arr[i][j];
}
avg[i]=avg[i]/7; 
cout << "Average AQI value of city" << i+1 << " over the week is " << avg[i] <<endl;
}
int j=0;
int max=avg[0];
for (int i=1;i<4;i++){
  if (avg[i]>max){
        max=avg[i];
          j=i+1;
  }
}
cout << "City " << j << " have the worst air quality" << endl;
}

void criticaldays(int arr[4][7]){
    for(int i=0;i<4;i++){
    for(int j=0;j<7;j++){
      if (arr[i][j]>=150){
        cout << "Day " << j+1 << " of week " << i+1 << " is critical polluted day" << endl;
      }
    }
    }
}

void citylevel(int arr[4][7]){
  int cityweek[4][7];
  for (int i=0;i<4;i++){
    for(int j=0;j<7;j++){
      cityweek[i][j]=arr[i][j];
    }
  }
  for (int i=0;i<4;i++){
  cout << "AQI Levels for city " << i+1 << " over the week" << endl;
  for (int j=0;j<7;j++){
  cout << "Day " << j+1 << " : ";
     while(cityweek[i][j]>=50){
      cout << "*";
      cityweek[i][j]-=50;
     }
     cout << "\n";
  }
     cout << "\n";
  }
}

void inputmonthrecord(int arr[4][7],int array[4][21]){
 for(int i=0;i<4;i++){
  cout << "AQI Values of city " << i+1 << endl;
  for (int j = 0; j < 21; j++)
  {
   cout << "Enter the record of Day " << j+8 << endl;
   cin >>  array[i][j];
  }
   }
}
void monthlyavgAQI(int arr[4][7],int array[4][21],float avg[4]){
  float average[4];
for (int i=0;i<4;i++){
  average[i]=0;
average[i]+=avg[i];
for(int k=0;k<21;k++){

average[i]+=array[i][k];
}
average[i]=average[i]/28; 
cout << "Average AQI value of city " << i+1 << " over the month is " << average[i] <<endl;
}
int j=0;
  for (int i=0;i<4;i++){
avglweek[i]=0;
for (int j=20;j<28;j++){
avglweek[i]+=array[i][j];
}
avglweek[i]=avglweek[i]/7;
float citystats[4];
 citystats[0]=avg[0]-avglweek[0];
 citystats[1]=avg[1]-avglweek[1];
 citystats[2]=avg[2]-avglweek[2];
 citystats[3]=avg[3]-avglweek[3];
int max=citystats[0];
for (int i=1;i<4;i++){
  if (citystats[i]>max){
        max=citystats[i];
          j=i+1;
  }
}
}
cout << "City " << j << " has most improved air quality" << endl;
}
void report(int arr[4][7],int array[4][21],float average[4],float avg[4],float avglweek[4]){
cout << "__________REPORT__________" << endl;


cout << "___Weekly Averages___" << endl;
cout << "..1st week average.." << endl;
for (int i=0;i<4;i++){
avg[i]=0;
for (int j=0;j<7;j++){
avg[i]+=arr[i][j];
}
avg[i]=avg[i]/7; 
cout << "Average AQI value of city" << i+1 << " over the 3rd week is " << avg[i] <<endl;
}
float avg2[4],avg3[4];
cout << "..Second week average.." << endl;
for (int i=0;i<4;i++){
avg2[i]=0;
for (int j=7;j<14;j++){
avg2[i]+=array[i][j];
}
avg2[i]=avg2[i]/7; 
cout << "Average AQI value of city" << i+1 << " over the 2nd week is " << avg2[i] <<endl;
}
cout << "3rd week average" << endl;
for (int i=0;i<4;i++){
avg3[i]=0;
for (int j=14;j<21;j++){
avg3[i]+=array[i][j];
}
avg3[i]=avg3[i]/7; 
cout << "Average AQI value of city" << i+1 << " over the 3rd week is " << avg3[i] <<endl;
}
cout << "4th week average" << endl;
for (int i=0;i<4;i++){
avglweek[i]=0;
for (int j=21;j<28;j++){
avglweek[i]+=array[i][j];
}
avglweek[i]=avglweek[i]/7; 
cout << "Average AQI value of city" << i+1 << " over the 4th week is " << avglweek[i] <<endl;
}


cout << "______Critical Polluted Days______" << endl;
 for(int i=0;i<4;i++){
    for(int j=0;j<7;j++){
      if (arr[i][j]>=150){
        cout << "Day " << j+1 << " of week " << i+1 << " is critical polluted day" << endl;
      }
    }
    }
 for(int i=0;i<4;i++){
    for(int j=7;j<28;j++){
      if (arr[i][j]>=150){
        cout << "Day " << j+1 << " of week " << i+1 << " is critical polluted day" << endl;
      }
    }
    }

int HighestAQI=arr[0][0];
int LowestAQI=arr[0][0];
cout << "_____Highest and lowest AQI values over the month______" << endl;
for (int i=0;i<4;i++){
for (int j=0;j<7;j++){
 if (arr[i][j]>HighestAQI)
 HighestAQI=arr[i][j];
 if (arr[i][j]<LowestAQI)
 LowestAQI=arr[i][j];
}
}

for (int i=0;i<4;i++){
for (int j=7;j<28;j++){
 if (array[i][j]>HighestAQI)
 HighestAQI=arr[i][j];
 if (array[i][j]<LowestAQI)
 LowestAQI=arr[i][j];
}
}

cout << "Highest AQI recorded over the month is " << HighestAQI << endl;
cout << "Lowest AQI recorded over the month is " << LowestAQI << endl;
}

int main(){

 int arr[4][7],array[4][21];
 float avg[4],average[4],avglweek[4];
 inputrecord(arr);
 criticaldays(arr);
 citylevel(arr);
 inputmonthrecord(arr,array);
 monthlyavgAQI(arr,array,avg);
 report(arr,array,average,avg,avglweek);
 return 0;

}