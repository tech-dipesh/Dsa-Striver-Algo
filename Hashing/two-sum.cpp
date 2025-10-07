#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;


vector<int>twoSum(int arr[], int n, int target){
// vector<int> twoSum(int arr[], int n, int target){
  // vector<int>res;
  // int res[2];
  unordered_map<int, int>mp;
  for(int i=0;i<n;i++){
    int sub=target-arr[i];
    if(mp.find(sub)!=mp.end()){
      // example is: i become, 5 index: 2, and now mp[2], so mp index 2 have value of: 0 which is the indesx 
      int firsthashmapindex=mp[arr[sub]];
      return {i, firsthashmapindex};
      // res.push_back(i);
      // res.push_back(nextvalue);
      // return res;
    }
    mp[arr[i]]=i;
  }
  // return res;
  return {};
}

int main(){
  int arr[]={2, 8, 5, 3, 9, 11, 4};
  int target=7;
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<twoSum(arr, size, target);
}