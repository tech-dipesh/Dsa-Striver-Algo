#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  // Default Pointer:
  Node(){
    Node* head=nullptr;
  }
  Node(int data1){
    data=data1;
    next=nullptr;
  }
  Node(int data1, Node* data2){
    data=data1;
    next=data2;
  }
};


  
  // where will be start:
  Node* convertArraytoLinkedList(int arr[], int n){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<n;i++){
      // Node* temp=new Node(arr[i]);
      Node *eachValue=new Node(arr[i]);
      temp->next=eachValue;
      temp=eachValue;
    }   
    return head;
  }

  bool searchLinkedList(Node* head, int value){
    Node* temp=head;
    while(temp){
      if(value==temp->data){
          return true;
      }
    temp=temp->next;
    }
    return false;
  }
  int main(){
  int arr[]={3, 9, 10, 23, 93};
  int n=sizeof(arr)/sizeof(arr[0]);
  Node* head=convertArraytoLinkedList(arr, n);
  int value=23;
  cout<<endl<<searchLinkedList(head, 23);
return 0;
}