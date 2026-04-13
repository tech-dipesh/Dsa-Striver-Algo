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

Node* deleteMiddleNode(Node *head){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head;
  int count=0;
  while(temp){
    count++;
    temp=temp->next;
  }
  temp=head;
  count/=2;
  count--;
  while(count--){
    temp=temp->next;
  }
  Node* deleteNode=temp->next;
  temp->next=deleteNode->next;
  delete deleteNode;
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
  vector<int>arr1={7, 3, 6, 9, 10, 17, 21};
  Node* head = convertArrayToLL(arr);
  Node* head1 = convertArrayToLL(arr1);
  head=deleteMiddleNode(head);
  head1=deleteMiddleNode(head1);
  Display(head);
  cout<<endl;
  Display(head1);
}