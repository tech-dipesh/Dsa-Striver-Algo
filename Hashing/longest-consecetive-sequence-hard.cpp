#include <iostream>
#include <set>
using namespace std;

int longestSubSequence(int arr[], int n){
  int maxVal=0, res=0;
  set<int>st;

  // inserting the each element onto the set:
  for(int i=0;i<n;i++){
    st.insert(arr[i]);
  }

  for(int i=0;i<n;i++){
    // if arr is 99 it will check 98 exist or not.
    if(!st.count(arr[i]-1)){
      int j=i;
        // while(st[arr[j]]+1){
        // do until that next subsequent elemtn not found.
        while(st.count(j+1)){
            // maxVal=st[arr[j]]-st[arr[i]];
          maxVal++;
            j++;
        }
        res=max(res, maxVal);
      }
  }
  return res;
}


int main(){
  int arr[]={9, 97, 7, 3, 99, 1, 8, 98, 6};
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<longestSubSequence(arr, size);
return 0;
}