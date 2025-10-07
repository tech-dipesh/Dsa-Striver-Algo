// t.c.: o(n)+o(n)+o(m): o(2n+m) and s.c.: o(n)
#include <iostream>
using namespace std;
int main(){
   int arr[]={2, 9, 10, 0, 29, 0, 18, 0, 5, 0, 25, 30, 0, 35};
   int n=sizeof(arr)/sizeof(arr[0]);
   int temp[n];
   for(int i=0, j=0;i<n;i++){
    if(arr[i]==0){
      temp[j]=arr[i];
      j++;
    }
   }
int count=0;
 for(int i=0, j=0;i<n;i++){
     if(arr[i]!=0){
      arr[j]=arr[i];
      j++;
      count++;
     }
  }
  for(int i=count;i<n;i++){
    arr[i]=0;
  }


  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
  }
  

return 0;
}