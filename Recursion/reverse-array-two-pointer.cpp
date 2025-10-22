#include <iostream>
using namespace std;

void Rev(int arr[], int i, int j){
  if(i>=j){
    return;
  }
  swap(arr[i], arr[j]);
  Rev(arr, i+1, j-1);
}
int main(){
   int arr[]={2, 4, 5, 7, 9};
   int n=sizeof(arr)/sizeof(arr[0]);
   int i=0, j=n-1;
   Rev(arr, i, j);

   for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
   }
return 0;
}