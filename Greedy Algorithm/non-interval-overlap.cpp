// for the non interval problem that it's the same problem as n meeting just sort them and count how many times that we can' just make a meeting just reverse solution we can say.
#include <iostream>
#include <algorithm>
using namespace std;
struct Overlap{
  int start;
  int end;
};

bool Sort (Overlap a, Overlap b){
  return a.end<b.end;
}
int main(){
  Overlap arr[]{
      {0, 5},
      {3, 4},
      {1, 2},
      {5, 9},
      {5, 7},
      {7, 9}
  };
  
  int n=sizeof(arr)/sizeof(arr[0]);
  sort(arr, arr+n, Sort);

  
  int totalPossible=1, firstEnd=arr[0].end, j=0;
  int res[n];
  for(int i=1;i<n;i++){
    if(arr[i].start<firstEnd){
        totalPossible++;
        res[j++]=arr[i].end;
    }
  }

  cout<<"final output is: "<<n-totalPossible;
return 0;
}