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


  // void PrintLinkedList(){
  //   Node *temp=head;
  //   while(temp){
  //       cout<<temp->data<<" ";
  //       temp=temp->next;
  //     }
  //   }
   

  
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
  int main(){
  int arr[]={3, 9, 10, 23, 93};
  int n=sizeof(arr)/sizeof(arr[0]);
  Node* head=convertArraytoLinkedList(arr, n);
  Node* temp=head;
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
return 0;
}