#include <iostream>
using namespace std;

class Queue{
class Node{
    public:
    int data;
    Node *next;
    // Constructor Node:
    Node(int value): data(value), next(nullptr){};
};

  public:
  Node *top=nullptr;
  Node* start=nullptr, *end=nullptr;
  int size=0;
  void Push(int value){
    Node* temp=new Node(value);
      if(size==0){
        start=end=temp;
      }
      else{
        end->next=temp;
      }
      size++;
  }
  int Pop(){
    Node *temp=start;
      if(start==nullptr){
        return -1;
      }
      start=start->next;
      delete temp;
      size--;
      return start->data;
  }

  int Top(){
    if(start==nullptr){
      return 0;
    }
    return start->data;
  }
  void isEmpty(){
      if(size==0){
        cout<<"Queue is empty.";
      }
      else{
        cout<<"It's not empty.";
      }
  }
  
  int totalSize(){
    return size;
  }
};
int main(){
    Queue q;
    q.Push(20);
    q.Push(15);
    q.Push(12);
    cout<<"1: "<<q.Pop()<<endl;
    cout<<"Top Element is: "<<q.Top()<<endl;
    q.Push(17);
    
    cout<<"2: "<<q.Pop()<<endl;
    q.Push(2);

    cout<<"Total Size: "<<q.totalSize()<<endl;
    q.isEmpty();
    q.Push(26);
return 0;
}