#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int trappingrainWater(int arr[], int n){
  int totalWater=0;
  int prefixMax[n], SuffixMax[n];
  prefixMax[0]=arr[0], SuffixMax[n-1]=arr[n-1];
  for(int i=1;i<n;i++){
      prefixMax[i]=max(arr[i], prefixMax[i-1]);
      // biggestPrefix=max(biggestPrefix, prefixMax[i]);
    }

    // For getting hte suffix Value:
    for(int i=n-2;i>=0;i--){
      SuffixMax[i]=max(arr[i], SuffixMax[i+1]);
      // biggestSuffix=max(biggestSuffix, SuffixMax[i]);
  }
  for(int i=0;i<n;i++){
    if(arr[i]<prefixMax[i] && arr[i]<SuffixMax[i]){
      int SmallFix=(min(prefixMax[i], SuffixMax[i]))-arr[i];
      totalWater+=SmallFix;
    }
  }
  return totalWater;
}
int main(){
  int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  //  Res: 6: by: (1, 2): 1 (2, 1): 1, (2, 1): 1, (2, 3): 2, (2, 1): 1=1+1+1+2+1=6
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<trappingrainWater(arr, n);
return 0;
}