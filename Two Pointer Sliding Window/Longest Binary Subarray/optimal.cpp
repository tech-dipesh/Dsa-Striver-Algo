#include <iostream>
using namespace std;
    
int Brute(int arr[], int n, int k){
  if(k<0) return 0;
  int left=0, right=0, sum=0, maxsub=0;
  while(right<n){
    sum+=arr[right];
    // if(sum==k){
    //     maxsub=max(maxsub, right-left+1);
    // }
    while(sum>k){
      sum-=arr[left];
      left++;
    }
        maxsub=max(maxsub, right-left+1);
    right++;
  }
  return maxsub;
}
int main(){
  // it can only include the binary numbers:
  int bin[]={1, 0, 1, 0, 1};
  int size=sizeof(bin)/sizeof(bin[0]);
  int k=2;
  cout<<"Longest Binary Subarray is: "<<Brute(bin, size, k);
return 0;
}