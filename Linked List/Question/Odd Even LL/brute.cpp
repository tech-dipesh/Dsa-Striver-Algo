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
Node* oddEvenLL(Node *head){
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  
   Node* temp=head;
  Node* result;
  vector<int>vt;
  while(temp && temp->next){
    vt.push_back(temp->data);
    temp=temp->next->next;
  }
  temp=head->next;
  while(temp && temp->next){
      vt.push_back(temp->data);
      temp=temp->next->next;
  }
  temp=head;
  for(int i=0;i<vt.size();i++){
    temp->data=vt[i];
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
  // vector<int>arr={1, 3, 4, 2, 5, 6};
  vector<int>arr={1, 2, 3, 4, 5};
  // Output: 1 4 5 3 2 6.
  Node* head = convertArrayToLL(arr);
  head = oddEvenLL(head);
  Display(head);

}