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

Node* insertSortedOrder(Node* head, int key){
  Node* value=new Node(key);
  Node *temp=head;
  
  // Base Case:
  if(head==nullptr){
    head=value;
    return head;
  }

  Node* previous=nullptr;
  while(temp->next->data<key){
    temp=temp->next;
  }


  value->next=temp->next;
  temp->next=value;
  temp->prev=value;
  value->prev=temp;
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
  vector<int>arr = {13, 20, 23, 27, 29, 32, 46, 73, 85, 93};
  Node* head = convertArrayToDLL(arr);

  head=insertSortedOrder(head, 21);
  Display(head);
}