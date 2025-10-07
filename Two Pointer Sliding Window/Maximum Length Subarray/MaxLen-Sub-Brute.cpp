#include <iostream>
using namespace std;
// finding the maximum sum element with based on the some basic condition.

int ConstantWindow(int arr[], int cond, int n){
  int maxLen=0;
  for(int i=0;i<n-1;i++){
    int sum=0;
    for(int j=0;j<n-1;j++){
      sum+=arr[j];
      if(sum<=cond){
        maxLen=max(maxLen, j-i+1);
      }
      else if(sum>cond){
        break;
      }
    }
    return maxLen;
}
}
int main(){
  int arr[]={12, 3, 15, 10, 6, 8, 4, 1, 12, 9, 14, 18, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int conditionlessthan=41;
  cout<<ConstantWindow(arr, conditionlessthan, n);
return 0;
}