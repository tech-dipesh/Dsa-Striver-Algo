#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int trappingrainWater(int arr[], int n){
  int totalWater=0;
  int leftMax=0, rightMax=0;
  int left=0, right=n-1;
  while(left<right){
    if(arr[left]<=arr[right]){
      // That mean have the higer on the left side:
      if(leftMax>arr[left]){
        totalWater+=leftMax-arr[left];
      }
      else{
        leftMax=arr[left];
      }
      left++;
    }
    else{
      if(rightMax>arr[right]){
        totalWater+=rightMax-arr[right];
      }
      else{
        rightMax=arr[right];
      }
      right--;
    }
  }
    return totalWater;
}
int main(){
  int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  //  Res: 6: by: (1, 2): 1 (2, 1): 1, (2, 1): 1, (2, 3): 2, (2, 1): 1=1+1+1+2+1=6
  int n=sizeof(arr)/sizeof(arr[0]);
  int arr1[]={2, 1, 0, 1, 3};
  //  Res: 6: by: (1, 2): 1 (2, 1): 1, (2, 1): 1, (2, 3): 2, (2, 1): 1=1+1+1+2+1=6
  int n1=sizeof(arr1)/sizeof(arr1[0]);
  cout<<trappingrainWater(arr, n)<<endl;
  cout<<trappingrainWater(arr1, n1)<<endl;
return 0;
}