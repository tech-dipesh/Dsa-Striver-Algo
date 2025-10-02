#include <iostream>
using namespace std;

int ConstantWindow(int arr[], int n, int k){
  int l=0, r=k;
  int maxSum=0, sum=0;
  int insidesum=0;
  for(int i=0;i<k-1;i++)
    sum+=arr[i];
  while(r<n-1){
    sum-=arr[l];
    l++;
    r++;
    sum+=arr[r];
    maxSum=max(maxSum, sum);
  }
  return maxSum;
}
int main(){
  int arr[]={12, 3, 15, 10, 6, 8, 4, 1, 12, 9, 14, 18, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int maxnum=3;
  cout<<ConstantWindow(arr, n, maxnum);
return 0;
}