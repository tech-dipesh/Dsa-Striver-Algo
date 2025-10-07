#include <iostream>
using namespace std;
int main(){
       int arr[]={0, 1, 0, 0, 1, 2, 0, 1, 0, 2, 0, 2, 0, 2, 0, 2, 1, 0, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int zero=0, ones=0, twos=0;

    for(int i=0;i<n;i++){
      if(arr[i]==0){
        zero++;
      }
      if(arr[i]==1){
        ones++;
      }
      if(arr[i]==2){
        twos++;
      }
    }
    
    int i=0;
    while(zero--){
      arr[i++]=0;
    }
    while(ones--){
      arr[i++]=1;
    }
    while(twos--){
        arr[i++]=2;
    }

    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
return 0;
}