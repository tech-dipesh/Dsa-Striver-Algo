#include <iostream>
#include <stack>
#include <climits>
#include <unordered_map>
using namespace std;
class Stack{
  public:
  stack<pair<int, int>>st;
  unordered_map<int, int>mp;
  void Push(int x){
    // for the first element:
    if(st.empty()){
      st.push({x, x});
    }
    else{
      // Find small value:
      int minValue=min(x, st.top().second);
      st.push({x, minValue});
    }
  }

  int Pop(){
    int res=st.top().first;
    st.pop();
    return res;
  }
  int Top(){
    return st.top().first;
  }
  int getMin(){
    return st.top().second;
  }

};
int main(){
  Stack s;
  s.Push(15);
  s.Push(10);
  cout<<"First Min: "<<s.getMin()<<endl;
  s.Push(29);
  cout<<s.Pop()<<endl;
  s.Push(17);
  cout<<s.Top()<<endl;
  cout<<"Second Min: "<<s.getMin()<<endl;
return 0;
}