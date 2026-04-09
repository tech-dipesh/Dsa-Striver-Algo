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

int recursiveReverse(Node* head){
  // Carry is 1:
  if(head==nullptr){
    return 1; 
  }
  int carry=recursiveReverse(head->next);
  head->data=head->data+carry;
  if(head->data<10){
    return 0;
  }
  head->data=0;
  return 1;
}

Node* Add1LL(Node* head) {
  Node *temp=head;
  // Base Case:
  if(head == nullptr) {
    return head;
  }

  int carry = recursiveReverse(head);
  if(carry==1){
     Node* newNode=new Node(1);
     newNode->next=head;
     return newNode;
  }
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
  vector<int>arr={2, 7, 9};
  Node* head = convertArrayToLL(arr);
  head=Add1LL(head);
  Display(head);
}