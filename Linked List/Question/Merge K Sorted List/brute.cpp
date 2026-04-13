#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {};
  Node(int value, Node* nxt) : data(value), next(nxt) {};
};

vector<Node*>convertArrayToLL(vector<int>arr) {
  vector<Node*>head;
  head[0] = new Node(arr[0]);
  Node* temp=head[0];
  for(int i = 1;i < arr.size();i++) {
    Node* eachValue = new Node(arr[i]);
    temp[i]->next=eachValue;
    // Move temp to the newValue
    temp[i] = eachValue;
  }
  return head;
}

Node* mergeKSortedList(vector<Node*>head){
  if(head.empty()){
  return head[0];
  }

  vector<int>vt;
  for(int i=0;i<head.size();i++){
    Node* temp=head[i];
    while(temp){
      vt.push_back(temp->data);
        temp=temp->next;
    }
  } 
  sort(vt.begin(), vt.end());
  
  Node* returnList=convertArrayToLL(vt);
  return returnList;
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
  vector<Node*>temp=convertArrayToLL(arr);

  Display(head);
}