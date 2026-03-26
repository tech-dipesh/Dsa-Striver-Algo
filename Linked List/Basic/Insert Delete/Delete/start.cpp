#include <iostream>
#include <vector>
using namespace std;
// Multiple Value with data and next pointer address:
class Node{
    public:
    int data;
    Node* next;
    // Default Constructor:
    Node(int value):data(value), next(nullptr){};
};

Node* convertArraytoLinkedList(vector<int>arr){
  // Create head node:
  Node* head=new Node(arr[0]);
  Node* temp=head;
  for(int i=1;i<arr.size();i++){
        Node* eachValue=new Node(arr[i]);
        temp->next=eachValue;
        temp=eachValue;
  }
  return head;
}
Node* deleteStart(Node* head){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
void Display(Node *head){
Node* temp=head;
while(temp){
cout<<temp->data<<" ";
temp=temp->next;
}
}
int main(){
  vector<int>arr={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  Node* head=convertArraytoLinkedList(arr);
  // I must replace the exisiting node with new Node.
  head=deleteStart(head);
  Display(head);
return 0;
}