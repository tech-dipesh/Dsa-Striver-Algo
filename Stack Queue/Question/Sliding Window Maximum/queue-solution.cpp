  #include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector<int>maxSlidingWindow(vector<int>arr, int n,  int k){
  vector<int>vt;
  queue<int>q;
  // doubly ended dequeue which insert and delete from both side. 
  deque<int>dq;
  
  int left=0, right=k;
  for(int i=0;i<n;i++){
    // The value is bigger so:
    if(dq.size() && dq.front()<=i-k){
    dq.pop_front();
  }
  while(dq.size() && arr[dq.back()]<=arr[i]){
    dq.pop_back();
  }
  // index not element.
  dq.push_front(i);

  // There will be the only range:
  if(i>=k-1){
    vt.push_back(arr[dq.front()]);
  }
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