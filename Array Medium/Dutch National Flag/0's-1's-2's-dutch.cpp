#include <iostream>
using namespace std;
int main(){
    int arr[]={0, 1, 0, 0, 1, 2, 0, 1, 0, 2, 0, 2, 0, 2, 0, 2, 1, 0, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    
    int low=0, medium=0, high=n-1;
    while(medium<=high){
        if(arr[medium]==0){
          swap(arr[low], arr[medium]); 
          low++;
          medium++;
        }
       else if(arr[medium]==1){
          medium++;
        }
        else{
          swap(arr[medium], arr[high]);
          // medium++;
          high--;
        }
    }

    for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
    }
return 0;
}