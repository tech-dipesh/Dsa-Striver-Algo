// This becomes the, 2^n*kl0gn
#include <bits/stdc++.h>
using namespace std;
void Sum(int i, int sum, int target, int arr[], int n, vector<vector<int>>&vt, vector<int>&each){
  if(i==n){
      if(target==0){
        vt.push_back(each);
      }
      return;
  } 
  if(arr[i]<=target){
    // Take
    each.push_back(arr[i]);
    Sum(i+1, sum, target-arr[i], arr, n, vt, each);
    // Non Take
    each.pop_back();
  } 
  
  Sum(i+1, sum, target, arr, n, vt, each);
}

vector<vector<int>>CombinationSum(int i, int sum, int target, int arr[], int n){
  vector<vector<int>>vt;
  vector<int>each;
  Sum(i, sum, target, arr, n, vt, each);
  return vt;
}

int main(){
  int arr[]={2, 3, 5, 1, 6, 3, 7, 1};
  int n=sizeof(arr)/sizeof(arr[0]), target=6,sum=0;
  vector<vector<int>>res=CombinationSum(0, sum, target, arr, n);
  for(int i=0;i<res.size();i++){
   for(int j=0;j<res[i].size();j++){
     cout<<res[i][j]<<" ";
  }
  cout<<endl;
  }
return 0;
}