
#include <iostream>
#include <queue>
using namespace std;

class StackwithQueue{
  public:
  int size=20;
  int arr[20];
  int top=0;
  queue<int>q;
  void Push(int value){
    q.push(value);
      for(int i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
      }
  }
  int Pop(){
    int res=q.back();
    q.pop();
   return res;
  }

  int Top(){
      return q.front();
  }
  void isEmpty(){
      if(q.size()==0){
        cout<<"Stack is empty.";
      }
      else{
        cout<<"Stack have element.";
      }
  }
  
  int totalSize(){
    return q.size();
  }


  void Display(){
    while(q.size()){
        cout<<q.front();
        q.pop();
    }
  }
};
int main(){
    StackwithQueue sq;
    sq.Push(20);
    sq.Push(15);
    sq.Push(12);
    cout<<"1: "<<sq.Pop()<<endl;
    cout<<"Top Element is: "<<sq.Top()<<endl;
    sq.Push(29);
    cout<<"2: "<<sq.Pop()<<endl;
    sq.Push(2);

    cout<<"Size is:"<<sq.totalSize()<<endl;
    sq.isEmpty();
    sq.Push(26);

    sq.Display();
return 0;
}