#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int trappingrainWater(int arr[], int n){
  // vector<int>vt;
  // stack<int>st;
  int totalWater=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    if(arr[i]>0 && arr[j]>0){
      int minValue=min(arr[i], arr[j]);
     int totoaTrappingWater=minValue*arr[i];
     totalWater+=totoaTrappingWater;
    }
    else if(arr[i]==0 || arr[i]<=arr[j]){
      break;
    }

    else if(arr[j]==0){
        continue;
      }
  }
  }
  return totalWater;
}
int main(){
  int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1};
  //  Res: 6: by: (1, 2): 1 (2, 1): 1, (2, 1): 1, (2, 3): 2, (2, 1): 1=1+1+1+2+1=6
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<trappingrainWater(arr, n);
return 0;
}