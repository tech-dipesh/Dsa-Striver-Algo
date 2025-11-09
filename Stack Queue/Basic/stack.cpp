#include <iostream>
using namespace std;
class Stack{
  int size=10;
  int arr[10];
  // int arr=new int[size];
  int top=-1;
  public:
  void push(int x){
    if(top==size){
      cout<<"Stack Overflow"<<endl;
    }
    else{
      top++;
      arr[top]=x;
    }
  }
  
  void pop(){
      if(top==-1){
        cout<<"Stack Underflow"<<endl;
      }
      else{
        cout<<arr[top]<<endl;
        top--;
      }
    }
    
    
    int Top(){
    if(top==-1){
      cout<<"Stack Underflow"<<endl;
    }
    else{
      cout<<arr[top]<<endl;
    }
  }

  void isEmpty(){
      if(top==-1){
        cout<<"Stack is Empty"<<endl;
      }
      else{
        cout<<"Stack have element."<<endl;
      }
    }
    
    void isFull(){
      if(top==size){
        cout<<"Stack is Full"<<endl;
      }
      else{
        cout<<"Stack have element."<<endl;
      }
  }
};
int main(){
    Stack s;
    s.push(20);
    s.push(75);
    s.pop();
    s.Top();
    
    s.push(92);
    s.push(27);
    s.push(24);
    s.isEmpty();
    s.pop();
    s.isFull();
    s.push(19);
    s.push(36);
return 0;
}