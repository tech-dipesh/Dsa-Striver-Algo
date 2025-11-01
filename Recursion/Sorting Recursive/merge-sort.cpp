// The Approach is first divide, keep divide until it doesn't become single element, after single element make them merge together in sorted order.
#include <iostream>
#include <vector>
using namespace std;

void MergeTwoArray(int arr[], int low, int middle, int high){
    int left=low, right=middle+1;
    vector<int>newArray;
    // int i=0, j=midd, k=0;
    while(left<=middle & right<=high){
      if(arr[left]<=arr[right]){
            // newArray[i++]=arr[left++];
            newArray.push_back(arr[left++]);
        }
        else{
          newArray.push_back(arr[right++]);
        }
    }

    // There is some value still exist.
    while(left<=middle){
      newArray.push_back(arr[left++]);
    }
    while(right<=high){
      newArray.push_back(arr[right++]);
    }


    // Move back to original array:
    for(int i=low;i<=high;i++){
        arr[i]=newArray[i-low];
    }
}

void MergeSort(int arr [], int n, int low, int high){
  if(low==high)return;
  int middle=(low+high)/2;
  // Left Portion of the Divide:
  MergeSort(arr, n, low, middle);
  MergeSort(arr, n, middle+1, high);

  MergeTwoArray(arr, low, middle, high);
}

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
   Display(arr, n);
return 0;
}