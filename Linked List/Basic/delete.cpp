#include <iostream>
#include <vector>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node(int value){
    data=value;
    next=nullptr;
  }
};
Node* convertArrayToLinkedList(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=0;i<arr.size();i++){
      Node* eachNodeCreate=new Node(arr[i]);
      temp->next=eachNodeCreate;
      temp=eachNodeCreate;
    }
    return head;
}
int DeleteFirstNode(Node *head){
  Node* temp=head;
  Node* newVariable=temp->next;
  delete temp;
  head=newVariable;
  return temp->data;
}
Node* deleteLast(Node *head){
  Node* temp=head;
  while(temp->next){
    temp=temp->next;
  }
  temp->next=nullptr;
  temp=head;
  return head;
}

bool DeleteGivenValue(Node* head, int value){
  Node* front=head, *back=head;
  front=front->next;
  while(front->data!=value && front){
      front=front->next;
      back=back->next;
  }
  if(front->next=nullptr){
    return 0;
  }
  back->next=front->next;
  head=back;
  return 1;
}
int main(){
    vector<int>arr={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
    int n=arr.size();
    Node* head=convertArrayToLinkedList(arr);
  cout<<DeleteFirstNode(head)<<endl;
  cout<<deleteLast(head)<<endl;
  cout<<DeleteGivenValue(head, 29);


  Node* temp=head;
  while(temp){
  cout<<temp->data<<" ";
  temp=temp->next;
  }
  
return 0;
}