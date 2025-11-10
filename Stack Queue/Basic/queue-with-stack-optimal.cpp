
#include <iostream>
#include <stack>
using namespace std;

class StackwithQueue{
  public:
  int size=20;
  stack<int>st;
  stack<int>st1;
  void Push(int value){
    st.push(value);
  }
  int Pop(){
    if(st1.size()){
      int res=st1.top();
      st1.pop();
     return res;
    }
    else{
      while(st.size()){
        st1.push(st.top());
        st.pop();
      }
      int res=st1.top();
      st1.pop();
      return res;
    }
  }

  int Top(){
     if(st1.size()){
     return st1.top();
    }
    else{
      while(st.size()){
        st1.push(st.top());
        st.pop();
      }
      st1.top();
    }
  }
  void isEmpty(){
    if(st.empty()){
      cout<<"Stack/Queue is empty.";
    }
    else{
      cout<<"Stack/Queue is not empty.";
    }
  }
  
  int totalSize(){
    return st.size();
  }
 
};
int main(){
    StackwithQueue qs;
    qs.Push(20);
    qs.Push(15);
    qs.Push(12);
    cout<<"1: "<<qs.Pop()<<endl;
    cout<<"Top Element is: "<<qs.Top()<<endl;
    qs.Push(29);
    cout<<"2: "<<qs.Pop()<<endl;
    qs.Push(2);

    cout<<"Size is:"<<qs.totalSize()<<endl;
    qs.isEmpty();
    qs.Push(26);
return 0;
}