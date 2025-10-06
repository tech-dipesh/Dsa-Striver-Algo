#include <iostream>
using namespace std;
int main(){
   int arr[]={2, 5, 7, 9, 6, 4};
   int n=sizeof(arr)/sizeof(arr[0]);
   int k=2;
  //  final output should be: 5 7 9 6 4 2
  
  int first[k];
  for(int i=0;i<k;i++){
      first[i]=arr[i];
  }
  for(int i=k;i<n;i++){
      arr[i-k]=arr[i];
  }


  for(int i=n-k, j=0;i<n;i++, j++){
   arr[i]=first[j];
  }
  
  //   without j variable:
  for(int i=n-k;i<n;i++){
   arr[i]=first[i-(n-k)];
  }


  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
  }

return 0;
}