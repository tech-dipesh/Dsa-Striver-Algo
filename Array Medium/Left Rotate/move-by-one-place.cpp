#include <iostream>
using namespace std;
int main(){
   int arr[]={2, 5, 7, 9, 6, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
  //  final output should be: 5 7 9 6 4 2
  int first=arr[0];
   for(int i=1;i<n;i++){
    arr[i-1]=arr[i];
   }
   arr[n-1]=first;

   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
return 0;
}