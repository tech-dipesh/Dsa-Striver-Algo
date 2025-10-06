
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   int arr[]={2, 5, 7, 9, 6, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
   int k=2;
  //  final output should be: 5 7 9 6 4 2

  // we can just reverse the k element and again reverse the elemnt from k tolast that become: 5 2 and 4 6 9 7 then then if we just reverse this it become: 7 9 6 4 2 5 that'st he answer.
  reverse(arr, arr+k);
  reverse(arr+k, arr+n);

  reverse(arr, arr+n);

  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
  }

return 0;
}