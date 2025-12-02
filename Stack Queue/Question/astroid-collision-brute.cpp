#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int>astroidCollision(vector<int>arr, int n) {
  stack<int>positive;
  stack<int>negative;
  for(int i = 0;i < n;i++) {
     // if(positive.top()>negative.top()){
    //   int res=abs(positive.top()-negative.top());
    // }
    while(positive.size() && negative.size() && abs(positive.top()>negative.top())){
        negative.pop();
    }
    while(negative.size() && positive.size() && abs(negative.top()>positive.top())){
        positive.pop();
    }
    while(negative.size() && positive.size() && abs(negative.top()==positive.top())){
        positive.pop();
        negative.pop();
    }
    if(arr[i] > 0) {
      positive.push(arr[i]);
    }
    else if(arr[i]<0){
      negative.push(arr[i]);
    }
  }
  vector<int>res;
  while(positive.size() || negative.size()){
      if(positive.size()){
        res.push_back(positive.top());
        positive.pop();
      }
      else{
        res.push_back(negative.top());
        negative.pop();
      }
  }
  return res;
}
int main() {
  vector<int>vt = { 4, 7, 1, 1, 2, -3, -7, 17, 15, -16 };
  int n=vt.size();
  //  Final Result is: 4, 17;
  vector<int>res=astroidCollision(vt, n);
  for(int i:res){
    cout<<i<<" ";
  }
  return 0;
}