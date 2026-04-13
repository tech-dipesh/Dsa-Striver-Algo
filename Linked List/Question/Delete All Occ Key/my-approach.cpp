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
    Constructor:
    Node* eachValue = new Node(arr[i], nullptr, previous);
    temp->next = eachValue;
    previous->next=eachValue;
    previous = temp;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* deleteAllOcurranceKey(Node* head, int key){
  Node* temp=head;
  while(temp){
    if(temp->data==key){
      // If first node is a head:
      if(temp==head){
        head=temp->next;
      }

       Node* previous=temp->prev;
       Node* front=temp->next;
       if(front) front->prev=previous;
       if(previous)  previous->next=front;
       delete temp;
       temp=front;
    }
    else{
      temp=temp->next;
    }
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
  vector<int>arr={10, 10, 4, 10, 6, 10, 20, 29};
  int key=10;
  Node* head = convertArrayToDLL(arr);
  head=deleteAllOcurranceKey(head, key);
  Display(head);
}