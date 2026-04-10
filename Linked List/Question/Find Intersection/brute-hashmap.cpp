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
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}


Node* findIntersection(Node* temp1, Node* temp2) {
  if(temp1 == nullptr || temp2 == nullptr) {
    return nullptr;
  }
  unordered_map<Node*, int>mp;
  Node* temp=temp2;
  while(temp){
    // mp.insert({temp->data, temp});
    mp[temp]=1;
    temp=temp->next;
  }
  temp=temp1;
  while(temp){
      if(mp.find(temp)!=mp.end()){
        return temp;
      }
      temp=temp->next;
  }
  return nullptr;
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
  vector<int>arr = { 3, 1, 4, 6, 2 };
  vector<int>arr1 = { 1, 2, 4, 5, 4, 6, 2 };
  Node* head1 = convertArrayToLL(arr);
  Node* head2 = convertArrayToLL(arr1);
  Node* head = findIntersection(head1, head2);
  Display(head);
}