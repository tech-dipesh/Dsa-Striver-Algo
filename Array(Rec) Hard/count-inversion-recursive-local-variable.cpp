// The approach is for the recursive:
// First implemenet the merge sort and during return back that the eleement will be on the sorted order on every call, so we can just keep have the sorted element , as j>i that mean the j rest of the element will alwasy be so don't need further checks. 
#include <iostream>
#include <vector>
using namespace std;

int mergeTwoSortedArray(int arr[], int n, int low, int medium, int high){
  int count=0;
  int left=low, right=medium;
  vector<int>vt;
    while(left<=medium & right<=high){
      if(arr[left]<=arr[right]){
            vt.push_back(arr[left++]);
        }
        else{
          // where (5, 7, 9), (4, 6) where 5.4 that mean 7 and 9 also being the inversion.
          count+=(right-left+1);
          vt.push_back(arr[right++]);
        }
    }

    // There is some value still exist.
    while(left<=medium){
      vt.push_back(arr[left++]);
    }
    while(right<=high){
      vt.push_back(arr[right++]);
    }


    // Move back to original array:
    for(int i=low;i<high;i++){
        arr[i]=vt[i-low];
    }
    return count;
}

int MergeSort(int low, int high, int arr[], int n){
  int count=0;
  if(low==high){
    return count;
  }
  int medium=(low+high)/2;
  count+=MergeSort(low, medium, arr, n);
  count+=MergeSort(medium+1, high, arr, n);
  count+=mergeTwoSortedArray(arr, n, low, medium, high);
  return count;
}
int countInversion(int arr[], int n){
    vector<int>vt;
    int low=0, high=n-1;
  return MergeSort(low, high, arr, n);
}
int main(){
   int arr[]={5, 3, 2, 4, 1};
   int n=sizeof(arr)/sizeof(arr[0]);
    // Return an element: (5, 3) (5, 2) (5, 4), (5, 1), (3, 2) (3, 1) (4, 1).
    // The condition are: i<j and arr[i]>arr[j].
    int res=countInversion(arr, n);
    cout<<res;
return 0;
}