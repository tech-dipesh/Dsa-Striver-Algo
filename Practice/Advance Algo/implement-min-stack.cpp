#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class Stack{
  stack<int>st;
  public:
  void Push(int x){
    st.push(x);
  }

  int Pop(){
    int res=st.top();
    st.pop();
    return res;
  }
  int Top(){
    return st.top();
  }
  int getMin(){
    int minValue=st.top();
    while(st.size()){
      minValue=min(minValue, st.top());
      st.pop();
    }
    return minValue;
  }

};
int main(){
  Stack s;
  s.Push(15);
  s.Push(10);
  s.Push(29);
  cout<<s.getMin()<<endl;
  cout<<s.Pop()<<endl;
  s.Push(17);
  cout<<s.Top()<<endl;
  cout<<s.getMin()<<endl;
return 0;
}