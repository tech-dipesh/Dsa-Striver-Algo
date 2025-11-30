#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Condition are:
// max consecetive day which the stock price are, less than or equal to that day, if previous are bigger just return 1. 
// Appraoch is the just take the pse approach:
class Stock{
  public:
  stack<pair<int, int>>previousGreaterElement;
  int index=-1;
  //  Constructor:
  Stock(){
    index=-1;
  }
  int next(int value){
    // pge approach:
    index++;
    while(previousGreaterElement.size() &&
    previousGreaterElement.top().first<=value){
      previousGreaterElement.pop();
    }
    // We've compute the index before the pushing a element.
    int totaldistanceindex=index-(previousGreaterElement.size()?previousGreaterElement.top().second:-1);
    previousGreaterElement.push({value, index});
    return totaldistanceindex;
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