#include <iostream>
#include <set>
#include <vector>
using namespace std;
void Sum(int i, int initialSum, int arr[],int sum, int n, vector<int>vt){
  if(i==n){
    if(initialSum==sum){
      // cout<<arr[i];
      for(int i:vt){
        cout<<i<<" ";
      }
      cout<<endl;
    }
    return;
  }

  // Pick Case:
  initialSum+=arr[i];
  vt.push_back(arr[i]);
  Sum(i+1, initialSum, arr, sum, n, vt);
  
  vt.pop_back();
  initialSum-=arr[i];

  // Not Pick Case:
  Sum(i+1, initialSum, arr, sum, n, vt);
  
}
int main(){
   int arr[]={1, 2, 3, 2, 1, 2, 3};
   int n=sizeof(arr)/sizeof(arr[0]);
   int i=0;
   int sum=3, initialSum=0;
   vector<int>vt;
   Sum(i, initialSum,  arr, sum, n, vt); 
return 0;
}