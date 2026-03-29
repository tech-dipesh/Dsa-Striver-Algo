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
    // Constructor value initliazer::
    Node* eachValue = new Node(arr[i], nullptr, previous);
    temp->next = eachValue;
    previous->next=temp;
    previous = temp;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* insertHeadLinkedList(Node* head, int key){
  // Base Case:
  Node* temp=head;
  Node* value=new Node(key);
  if(head==nullptr){
    head=value;
    return head;
  }
  value->next=temp;
  temp->prev=value;
  head=value;
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
  vector<int>arr = {9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToDLL(arr);

  head=insertHeadLinkedList(head, 50);
  // head=insertHeadLinkedList(head);
  // head=insertHeadLinkedList(head);
  // head=insertHeadLinkedList(head);
  Display(head);
}