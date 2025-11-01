// There can be the possiblity of pick a first index from 0th to nth index, first we've to sort then only prepraring for the recursion.
#include <bits/stdc++.h>
using namespace std;
void Sum(int i, int sum, int target, vector<int>arr, int n, vector<vector<int>>&vt, vector<int>&each){
  if(target==0){
    vt.push_back(each);
    return;
  }
  for(int j=i;j<arr.size();j++){
      if(arr[j]==arr[j-1])continue;
      if(target<arr[j])break;
      
      // Pick Recursion Call:
      each.push_back(arr[j]);
      Sum(j+1, sum, target-arr[j], arr, n, vt, each);
      // Non Pick
      each.pop_back();
    }
}

vector<vector<int>>CombinationSum(int i, int sum, int target, vector<int>arr, int n){
  sort(arr.begin(), arr.end());
  vector<vector<int>>vt;
  vector<int>each;
  Sum(i, sum, target, arr, n, vt, each);
  return vt;
}

int main(){
  vector<int>arr={2, 3, 5, 1, 6, 3, 7, 1};
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