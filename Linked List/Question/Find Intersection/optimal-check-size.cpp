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
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}


Node* findIntersection(Node* temp1, Node* temp2) {
  if(temp1 == nullptr || temp2 == nullptr) {
    return nullptr;
  }
  Node* t1 = temp1, * t2 = temp2;
  int t1count = 0, t2count = 0;
  while(t1 || t2) {
    if(t1) {
      t1count++;
      t1 = t1->next;
    }
    if(t2) {
      t2count++;
      t2 = t2->next;
    }
  }
  t1 = temp1, t2 = temp2;
  // move that element:
  if(t1count > t2count) {
    for(int i = 0;i < t1count-t2count;i++) {
      t1 = t2->next;
    }
  }
  else {
    for(int i = 0;i < t2count - t1count;i++) {
      t2 = t2->next;
    }
  }

  while(t1 || t2) {
    if(t1->data == t2->data) {
      return t1;
    }
    t1 = t1->next;
    t2 = t2->next;
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