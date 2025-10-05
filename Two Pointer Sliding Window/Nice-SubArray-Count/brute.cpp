#include <iostream>
using namespace std;
  
int niceSubarray(int arr[], int n, int k){
  int maxSum=0;
  for(int i=0;i<n;i++){
    int sum=0;
  for(int j=i;j<n;j++){
    // just convert each to 1 and 0 very simple:
    sum+=arr[j]%2;
    if(sum==k){
      maxSum++;
    }
   else if(sum>k){
    break;
   }
  }
  }
  return maxSum;
}
int main(){
  int arr[]={ 1, 1, 2, 1, 1};
  int k=3;
  int n=sizeof(arr)/sizeof(arr[0]);
  int a1[]={2, 1, 1, 1, 2, 1};
  int k1=3;
  int n1=sizeof(a1)/sizeof(a1[0]);



  int ar[]={1, 2, 3, 5, 1, 3, 8, 7, 3, 53, 2, 82, 52, 62, 42, 35, 82};
  int n2=sizeof(ar)/sizeof(ar[0]);
  int k2=3;

  int leetcode[]={2,2,2,1,2,2,1,2,2,2};
  int leetcodesize=sizeof(leetcode)/sizeof(leetcode[0]);
  int leetcodek=2;
  
  cout<<"Nice subarray is: "<<niceSubarray(arr, n, k)<<endl;
  cout<<"Nice subarray/ is: "<<niceSubarray(a1, n1, k1)<<endl;
  cout<<"Nice subarray/ is: "<<niceSubarray(ar, n2, k2)<<endl;
  cout<<"Leetcode Subarray is: "<<niceSubarray(leetcode, leetcodesize, leetcodek)<<endl;
return 0;
}