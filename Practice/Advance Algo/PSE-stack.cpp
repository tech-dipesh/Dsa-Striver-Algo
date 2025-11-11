#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int>previousSmallerElement(int arr[], int n){
  vector<int>vt;
  stack<int>st;
  for(int i=n-1;i>=0;i--){
   while(st.size() && st.top()>arr[i]){
    st.pop();
   }
   if(st.empty()){
    vt.push_back(arr[i]);
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
   int arr[]={3, 1, 2, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
   vector<int>res=previousSmallerElement(arr, n);
   for(int i:res){
    cout<<i<<" ";
   }
return 0;
}