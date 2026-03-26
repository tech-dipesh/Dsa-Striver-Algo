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

Node* indexRemove(Node* head, int index){
  Node* temp=head;
  if(head==nullptr){
    return head;
  }
  if(index==0){
      head=temp->next;
      delete temp;
      return head;
  }
  // If first Node:
  if(index==1){
    head=head->next;
    delete temp;
    return head;
  }

  for(int i=1;i<index-1;i++){
      temp=temp->next;
      if(temp==nullptr){
          return head;
      }
  }
  Node* variable=temp->next;
  temp->next=variable->next;
  delete variable;
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
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  head= indexRemove(head, 3);
  Display(head);
}