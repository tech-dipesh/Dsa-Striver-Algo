// The Approach is first divide, keep divide until it doesn't become single element, after single element make them merge together in sorted order.

#include <iostream>
#include <vector>
using namespace std;




void Display(int arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}
int main(){
   int arr[]={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
   int n=sizeof(arr)/sizeof(arr[0]);
   int low=0, high=n-1;
   MergeSort(arr, n, low, high); 
return 0;
}