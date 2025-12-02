#include <iostream>
#include <vector>
using namespace std;

vector<int>maxSlidingWindow(vector<int>arr, int n,  int k){
  vector<int>vt;
  for(int i=0;i<n-k+1;i++){
    int maxValue=INT16_MIN;
     for(int j=i;j<i+k;j++){
      maxValue=max(maxValue, arr[j]);
    }
    vt.push_back(maxValue);
  }
  return vt;
}

int main(){
   vector<int>vt={1, 3, -1, -3, 5, 3, 2, 1, 6};
   int n=vt.size();
   int k=3;
   vector<int>res=maxSlidingWindow(vt,  n, k);
   for(int i: res){
    cout<<i<<" ";
   }
return 0;
}