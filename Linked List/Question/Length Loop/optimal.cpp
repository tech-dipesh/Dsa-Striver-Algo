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
    // Must move to next on Linked List:
    temp = eachValue;
  }
  // For making the cycle:
  Node* cycleNode=head;
  for(int i=0;i<7;i++){
    cycleNode=cycleNode->next;
  }
  temp->next=cycleNode;
  return head;
}

int detectCycle(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return 0;
  }
  Node* temp = head;
  Node* slow=head, *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    // if loop detect.
    if(slow==fast){
      int count=1;
      fast=fast->next;
      // Count total node that comes under the loop:
      while(fast!=slow){
        count++;
        fast=fast->next;
      }
      return count;
    }
  }
  return 0;
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
  cout<<"Length of the loop is: "<<detectCycle(head)<<endl;
  Display(head);
}