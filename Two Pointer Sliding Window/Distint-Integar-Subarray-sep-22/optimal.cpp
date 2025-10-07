#include <iostream>
#include <unordered_map>
using namespace std;
    
int maxSubarrayDistintIntegar(int arr[], int n, int k){
  int maxValue=0, left=0, right=0, count=0;
  unordered_map<int, int>mp;
  while(right<n){
    mp[arr[right]]++;
    while(mp.size()>k){
      mp[arr[left]]--;
      if(mp[arr[left]]==0){
        mp.erase(mp[left]);
      }
      left++;
    }
    count+=right-left+1;
    right++;
  }

return count;
}
int main(){
  int a[]={1, 2, 1, 3, 4};
  int size=sizeof(a)/sizeof(a[0]);
  int arr1[]={5, 4, 7, 2, 5, 3};
  int size1=sizeof(arr1)/sizeof(arr1[0]);
  int arr2[]={2, 1, 1, 3,  4, 3, 2};
  int size2=sizeof(arr1)/sizeof(arr1[0]);
  int k=3;
  int k1=2;
  
  // on the 2113432 with given 3 these are the substring that we can generate:
  // 2 1 1 3, 1 3 4, 1 1 3 4, 3 4 3 2, 4 3 2.
  // 1         2       3       4         5
  // final output is: 5
  cout<<"final output of the three string is: "<<maxSubarrayDistintIntegar(a, size, k)<<endl;
  cout<<"final output of the two string is: "<<maxSubarrayDistintIntegar(arr1, size1, k1)<<endl;
  cout<<"final output of the three string is: "<<maxSubarrayDistintIntegar(arr1, size2, k)<<endl;


  // result should be either 3 or 4 all generated subarray are from the given distrint values but not more that that:
  // 1 2 1 3, 1 3 4, 2 1 3, 
return 0;
}