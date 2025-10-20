#include <iostream>
using namespace std;

void Rev(int arr[], int i, int n){
  if(i>=n/2){
    return;
  }
  swap(arr[i], arr[n-i-1]);
  Rev(arr, i+1, n);
}
int main(){
  int arr[]={2, 4, 5, 7, 9};
  int n=sizeof(arr)/sizeof(arr[0]);
   int i=0;
   Rev(arr, i, n);

   for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
   }
return 0;
}