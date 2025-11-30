#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Condition are:
// max consecetive day which the stock price are, less than or equal to that day, if previous are bigger just return 1. 

class Stock{
  public:
  vector<int>vt;
  int index=0;
  int next(int value){
    vt.push_back(value);
    int count=1;
    int i=vt.size()-2;
    while(vt[i]<=value){
        count++;
        i--;
    }
    return count;
  }
};
int main(){
  //  Given problem:
  Stock s;
  cout<<s.next(7)<<" "; 
  cout<<s.next(2)<<" "; 
  cout<<s.next(1)<<" "; 
  cout<<s.next(3)<<" "; 
  cout<<s.next(3)<<" ";
  cout<<s.next(1)<<" "; 
  cout<<s.next(8)<<" "; 
  // on each function should be: 1, 1, 1, 3, 4, 1, 7.
return 0;
}