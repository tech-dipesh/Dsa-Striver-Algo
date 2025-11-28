#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int>nextSmallerElement(vector<int>arr, int n){
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
    vt.push_back(arr[i]);
  }
  return vt;
}
vector<int>previousSmallerElement(vector<int>arr, int n){
  vector<int>vt;
  stack<int>st;
  for(int i=0;i<n;i++){
    while(st.size() && st.top()>arr[i]){
      st.pop();
    }
    if(st.empty()){
      vt.push_back(arr[i]);
    }
    else{
      vt.push_back(st.top());
    }
    vt.push_back(arr[i]);
 }
  return vt;
}

int largeHistogram(vector<int>vt, int n){
  vector<int>NSE=nextSmallerElement(vt, n);
  vector<int>PSE=previousSmallerElement(vt, n);
  int maxHistogram=0;
  for(int i=0;i<n;i++){
    int eachHistogram=vt[i]*(NSE[i]-PSE[i]-1);
     maxHistogram=max(maxHistogram, eachHistogram);
  }
  return maxHistogram;
}
int main(){
    vector<int>arr={2, 1, 5, 6, 2, 3};
    int n=arr.size();
    cout<<largeHistogram(arr, n);
return 0;
}