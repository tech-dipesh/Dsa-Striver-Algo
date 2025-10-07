// use the two pointer approach where on with swap the variabgle with the zero to non zero values.
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   int arr[]={2, 9, 10, 0, 29, 0, 18, 0, 5, 0, 25, 30, 0, 35};
   int n=sizeof(arr)/sizeof(arr[0]);

  //  t.c.: o(n) and s.c.: o(1)
  int count=0, j=0;
  for(int i=0;i<n;i++){
    if(arr[i]!=0){
      arr[j]=arr[i];
      j++;
    }
    else{
      count++;
    }
  }

  for(int i=j;i<n;i++){
    arr[i]=0;
  }
  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
  }

return 0;
}