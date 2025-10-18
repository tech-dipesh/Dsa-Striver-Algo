#include <iostream>
#include <algorithm>
using namespace std;
struct Knap{
  double fraction;
  int profit;
  int weight;
}; 

// This is the custom comperator which sort according to the divide of profit to weight 
bool Sort(Knap a, Knap b){
  return a.fraction>b.fraction;
}
int main(){
    Knap arr[]={
       {0, 10, 2},
       {0, 5, 3},
       {0, 15, 5},
       {0, 7, 7},
       {0, 6, 1},
       {0, 18, 4},
       {0, 3, 1} 
    };

    int n=sizeof(arr)/sizeof(arr[0]);
    int m=15;
   

    for(int i=0;i<n;i++){
      arr[i].fraction=(float)arr[i].profit/arr[i].weight;
    }

    sort(arr, arr+n, Sort);
    double maxProfit=0;

    int i=0;
    while(i<n){
      if(arr[i].weight<=m){
        m-=arr[i].weight;
        maxProfit+=arr[i].profit;
      }
      else{
        break;
      }
    }
    
    
    cout<<maxProfit;
return 0;
}