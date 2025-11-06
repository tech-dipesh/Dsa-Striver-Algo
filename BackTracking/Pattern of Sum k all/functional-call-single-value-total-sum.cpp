#include <iostream>
#include <vector>
using namespace std;

bool Sum(int arr[], int i, int n, int k, int sum, vector<int>vt){
  // Base case:
  if(i==n){
      if(sum==k){
          for(int i:vt){
            cout<<i<<" ";
          }
          cout<<endl;
          return true;
      }
      // That call is not have element
      else{
        return false;
      }
      // return;
  }
  //Take:
  vt.push_back(arr[i]);
  sum+=arr[i];
  if(Sum(arr, i+1, n, k, sum, vt)==true){
    return true;
  }

  // During Returning Time:
  vt.pop_back();
  sum-=arr[i];
  // Not Take:
  if(Sum(arr, i+1, n, k, sum, vt)==true){
    return true;
  }
  return false;
}

int main(){
   int arr[]={1, 2, 2, 1, 3};
   vector<int>vt;
   int n=sizeof(arr)/sizeof(arr[0]);
   int sum=0, k=3, i=0;
  cout<<Sum(arr, i, n, k, sum, vt);
return 0;
}