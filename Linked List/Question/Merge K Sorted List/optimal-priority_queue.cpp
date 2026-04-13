#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {};
  Node(int value, Node* nxt) : data(value), next(nxt) {};
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
  return head;
}

Node* mergeKSortedList(vector<Node*>head){
  if(head.empty()){
  return head[0];
  }
  priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>>pq;
  for(int i=0;i<head.size();i++){
    // only insert the element  if head exist:
    if(head[i]){
      pq.push({head[i]->data, head[i]});
    }
  }

  Node* dummyNode=new Node(0);
  Node* temp=dummyNode;
  while(pq.size()){
      // Get the top element and pop it:
      auto at=pq.top();
      pq.pop();
      // If the next node exist then only insert the element:
      if(at.second->next){
          pq.push({at.second->next->data, at.second->next});
      }
      temp->next=at.second;
      temp=temp->next;
  }

  return dummyNode->next;
  
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
  Node* head = convertArrayToLL(arr);
  
  Display(head);
}