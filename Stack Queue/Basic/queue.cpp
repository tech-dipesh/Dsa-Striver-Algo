#include <iostream>
using namespace std;
class Stack{
  int size=10;
  int arr[10];
  int totalSize=-1;
  int start=-1;
  int end=-1;
  public:
  void push(int x){
    if(totalSize==size){
      cout<<"Stack Overflow"<<endl;
    }
    if(totalSize==-1){
      totalSize=0;
      start=0;
      end=0;
      arr[end]=x;
    }
    else{
      end=(end+1)%size;
      arr[end]=x;
      totalSize++;
    }
  }
  
  int pop(){
    int popResult;
      if(start==-1){
        cout<<"Stack Underflow"<<endl;
        return -1;
      }
      else{
        // cout<<arr[start]<<endl;
        popResult=arr[start];
        totalSize--;
        start++;
      }
      return popResult;
    }
    
    
    int Top(){
    if(totalSize==-1){
      cout<<"Stack Underflow"<<endl;
    }
    else{
      cout<<arr[start]<<endl;
    }
  }

  void isEmpty(){
      if(totalSize==-1){
        cout<<"Stack is Empty"<<endl;
      }
      else{
        cout<<"Stack have element."<<endl;
      }
    }
    
    void isFull(){
      if(totalSize==size){
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
    cout<<s.pop()<<endl;
    
    s.push(92);
    s.push(27);
    s.Top();
    s.push(24);
    s.isEmpty();
    cout<<s.pop()<<endl;
    s.isFull();
    s.push(19);
    cout<<s.pop()<<endl;
    s.push(36);

return 0;
}