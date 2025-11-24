#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>monotonicStack(vector<int>arr){
  vector<int>vt;
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
    // When next eleemtn is not greater:
    while(st.size() && arr[i]>=st.top()){
      st.pop();
    }
    // First element:
    if(st.empty()){
      vt.push_back(-1);
    }
    else{
      vt.push_back(st.top());
    }
    st.push(arr[i]);
  }
  reverse(vt.begin(), vt.end());
  return vt;
}
int main(){
  vector<int>arr={4, 1, 5, 5, 3, 1, 2, 5,3, 1, 2, 4, 6};
  // Result: 5, 5, 6, 6, 4, 2, 3, 6, 4, 2, 4, 6
  vector<int>vt=monotonicStack(arr);
  for(int i:vt){
    cout<<i<<" ";
  }
return 0;
}