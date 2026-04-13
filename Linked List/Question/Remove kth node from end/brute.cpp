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
  Node *temp=head;
  int count=0;
  while(temp){
    count++;
    temp=temp->next; 
  }
  temp=head;
  int val=0;
  while(count-val>k+1){
    temp=temp->next;
    val++;
  }
  Node* delValue=temp->next;
  temp->next=delValue->next;
  delete delValue;
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
  vector<int>arr={1, 2, 7};
  int k=3;
  // 1 2 3 7, 8
  Node* head = convertArrayToLL(arr);
  head=removeKNodeFromEnd(head, k);
  Display(head);
}