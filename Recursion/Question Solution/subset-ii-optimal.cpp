// The most important is take and non take on this kind of pattern.
//Most Not contain duplicate:
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void subSetII(int i, int arr[], int n, vector<int>&vt, set<vector<int>>&res){
  if(i==n){
    if(vt.size()==0){
      cout<<"{} ";
    }
    res.insert(vt);
    return ;
  }
  for(int j=i;j<n;j++){
      vt.push_back(arr[i]);
      subSetII(i+1, arr, n, vt, res);
      vt.pop_back();
    }
    
    // Take Back:
    subSetII(i+1, arr, n, vt, res);
}

set<vector<int>>subSequence(int arr[], int n){
  vector<int>vt;
  set<vector<int>>res;
  subSetII(0, arr, n, vt, res);
  return res;
}

int main(){
  int arr[]={1, 2, 2};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i=0;
  set<vector<int>>res=subSequence(arr, n);

  for(auto i:res){
    for(int j:i){
      cout<<j<<" ";
    }
  }
return 0;
}