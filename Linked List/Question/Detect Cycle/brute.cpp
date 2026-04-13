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
  // Cycle create:
 Node* cycleNode = head->next->next;
  temp->next = cycleNode;
  return head;
}

bool detectCycle(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return false;
  }
  Node* temp = head;
  unordered_map<Node*, int>mp;
  while(temp) {
    // mp[temp]++;
    if(mp.find(temp)!=mp.end()){
      return true;
    }
    mp[temp]=1;
    temp=temp->next;
  }
  return false;
}
void Display(Node* head) {
  Node* temp = head;
  unordered_map<Node*, int> mp;
  while(temp) {
    // For avoid inifnite loop
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