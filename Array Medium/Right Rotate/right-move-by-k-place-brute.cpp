// for the bruet it just need one extra space with o(k).


#include <iostream>
using namespace std;
int main(){
   int arr[]={8, 6,2, 10, 15, 17};
   int k=2;
   int n=sizeof(arr)/sizeof(arr[0]);
   int temp[k];
    
  for(int i=0, j=0;i<n;i++){
      temp[i]=arr[n-k+i];
  }


 for(int i=n-1;i>=k;i--){
    arr[i]=arr[i-k];
 }




//  the temp i've to copy back.
  for(int i=0;i<k;i++){
    arr[i]=temp[i];
  }

  for(int i=0;i<n;i++){
   cout<<arr[i]<<" "; 
  }
return 0;
}