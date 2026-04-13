#include <iostream>
#include <vector>
#include <unordered_map>
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
    // Move temp to the newValue
    temp = eachValue;
  }

  Node* cycleNode = head;
  for(int i = 0;i < 4;i++) {
    cycleNode = cycleNode->next;
  }
  temp->next = cycleNode;
  return head;
}

Node* findStartingPointLL(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head;
  Node* slow=head, *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      slow=fast;
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

void Display(Node* head) {
  Node* temp = head;
  unordered_map<Node*, int>mp;
  while(temp) {
    if(mp[temp]++) break;
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  head = findStartingPointLL(head);
  Display(head);
}