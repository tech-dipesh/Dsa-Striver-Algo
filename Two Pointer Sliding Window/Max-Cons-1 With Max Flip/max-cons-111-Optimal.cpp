#include <iostream>
using namespace std;

int MaxOne(int arr[], int n, int k)
{
  int left=0, right=0, count=0, maxLength=0;
  while(right<n){
    if(arr[right]==0){
      count++;
    }
    if(count>k){
      if(arr[left]==0){
        count--;
      }
      left++;
     }
     if(count<=k){
       maxLength=max(maxLength, right-left+1);
     }
    right++;
  }
  return maxLength;
}

int main(){
  int arr[] = {1, 0, 1, 1, 0, 0, 1};
  int arrn = sizeof(arr) / sizeof(arr[0]);
  int k = 2;
  int a1[] = {1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1};
  int a1n = sizeof(a1) / sizeof(a1[0]);
  int a2[] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0};
  int n2 = sizeof(a2) / sizeof(a2[0]);
  int k2 = 4;
  cout << "Max one flip is: "<<MaxOne(arr, arrn, k)<<endl;
  cout << "Max one flip is: " << MaxOne(a1, a1n, k) << endl;
  cout << "Max one flip is: " << MaxOne(a2, n2, k2) << endl;

  return 0;
}