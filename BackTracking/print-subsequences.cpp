// The subsequences can be contigious or non contigious sequence which follows the order.
// make sure the it follows the order of the array we can't just do first make the last and second make the first element from the array.

// The most important is take and non take on this kind of pattern.
#include <iostream>
#include <vector>
using namespace std;

void subSequence(int arr[], vector<int>&vt, int n, int i){
  if(i>=n){
    // cout<<arr[i];
    for(int i:vt){
      cout<<i<<" ";
    }

    if(vt.size()==0){
      cout<<"{}";
    }
    cout<<endl;
    return ;
  }
  // First take the element
  vt.push_back(arr[i]);
  subSequence(arr, vt, n, i+1);
  // Take back the element.
  vt.pop_back();
  subSequence(arr, vt, n, i+1);
}
int main(){
    // Subarray can be the subsequence, a:
  // int arr[]={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  int arr[]={2, 3, 4};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i=0;
  vector<int>vt;
  // vector<int>res={subSequence(arr, n, i)};
  subSequence(arr, vt,  n, i);
  
return 0;
}