#include <iostream>
using namespace std;
struct Knap{
  // int object;
  int profit;
  int weight;
};
int main(){
    // Knap arr[]={
    //    {1, 10, 2},
    //    {2, 5, 3},
    //    {3, 15, 5},
    //    {4, 7, 7},
    //    {5, 6, 1},
    //    {6, 18, 4},
    //    {7, 3, 1} 
    // };
     Knap arr[]={
       {100, 20}, 
       {60, 10}, 
       {100, 50}, 
       {200, 40}, 
    };

    int m=90;
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxProfit=0;
     
    for(int i=0;i<n;i++){
      int profit=0, weight=0;
    for(int j=i;j<n;j++){
      if(weight<=m){
        maxProfit=max(maxProfit, profit);
        profit+=arr[j].profit;
        weight+=arr[j].weight;
      }
      else{
        break;
      }
    }
    }
    cout<<maxProfit;
return 0;
}