#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>monotonicStack(vector<int>arr){
  vector<int>vt;
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
     while(st.size() && arr[i]>=st.top()){
        st.pop();
     }
     if(st.empty()){
      int j=0;
      int Great=-1;
      while(j<i && Great==-1){
        if(arr[i]<arr[j]){
          Great=arr[j];
        }
        j++;
      }
      vt.push_back(Great);
     }
     else {
      vt.push_back(st.top());
     }
     st.push(arr[i]);
    }
    reverse(vt.begin(), vt.end());
  return vt;
}

int main(){
  vector<int>arr={2, 10, 12, 1, 11};
  vector<int>arr1={6, 0, 8, 1, 3};
  // Result: 10, 12, -1, 1, 11
  vector<int>vt=monotonicStack(arr);
  for(int i:vt){
    cout<<i<<" ";
  }
  cout<<endl;
  vector<int>vt1=monotonicStack(arr1);
  for(int i:vt1){
    cout<<i<<" ";
  }
return 0;
}