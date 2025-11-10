
#include <iostream>
#include <stack>
using namespace std;

class StackwithQueue{
  public:
  int size=20;
  stack<int>st;
  stack<int>st1;
  void Push(int value){
    while(st.size()){
      st1.push(st.top());
      st.pop();
    }
    st.push(value);
    
     while(st1.size()){
      st.push(st1.top());
      st1.pop();
    }
  }
  int Pop(){
    int res=st.top();
    st.pop();
    return res;
  }

  int Top(){
   return st.top();
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