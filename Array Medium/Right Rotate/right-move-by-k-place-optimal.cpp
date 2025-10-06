#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   int arr[]={8, 6,2, 10, 15, 17};
   int k=2;
   int n=sizeof(arr)/sizeof(arr[0]);
   reverse(arr+n-k, arr+k);
   reverse(arr, arr+n-k);
   reverse(arr, arr+n);



  for(int i=0;i<n;i++){
   cout<<arr[i]<<" "; 
  }
return 0;
}