#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int>astroidCollision(vector<int>arr, int n) {
  stack<int>st;
  for(int i = 0;i < n;i++) {
    if(arr[i] > 0) {
      st.push(arr[i]);
    }
    else{
      while(st.size() && st.top() >0 &&  st.top()<abs(arr[i])){
          st.pop();
      }
      if(st.size() && abs(st.top()==arr[i])){
        st.pop();
      }
      else if(st.empty() || st.top()<0){
        st.push(arr[i]);
      }
    }
  }
  vector<int>res;
  while(st.size()){
    res.push_back(st.top());
    st.pop();
  }
  return res;
}
int main() {
  vector<int>vt = { 4, 7, 1, 1, 2, -3, -7, 17, 15, -16 };
  int n=vt.size();
  //  Final Result is: 4, 17;
  vector<int>res=astroidCollision(vt, n);
  for(int i:res){
    cout<<i<<" ";
  }
  return 0;
}