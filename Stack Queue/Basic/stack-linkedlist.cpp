#include <iostream>
using namespace std;

class Stack{
  class Node{
    public:
    int data;
    Node *next;
    // Constructor Value:
    Node(int value): data(value), next(nullptr){};
  };
  public:
  Node *head=nullptr;
  Node *top=nullptr;
  int size=0;
  void Push(int value){
      Node* temp=new Node(value);
      temp->next=top;
      top=temp;
      size++;
  }
  int Pop(){
      if(top==nullptr){
        return -1;
      }
      Node *temp=top;
      int res=top->data;
      top=top->next;
      delete temp;
      size--;
      return res;
  }

  int Top(){
    return top->data;
  }
  void isEmpty(){
      if(size==0){
        cout<<"Stack is empty.";
      }
      else{
        cout<<"Stack have element.";
      }
  }
  
  int totalSize(){
    return size;
  }
};
int main(){
    Stack s;
    s.Push(20);
    s.Push(15);
    s.Push(12);
    cout<<"1: "<<s.Pop()<<endl;
    cout<<"Total Element is: "<<s.Top()<<endl;
    
    cout<<"2: "<<s.Pop()<<endl;
    s.Push(2);

    cout<<s.totalSize()<<endl;
    s.isEmpty();
    s.Push(26);
return 0;
}