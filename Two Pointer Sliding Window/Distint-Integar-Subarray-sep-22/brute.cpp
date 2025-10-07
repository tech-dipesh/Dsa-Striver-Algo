#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
    
int maxSubarrayDistintIntegar(int arr[], int n, int k){
  int maxValue=0, count=0;
  for(int i=0;i<n;i++){
    set<int>st;
  for(int j=i;j<n;j++){
      // hash[arr[j]]++;
      st.insert(arr[j]);
      if(st.size()==k){
          count++;
      }
      else if(st.size()>k){
        break;

      }
  }
  }
return count;
}
int main(){
  int a[]={1, 2, 1, 3, 4};
  int arr[]={5, 4, 7, 2, 5, 3};
  int arr1[]={2, 1, 1, 3,  4, 3, 2};
  int k=3;
  

  int size=sizeof(a)/sizeof(a[0]);
  cout<<"Distint integar Subarray is: "<<maxSubarrayDistintIntegar(a, size, k);
  // on the 2113432 with given 3 these are the substring that we can generate:
  // 2 1 1 3, 1 3 4, 1 1 3 4, 3 4 3 2, 4 3 2.
  // 1         2       3       4         5
  // final output is: 5


  int k1=3;

  // result should be either 3 or 4 all generated subarray are from the given distrint values but not more that that:
  // 1 2 1 3, 1 3 4, 2 1 3, 
return 0;
}