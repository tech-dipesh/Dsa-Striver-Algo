#include <iostream>
using namespace std;
    
// we can take from the both left and right first with from left to till right lat element;
int Point(int arr[], int n, int k){
  int leftSum=0, rightSum=0, maxSum=0;
  for(int i=0;i<k;i++){
    leftSum+=arr[i];
  }
  maxSum=leftSum;
  int i=k-1, j=n-1;
  while(i>=0 &&j>=0){
    leftSum-=arr[i--];
    rightSum+=arr[j--];
    if(i==0){
       maxSum=max(maxSum, rightSum);
    }
    else{
      maxSum=max(maxSum, leftSum+rightSum);
    }
  }
  return maxSum;
}
int secondPoint(int arr[], int n, int k){
    int leftSum=0, rightSum=0, maxSum=0;
  for(int i=0;i<k;i++){
      leftSum+=arr[i];
  }
  maxSum=leftSum;
  int j=n-1;
  for(int i=k-1;i>=0;i--){
      leftSum-=arr[i];
      rightSum+=arr[j];
      j--;
      maxSum=max(maxSum, leftSum+rightSum);
  }
  return maxSum;
}

int main(){
  int arr[]={6, 2, 3, 4, 7, 2, 1, 7, 1};
  int k=4;
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"Max Point can obtain is: "<<Point(arr, n, k)<<endl;
  cout<<"Another Way of getting Max point is: "<<secondPoint(arr, n, k);
  // Point(arr, n, k);
return 0;
}