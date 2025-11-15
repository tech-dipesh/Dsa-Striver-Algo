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
    previous->next=temp;
    previous = temp;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

Node* removeDuplicatesDLL(Node* head, int key){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head;
  while(temp && temp->next){
    Node* coming=temp->next;
    while(coming && temp->data==coming->data){
        coming=coming->next;
    }
    temp->next=coming;
    // For checking whether teh coming elemetn exist:
    if(coming) coming->prev=temp;
    temp=temp->next;
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
  vector<int>arr={4, 7, 10, 10, 10, 14, 16, 20, 20, 20, 29, 29};
  int key=10;
  Node* head = convertArrayToDLL(arr);
  head=removeDuplicatesDLL(head, key);
  Display(head);
}