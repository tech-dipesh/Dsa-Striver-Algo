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

Node* removeKNodeFromEnd(Node *head, int k){
  // Base Case:
  if(head==nullptr|| head->next==nullptr){
    return head;
  }
  Node *temp=head, *slow=head, *fast=head;
  for(int i=0;i<k;i++){
    fast=fast->next;
  }

  // If the first element to be deleted:
  if(fast==nullptr){
    return head->next;
  }
  while(fast->next){
      slow=slow->next;
      fast=fast->next;
  }
  Node *sNext=slow->next;
  slow->next=slow->next->next;
  delete sNext;
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
  // vector<int>arr={3, 6, 9, 12, 15, 17, 22, 25, 29, 42, 46, 56, 87};
  vector<int>arr={1, 3, 7};
  int k=2;
  // 1 2 3 7, 8
  Node* head = convertArrayToLL(arr);
  head=removeKNodeFromEnd(head, k);
  Display(head);
}