#include <iostream>
#include <unordered_map>

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
    // Must move temp to the node next.:
    temp = eachValue;
  }
  // For creating a cycle:
  Node* cycleCreate=head->next->next->next->next;
  temp->next=cycleCreate;
  return head;
}

bool detectCycle(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head;
  Node* slow=head, *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    // Loop Detect:
    if(slow==fast){
      return true;
    }
  }
  return false;
}
void Display(Node* head) {
  Node* temp = head;
  unordered_map<Node*, int>mp;
  while(temp) {
    // If cycle appear
    if(mp[temp]++) break;
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  cout << (detectCycle(head) ? "True" : "False");
  cout << endl;
  Display(head);
}