#include <iostream>
#include <vector>
using namespace std;
// int largestHistogram(vector<int>arr, int n){
int largestHistogram(vector<int>arr, int n){
  int highHistoGram=0;
  for(int i=0;i<n;i++){
    int j=i, k=i;
    int leftCount=0, rightCount=0;
    j--;k++;
    while(j>=0 && arr[i]<=arr[j]){
      leftCount++;
      j--;
    }
    while(k<n && arr[i]<=arr[k]){
      rightCount++;
      k++;
    }
      int eachHistogram=(leftCount+rightCount+1)*arr[i];
      highHistoGram=max(highHistoGram, eachHistogram);
  }
  return highHistoGram;
}
int main(){
   vector<int>vt={2, 1, 5, 6, 2, 3};
  // vector<int>vt={3, 2, 1, 5, 4, 3};
    // s: 2: 2, 1: (6), 5: (5*2=10): (6): 2: (4), 3: 3
    // highest answer: 10
    cout<<largestHistogram(vt, vt.size());
    // largestHistogram(vt, vt.size());
return 0;
}