#include <iostream>
using namespace std;

int ConstantWindow(int arr[], int cond, int n, int k){
  int maxSum=0;
  for(int i=0;i<n-1;i++){
    int sum=0;
    for(int j=0;j<n-1;j++){
      sum+=arr[i]+arr[j];
      if(sum>cond){
        break;
      }
      else{
        maxSum=max(maxSum, sum);
      }
    }
    return maxSum;
}
}
int main(){
  int arr[]={12, 3, 15, 10, 6, 8, 4, 1, 12, 9, 14, 18, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int maxnum=3;
  int conditionlessthan=41;
  cout<<ConstantWindow(arr, conditionlessthan, n, maxnum);
return 0;
}