//It's guarrented that we'll reach the end. we've to count the minimum jump that will take, from the 0th to the last index.
#include <iostream>
using namespace std;

// int JumpGame(int arr[], int n){
//   int count=0;
//   for(int i=0;i<n;i++){
//    int sum=arr[i]+i;
//    int j=i;
//    int maxValue=0;
//    while(j<=sum){
//      // maxValue=max(arr[j], maxValue);
//      if(maxValue<arr[j]){
//        maxValue=arr[j];
//        i=j;
//       }
//       j++;   
//     }
//     count++;
//   }
//   return count;
// }



// l will go to the one step ahead of the r and r will go to the farthest that elemenet can havee:
// we'll try to reach the farthest by the two we can say with the two pointer whichever is the maximum from the left and righ tpointer that we'll try to jump that index, one the any right point become the last index that mean we can reach at the end.
int JumpGame(int arr[], int n){
  int count=0;
  int left=0, right=0;
  while(right<n-1){
    int farthest=0;
    for(int i=left;i<=right;i++){
        farthest=max(farthest, arr[i]+i);
    }
    left=right+1;
    right=farthest;
    count++;
  }
  return count;
}
int main() {
  int arr[] = {2, 3, 1, 4, 1, 1, 1, 2 };
  int n = sizeof(arr) / sizeof(arr[0]);
  // the possible answer could be the: 0: 2 to: 2: 1 to, 3:4, 7: 2 reach at the end.
  int a1[] = { 2, 3, 1, 1, 4 };
  int n1 = sizeof(a1) / sizeof(a1[0]);
  // on the second example: first 0th index to 2: 2th index to 3:3th index to 4. which take the 3.
  // first go to from 0th to first, now go second to the last. 
  
  int a2[]={2, 3, 1, 4, 2, 3, 1, 4, 1, 2, 3};
  int n2=sizeof(a2)/sizeof(a2[0]);
  // The my approach that i can think of is:
  // wherever the element is that first just get the element. and just run the loop from there to the that value index, and get the maxValue, and now make the count increament and go that index there and do same thing again.

  cout<<JumpGame(arr, n)<<endl;
  cout<<JumpGame(a1, n1)<<endl;
  cout<<JumpGame(a2, n2)<<endl;
  return 0;
}