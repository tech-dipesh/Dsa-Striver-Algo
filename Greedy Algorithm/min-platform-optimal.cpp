//  we've to count how many minimum platform does it required to arival and depart a platform.
#include <iostream>
#include <algorithm>
using namespace std;
int totalTrain(int arr[], int n, int depart[]){
    sort(arr, arr+n);
    sort(depart, depart+n);

    int i=0, j=0;
    int MaxPlatform=0, totalPlatform=0;
    while(i<n &&j<n){
        if(arr[i++]<=depart[j]){
            totalPlatform++;
            MaxPlatform=max(totalPlatform, MaxPlatform);
        }
        else{
            j++;
            totalPlatform--;
        }
    }
    return MaxPlatform;
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

  cout<<"max possible count is: "<<totalTrain(arrival, n, departure);
return 0;
}