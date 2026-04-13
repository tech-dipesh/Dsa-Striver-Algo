#include <iostream>
#include <vector>
#include <algorithm>
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

Node* sortLLMergeSort(Node* head) {
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head;
  vector<int>vt;
  while(temp){
    vt.push_back(temp->data);
    temp=temp->next;
  }
  sort(vt.begin(), vt.end());
  head=convertArrayToLL(vt);
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
  Node* head = convertArrayToLL(arr);
  head=sortLLMergeSort(head);
  Display(head);
}