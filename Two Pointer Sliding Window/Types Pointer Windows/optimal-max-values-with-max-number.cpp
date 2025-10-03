#include <iostream>
using namespace std;

int MaxValueObtainFromNumber(int arr[], int n, int k){
  int left=0, right=0, maxVAlue=0, sum=0;
  while(right<n){
    if((right-left+1)>k){
      sum-=arr[left];
      left++;
    }
    sum+=arr[right];
    if((right-left+1)==k){
        maxVAlue=max(maxVAlue, sum);
    }
    right++;
  }
  return maxVAlue;
}
int main(){
  int arr[]={2, 8, 4, 6, 12, 34, 12, 14, 19, 11, 21, 7, 9};
  int maxnumber=4;
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<"Most Optimal Solution of the max value that we can obtain: "<<MaxValueObtainFromNumber(arr, size, maxnumber);
return 0;
}