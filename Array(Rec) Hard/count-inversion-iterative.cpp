#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>countInversion(int arr[], int n){
  vector<vector<int>>res;
  for(int i=0;i<n-1;i++){
    vector<int>vt;
  for(int j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
          vt.push_back(arr[i]);
          vt.push_back(arr[j]);
      }
  }
    if(vt.size()){
      res.push_back(vt);
    }
  }
  return res;
}
int main(){
   int arr[]={5, 3, 2, 4, 1};
   int n=sizeof(arr)/sizeof(arr[0]);
    // Return an element: (5, 3) (5, 2) (5, 4), (5, 1), (3, 2) (3, 1) (4, 1).

    // The condition are: i<j and arr[i]>arr[j].
    vector<vector<int>>res=countInversion(arr, n);
    for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
    }
return 0;
}