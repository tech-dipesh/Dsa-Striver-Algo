#include <iostream>
#include <unordered_map>
using namespace std;

int largest0Sum(int arr[], int n){
  int sum=0, maxelementindex=0;;
  unordered_map<int, int>mp;
  for(int i=0;i<n;i++){
   sum+=arr[i];
   if(sum==0){
    maxelementindex=i+1;
   }
   else{
    if(mp.find(sum)!=mp.end()){
      // as on the 2, 1, -2, -1: -1 index can be subtract with the 2 index whih is : 3-0, 3.
      maxelementindex=max(maxelementindex, i-mp[sum]);
    }
    else{
      mp[sum]=i;
    }
   }
  }
  return sum;
}

// My Approach:
// first in the each time we'll do the sum eachi iterator.
// with 15+-9 on now check is that sum becomes the 0 only perform the steps otherwise just add this each value on 



int main(){
  // input example with the both positive and negative also there is naive solution but we can use the optimal solution with the hashset:
  int arr[]={15, -9, 6, 2, 1, -2, 2, -8, 1, 7, 10, 23};
  
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<"First Test "<<largest0Sum(arr, size)<<endl;


  int leetcode1[]={-2, 2, -8, 1, 7};
  int leetcodesize=sizeof(leetcode1)/sizeof(leetcode1[0]);
  cout<<"First leetcode answwer is: "<<largest0Sum(leetcode1, leetcodesize)<<endl;
return 0;
}