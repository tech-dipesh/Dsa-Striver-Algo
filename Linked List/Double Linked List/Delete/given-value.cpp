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

Node* deleteGivenValue(Node* head, int value){
  Node *temp=head;
  // Base Case:
  if(head==nullptr || head->next==nullptr){
    return nullptr;
  }
  if(head->data==value){
    head=head->next;
    head->prev=nullptr;
    delete temp;
    return head;
  }
  Node *prev=nullptr;
  int count=0;
  while(temp->next){
    count++;
    if(temp->next->data==value){
      Node* deletedValue=temp->next;
      deletedValue->prev=nullptr;
      temp->next=deletedValue->next;
      delete deletedValue;
      temp->prev=prev;
      return head;
    }
    temp=temp->next;
    prev=temp;
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
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToDLL(arr);

  // head=removeKthPlace(head, 1);
  head=deleteGivenValue(head, 21);
  // head=deleteTail(head);
  Display(head);
}