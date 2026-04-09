#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {};
};

Node* convertArrayToLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i = 1;i < arr.size();i++) {
    Node* eachValue = new Node(arr[i]);
    temp->next = eachValue;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* Reverse(Node *head){
  Node* temp=head, *back=nullptr;
  while(temp){
    Node* front=temp->next;
    temp->next=back;
    back=temp;
    temp=front;
  }
  return back;
}


Node *Add1LL(Node *head){
  // Base Case:
  if(head==nullptr){
    return head;
  }
  head=Reverse(head);
  Node* temp=head;
  int carry=1;
  while(temp){
    temp->data=temp->data+carry;
    if(temp->data<10){
      carry=0;
      break;
    }
    else{
      // Carry 1 value:
      temp->data=0;
      carry=1;
    }
    temp=temp->next;
  }
  // If still carry Left:
  if(carry){
    Node* newNode=new Node(1);
    head=Reverse(head);
    newNode->next=head;
    return head;
  }
  head=Reverse(head);
  return head;
}

void Display(Node* head) {
  Node* temp = head;
  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  vector<int>arr = { 1, 5, 9 };
  // Result: 160
  Node* head = convertArrayToLL(arr);
  head=Add1LL(head);
  Display(head);
}