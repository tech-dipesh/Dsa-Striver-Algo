#include <iostream>
#include <stack>
#include <climits>
#include <unordered_map>
using namespace std;
class Stack{
  public:
  stack<int>st;
  int SmallestValue=INT_MAX;
  void Push(int x){
    // for the first element:
    if(st.empty()){
        SmallestValue=x;
        st.push(x);
      }
      else{
        if(x<SmallestValue){
          st.push(2*x-SmallestValue);
        }
        else{
          st.push(x);
        }
      }
  }

  int Pop(){
    if(st.empty()){
      return 0;
    }
    int res=st.top();
    st.pop();
    if(res<SmallestValue){
      SmallestValue=2*SmallestValue-res;
      return SmallestValue;
    }
    return res;
  }
  int Top(){
    int res=st.top();
    if(SmallestValue<res){
         return res;
    }
    return st.top();
  }
  int getMin(){
    return SmallestValue;
  }

};
int main(){
  Stack s;
  s.Push(9);
  s.Push(6);
  cout<<"First Min: "<<s.getMin()<<endl;
  s.Push(29);
  cout<<s.Pop()<<endl;
  cout<<"Second Min: "<<s.getMin()<<endl;
return 0;
}