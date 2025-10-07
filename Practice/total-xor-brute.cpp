#include <iostream>
#include <unordered_map>
using namespace std;
    
int Xor(int arr[], int n, int k){
  int totalXor=0;
  for(int i=0;i<n-1;i++){
    int sum=0;
  for(int j=i;j<n;j++){
    sum=sum^arr[j];
    if(sum==k){
      totalXor++;
    }
  }
  }
  return totalXor;
}
int Xor(int arr[], int n, int k){
  int totalXor=0;
 unordered_map<int, int>mp;
    for(int i=0;i<n;i++){
        
      }
  return totalXor;
}


int main(){
  int arr[]={4, 2, 2, 6, 4};
  int k=6;
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<"Total Xors are: "<<Xor(arr, size, k);
return 0;
}