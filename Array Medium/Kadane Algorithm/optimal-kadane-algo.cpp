#include <iostream>
#include <climits>
using namespace std;
int main(){
   int arr[]={-2, -3, 4, -1, -2, 1, 5, -3 };
   int n=sizeof(arr)/sizeof(arr[0]);
   
  //  answer should be of the: 7

  int maxRes=INT_MIN, sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum<0){
      sum=0;
    }
    maxRes=max(maxRes, sum);
  }

  cout<<maxRes;
return 0;
}