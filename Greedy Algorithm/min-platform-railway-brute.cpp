//  we've to count how many minimum platform does it required to arival and depart a platform.
#include <iostream>
using namespace std;
bool Intersection(int arive1,  int depart1, int arive2, int depart2){
  // this is when the  second rail is bigger from the both side.
  if(arive1>arive2 && depart1<depart2){
    return true;
  }
  // when the second train is coming faster but the depart earlier.
  else if(arive1>arive2 && depart1>depart2){
    return true;
  }
  // when the second arrive later, but the depart later
  else if(arive1<arive2 && depart1>arive1){
    return true;
  }
  // when the second arrive later and depart later.
 else if(arive1<arive2 && depart1<depart2){
  return true;
 }
 else{
  return false; 
 }
}

int main(){
   int arrival[]={900,   945,  955,  1100, 1500, 1800};
   int departure[]={920, 1200, 1130, 1150, 1900, 2000};

   int n=sizeof(arrival)/sizeof(arrival[0]);

  // ans: 920 empty, 1200 empty, 1130 empty, 
  // we don't need another platform for the second train, for the third train it required: 2
  // third also not possible as that depart is not less that 1100 depart: 1200, 1130, 1150
  // fourth not required: 1200, 1150, 1900
  // fifth not required: 1130, 1200, 1900

  int maxCount=0;
  
  for(int i=0;i<n;i++){
    int count=0;
  for(int j=i+1;j<n-1;j++){
    // if(Intersection(arrival[i], departure[j])){
    if(Intersection(arrival[i], departure[i], arrival[j], departure[j])){
        count++;
    }
    maxCount=max(maxCount, count);
  }
  }

  cout<<"max possible count is: "<<maxCount;
return 0;
}