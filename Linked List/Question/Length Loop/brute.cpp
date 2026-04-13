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
  // Create cycle Node:
  Node* cycleNode=head;
  for(int i=0;i<4;i++){
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
  unordered_map<Node*, int>mp;
  int count=0;
  int index=1;
  while(temp) {
    // mp[temp]++;
    if(mp.find(temp)!=mp.end()){
        int valueofThatKey=mp[temp];
        return index-valueofThatKey;
    }
    mp[temp]=index;
    index++;
    temp=temp->next;
  }
  return 0;
}
void Display(Node* head) {
  Node* temp = head;
  unordered_map<Node*, int>mp;
  while(temp) {
    // Cycle Detect:
    if(mp[temp]++) break;
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  vector<int>arr={2, 7, 9, 12, 5, 27, 6, 4};
  Node* head = convertArrayToLL(arr);
  cout << detectCycle(head);
  cout << endl;
  Display(head);
} 