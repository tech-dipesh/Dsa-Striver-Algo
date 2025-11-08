// The approach is for the recursive:
// First implemenet the merge sort and during return back that the eleement will be on the sorted order on every call, so we can just keep have the sorted element , as j>i that mean the j rest of the element will alwasy be so don't need further checks. 
#include <iostream>
#include <vector>
using namespace std;

int count=0;
void mergeTwoSortedArray(vector<vector<int>>&res, int arr[], int n, int low, int medium, int high){
  int left=low, right=medium;
  vector<int>vt;
    while(left<=medium & right<=high){
      if(arr[left]<=arr[right]){
            vt.push_back(arr[left++]);
        }
        else{
          // any point left side sorted array have bigger element that mean rest of the left side element with teh right side will be inversion.
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
}

void MergeSort(int low, int high, vector<vector<int>>&res, int arr[], int n){
  if(low==high){
    return;
  }
  int medium=(low+high)/2;
  MergeSort(low, medium, res, arr, n);
  MergeSort(medium+1, high, res, arr, n);
  mergeTwoSortedArray(res, arr, n, low, medium, high);
}
int countInversion(int arr[], int n){
  vector<vector<int>>res;
    vector<int>vt;
    int low=0, high=n-1;
  MergeSort(low, high, res, arr, n);
  return count;
}
int main(){
   int arr[]={5, 3, 2, 4, 1};
   int n=sizeof(arr)/sizeof(arr[0]);
    // Return an element: (5, 3) (5, 2) (5, 4), (5, 1), (3, 2) (3, 1) (4, 1).
    // The condition are: i<j and arr[i]>arr[j].
    int res=countInversion(arr, n);
    // for(int i=0;i<res.size();i++){
    // for(int j=0;j<res[i].size();j++){
    //     cout<<res[i][j]<<" ";
    // }
    // cout<<endl;
    // }
    cout<<res;
return 0;
}