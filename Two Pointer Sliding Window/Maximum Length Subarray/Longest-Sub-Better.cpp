#include <iostream>
using namespace std;

int ConstantWindow(int arr[], int n, int k){
  int l=0, r=0;
  int maxLen=0, sum=0;
  while(r<n){
    sum+=arr[r];
    while(sum>k){
      sum-=arr[l];
      l++;
    }
    if(sum<=k){
      maxLen=max(maxLen, r-l);
      r++; 
    }
  }
  return maxLen;
}
int main(){
  int arr[]={12, 3, 15, 10, 6, 8, 4, 1, 12, 9, 14, 18, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int maxnum=35;
  cout<<ConstantWindow(arr, n, maxnum);
return 0;
}