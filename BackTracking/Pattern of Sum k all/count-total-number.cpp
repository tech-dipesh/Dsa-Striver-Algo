#include <iostream>
using namespace std;

int Count(int arr[], int i, int k, int sum, int n){
  if(i==n){
    if(sum==k){
      return 1;
    }
    return 0;
  }
  
  // Take:
  sum+=arr[i];
  int left=Count(arr, i+1, k, sum, n);
  sum-=arr[i];
  // Not Take:
  int right=Count(arr, i+1, k, sum, n);
  return left+right;
}
int main(){
  int arr[]={2, 3, 1, 2};
  int n=sizeof(arr)/sizeof(arr[0]);
  int k=3, sum=0, i=0;
  cout<<Count(arr, i, k, sum, n);
return 0;
}