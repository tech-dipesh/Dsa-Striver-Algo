#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>nextSmallerElement(vector<int>arr){
  vector<int>vt;
  stack<int>st;
  for(int i=0;i<arr.size();i++){
      while(st.size() && st.top()>arr[i]){
        st.pop();
      }
      if(st.empty()){
        vt.push_back(-1);
      }
      else{
        vt.push_back(st.top());
      }
      st.push(arr[i]);
  }
  return vt;
}
int main(){
   vector<int>arr={4, 5, 2, 10, 8};
  //  Res: -1, 4, -1, 2, 2
  vector<int>vt=nextSmallerElement(arr);
  for(int i:vt){
    cout<<i<<" ";
  }
return 0;
}