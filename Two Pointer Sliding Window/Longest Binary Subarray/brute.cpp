#include <iostream>
using namespace std;
    
int Brute(int arr[], int n, int k){
  int maxsub=0;
  for(int i=0;i<n;i++){
    int sum=0;
  for(int j=i;j<n;j++){
    sum+=arr[j];
    if(sum>k){
      break;
    }
    if(sum==k){
      maxsub=max(maxsub, j-i+1);
    }
  }
  return maxsub;
  }
}
int main(){
  // it can only include the binary numbers:
  int bin[]={1, 0, 1, 0, 1};
  int size=sizeof(bin)/sizeof(bin[0]);
  int k=2;
  cout<<"Longest Binary Subarray is: "<<Brute(bin, size, k);
return 0;
}