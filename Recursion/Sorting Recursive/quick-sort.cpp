// The Simple Approach is:
// pick a pivot (we'll be taking first)
// place to correct place
// move smaller to left and larger to right:

#include <iostream>
using namespace std;

// we'll be picking the pivot from the low value.
int PartitionSwap(int arr[], int low, int high){
   int pivot=arr[low];
  int i=low, j=high;
  while(i<j){
    // i also have to chekc i<high as that can be go out of bound inside loop three time.
      while(pivot>=arr[i] && i<=high){
          i++;
      }
      while(pivot<arr[j] && j>low){
        j--;
      }
      if(i<j){
        swap(arr[i], arr[j]);
      }
  }
  // swap with the first  but really dont' understad as pivito also a same as on low value then why it's not working.
  swap(arr[low], arr[j]);
  return j;
}


void QuickSort(int arr[], int low, int high){
  if(low<high){
   int PartiotionIndex=PartitionSwap(arr, low, high);
    QuickSort(arr, low, PartiotionIndex-1);
    QuickSort(arr, PartiotionIndex+1, high);
  }
}


// for picking the number that's on correct place we'll be taking low and high and if the high is smaller we just keep swaping and last element we'll be placed the pivot.  
// now it will have smaller on left and bigger on right automatically.


// now we can call the partition element where the both directional have the same smaller and bigger.

int main(){
  int arr[]={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  int n=sizeof(arr)/sizeof(arr[0]);
  QuickSort(arr,0,n-1); 
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
return 0;
}