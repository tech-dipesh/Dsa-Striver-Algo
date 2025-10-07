#include <iostream>
#include <climits>
using namespace std;
int main(){
   int arr[]={-2, -5, -7, -9, -4};
  //  The answer should be the, 
   int n=sizeof(arr)/sizeof(arr[0]);
    
  int maxSum=INT_MIN, sum=0;
  int startIndex=0, endIndex=0;
   for(int i=0;i<n;i++){
    int start;
     if(sum>0){
       start=i;
     }
    sum+=arr[i];
    if(sum<0){
      sum=0;
    }
    if(maxSum<sum){
      maxSum=sum;
      startIndex=start;
      endIndex=i;
    }
   }
   cout<<"Maximum sum is: "<<maxSum<<endl;
   cout<<"and the starting index of the maxSum is: "<<startIndex<<endl;
   cout<<"and ending index of the maxSum is: "<<endIndex;
   
return 0;
}