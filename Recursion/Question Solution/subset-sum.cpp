// There can be the possiblity of pick a first index from 0th to nth index, first we've to sort then only prepraring for the recursion.
#include <bits/stdc++.h>
using namespace std;
void SubSum(int i, int sum, vector<int>&arr, vector<int>&vt, int n){
  if(i==n){
      vt.push_back(sum);
    return;
  }
  // Pick Approach:
  SubSum(i+1, sum+arr[i], arr, vt, n);

  // Not Pick:
  SubSum(i+1, sum, arr, vt, n);
}

vector<int>EachSum(vector<int>arr, int n) {
  vector<int>vt;
  SubSum(0, 0, arr, vt, n);
  return vt;
}

int main() {
  vector<int>arr = { 2, 3, 5, 1, 6, 3, 7, 1 };
  int n=arr.size();
  vector<int>vt=EachSum(arr, n);
  sort(vt.begin(), vt.end());
  for(int i : vt) {
    cout << i << " ";
  }
  return 0;
}