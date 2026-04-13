#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* prev;
  Node* next;
  Node(int value) : data(value), next(nullptr), prev(nullptr) {};
  Node(int value, Node* forward, Node* backward){
    data=value;
    next=forward;
    prev=backward;
  }
  // Node(int value, Node* forward, Node* backward): data(value), next(forward), prev(backward);
};

Node* convertArrayToDLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  Node* previous = head;
  for(int i = 1;i < arr.size();i++) {
    Constructor:
    Node* eachValue = new Node(arr[i], nullptr, temp);
    temp->next = eachValue;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* reverseDLL(Node *head){
  // Base Case:
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  
  Node *current=head, *lastElement=nullptr;
  while(current){
    lastElement=current->prev;
    current->prev=current->next;
    current->next=lastElement;
    current=current->prev;
  }
  // Return the botttom last element as lastElement reach only second laste element.
  return lastElement->prev;
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
  head=reverseDLL(head);
  Display(head);
}