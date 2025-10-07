// optimal solution can't be the, longest subaray only maxLen can be the possible:
// this tc: o(n), while better solution have: o(2n) due to using two while loop.
#include <iostream>
#include <vector>
using namespace std;

vector<int>ConstantWindow(int arr[], int n, int k){
  int l=0, r=0;
  int maxStart=0, maxEnd=0, sum=0;
  vector<int>res;
  while(r<n){
    sum+=arr[r];
    if(sum>k){
      sum-=arr[l];
      l++;
    }
    if(sum<=k){
      maxStart=max(maxStart, l);
      maxEnd=max(maxEnd, r);
      r++; 
    }
  }
  for(int i=maxStart-1;i<=maxEnd;i++)
    res.push_back(arr[i]);
  return res;
}
int main(){
  int arr[]={12, 3, 15, 10, 6, 8, 4, 1, 12, 9, 14, 18, 6};
  int n=sizeof(arr)/sizeof(arr[0]);
  int maxnum=35;
  vector<int>res=ConstantWindow(arr, n, maxnum);
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
return 0;
}