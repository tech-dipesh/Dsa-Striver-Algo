// T.c.: o(nlongn)+o(n), a.c.: o(1)
#include <iostream>
#include <algorithm>
using namespace std;

long SjfScheduling(int arr[], int n){
  sort(arr, arr+n);
  int sum=0, outSideSum=0;
  for(int i=0;i<n-1;i++){
    sum+=arr[i];
    outSideSum+=sum;
  }
  return outSideSum/n;
}
int main(){
  // Scheduling policy that selects the waiting process with the, smallest execution time to execute next.
  int arr[]={4, 3, 7, 1, 2};
  int n=sizeof(arr)/sizeof(arr[0]);
  // I've to count average waiting time for all the processes, with on the shorted job first algorithm.: the answer should be the 4: due to the , if we count the total sum of each of one before last:
  // p1: 4, p2: 3, p3: 7, p4: 1, p5: 2;
  // p4: 0, p5: 1, p2: 3, p4: 6, p3: 10:
  // now if we sum them up: 1+3+6+10: 20/5: 4 is the answer.
  

  int a1[]={6, 7, 2, 3, 5};
  // when we sort that becomes the: 2 3 5 6 7, on the schduling: 2, 5, 10, 16: 2+5+10+16: 33/6: 5 answer.
  int n1=sizeof(a1)/sizeof(a1[0]);
  cout<<"First Array Sjf Scheduling is: "<<SjfScheduling(arr, n)<<endl;
  cout<<"SEcond Array Sjf Scheduling is: "<<SjfScheduling(a1, n1)<<endl;

  


return 0;
}