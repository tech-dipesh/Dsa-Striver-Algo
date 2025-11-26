// WE've to find out the range that on each that with subtracting greaterValue to smallerValue can get the each value of the range.
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int>previousGreateElement(int arr[], int n){
  vector<int>vt;
  stack<int>st;
  for(int i=n-1;i>=0;i--){
   while(st.size() && st.top()<arr[i]){
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
vector<int>nextGreaterElement(int arr[], int n){
  vector<int>vt;
  stack<int>st;
  for(int i=0;i<n;i++){
    while(st.size() && st.top()<arr[i]){
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
    vt.push_back(arr[i]);
  }
  return vt;
}
vector<int>nextSmallerElement(int arr[], int n){
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
int sumAllSubarrayMinimum(int arr[], int n){
  vector<int>NSE=nextSmallerElement(arr, n);
  vector<int>PSE=previousSmallerElement(arr, n);
  vector<int>NGE=nextGreaterElement(arr, n);
  vector<int>PGE=previousGreateElement(arr, n);
  int sum=0, mod=(int)(1e9+7);
  int SmallerSum=0, GreaterSum=0;
  for(int i=0;i<n;i++){
    {
      // This for the smaller Sum:
      int leftside=i-PSE[i];
      int rightSide=NSE[i]-i;
      SmallerSum+=(leftside*rightSide)*arr[i]%mod;
    }
    {
      // This for the Greater Sum:
      int leftside=i+PGE[i];
      int rightSide=NGE[i]+i;
      GreaterSum+=(leftside*rightSide)*arr[i]%mod;
    }
  }
  return (GreaterSum-SmallerSum)%mod;
}

int main(){
   int arr[]={3, 1, 2, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
   //  All subarray: ((3) (3, 1), (3, 1, 2), (3, 1, 2, 4)): ((1) (1, 2) (1, 2, 4)) : ((2) (2, 4)): (4):
   // First: 3+1+1+1:1+1+1:2+2:4=17
   int arr1[]={1, 4, 6, 7, 3, 7, 8};
   int n1=sizeof(arr1)/sizeof(arr1[0]);
   int arr2[]={4, 2, 1, 3, 6, 2};
   int n2=sizeof(arr2)/sizeof(arr2[0]);
  cout<<sumAllSubarrayMinimum(arr, n)<<endl;
  cout<<sumAllSubarrayMinimum(arr1, n1)<<endl;
  cout<<sumAllSubarrayMinimum(arr2, n2)<<endl;
return 0;
}