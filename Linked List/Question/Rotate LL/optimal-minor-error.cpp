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
    // Move temp to the newValue
    temp = eachValue;
  }
  return head;
}

Node* rotateLL(Node* head, int k) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head, *preserveFront=head;

    int count=0;
  while(temp){
    count++;
    temp=temp->next;
  }

  // k%=count;

  while(k--){
    if(temp==nullptr){
      return head;
    }
    temp=temp->next;
  }
  Node* nextStore=temp->next;
  temp->next=nullptr;
  head=nextStore;
  temp=head;
  while(temp->next){
    temp=temp->next;
  }
  temp->next=preserveFront;
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
  // vector<int>arr={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  vector<int>arr = { 1, 2, 3, 4, 5 };
  int k = 7;
  Node* head = convertArrayToLL(arr);
  head = rotateLL(head, k);
  Display(head);
  // Result should be: 4 5 1 2 3
}