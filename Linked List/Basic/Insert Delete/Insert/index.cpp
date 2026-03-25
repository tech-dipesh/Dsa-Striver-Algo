#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {};

  // Both given value:
  Node(int value, Node* nxt): data(value), next(nxt){};
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
Node* insertatThatIndex(Node*head, int value, int index) {
  // Base Case:
  Node* val = new Node(value);
  if(head==nullptr){
    if(index==1){
      head=val;
    }
    return nullptr;
  }
  if(index == 0) {
    val->next=head;
    head=val;
    return head;
  }
  Node* temp = head, *next = head;
  if(index==1){
    Node* val = new Node(value, head);
    return val;
  } 
  
  for(int i = 0;i < index-1;i++) {
    temp = temp->next;
  }
  val->next=temp->next;
  temp->next=val;
  // return valu;
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
  head =insertatThatIndex(head, 27, 2);
  Display(head);

}