#include <iostream>
using namespace std;

  void PartionSort(int A[], int low, int mid, int high){
    int i, j, k;
    i=low, j=mid+1, k=low;
    int B[100];
    while(i<=mid &&j<=high){
      if(A[i]<A[j])
       B[k++]=A[i++];
      else B[k++]=A[j++];
    }
    while(i<=mid)
      B[k++]=A[i++];
    while(j<=high)
      B[k++]=A[j++];
      // send back to the original array:
      for(i=low;i<=high;i++){
          A[i]=B[i];
      }
  }

  void RecursiveMergeSort(int A[],  int low, int high){
    int mid;
    if(low<high){
      mid=(low+high)/2;
      RecursiveMergeSort(A, low, mid);
      RecursiveMergeSort(A, mid+1, high);
      PartionSort(A, low, mid, high);
    }
  }
int main(){
    int arr[]={0, 1, 0, 0, 1, 2, 0, 1, 0, 2, 0, 2, 0, 2, 0, 2, 1, 0, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0, high=n-1;
    RecursiveMergeSort(arr, low, high);
    

    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }

return 0;
}