#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* prev;
  Node* next;
  Node(int value, Node* forward, Node* backward){
    data=value;
    next=forward;
    prev=backward;
  }
  // Node(int value, Node* forward, Node* backward): data(value), next(forward), prev(backward);
  Node(int value) : data(value), next(nullptr), prev(nullptr) {};
};

Node* convertArrayToDLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  Node* previous = head;
  for(int i = 1;i < arr.size();i++) {
    // Constructor:
    Node* eachValue = new Node(arr[i], nullptr, previous);
    temp->next = eachValue;
    previous->next=temp;
    previous = temp;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* addToKthPlace(Node* head, int k, int key){
  Node* value=new Node(key);
  Node *temp=head;
  
  // Base Case:
  if(head==nullptr){
    head=value;
    return nullptr;
  }
  if(k==1){
    value->next=temp;
    temp->prev=value;
    head=value;
    return head;
  }
  Node *previous=nullptr;
  while(k--){
    previous=temp;
    temp=temp->next;
  }
  // First Inserted Value next to temp value:
  value->next=temp;
  temp->prev=value;
  previous->next=value;
  value->prev=previous;
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
  Node* head = convertArrayToDLL(arr);

  // head=removeKthPlace(head, 1);
  head=addToKthPlace(head, 7, 20);
  // head=deleteTail(head);
  Display(head);
}