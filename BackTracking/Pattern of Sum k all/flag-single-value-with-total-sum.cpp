#include <iostream>
#include <vector>
using namespace std;

bool flag=false;
void Sum(int arr[], int i, int n, int k, int sum, vector<int>vt){
  // Base case:
  if(i==n){
      if(k==sum && flag==false){
          for(int i:vt){
            cout<<i<<" ";
          }
          flag=true;
          cout<<endl;
      }
      return;
  }
  //Take:
  vt.push_back(arr[i]);
  sum+=arr[i];
  Sum(arr, i+1, n, k, sum, vt);

  // During Returning Time:
  vt.pop_back();
  sum-=arr[i];
  // Not Take:
  Sum(arr, i+1, n, k, sum, vt);
}

int main(){
   int arr[]={1, 2, 2, 1, 3};
   vector<int>vt;
   int n=sizeof(arr)/sizeof(arr[0]);
   int sum=0, k=3, i=0;
  Sum(arr, i, n, k, sum, vt);
return 0;
}