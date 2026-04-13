#include <iostream>
#include <vector>
  #include <algorithm>

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

Node* mergeSortedLL(Node* temp1, Node* temp2) {
  Node* t1 = temp1, * t2 = temp2;
  vector<int>vt;
  while(t1){
    vt.push_back(t1->data);
    t1=t1->next;
  }
  while(t2){
    vt.push_back(t2->data);
    t2=t2->next;
  }
  sort(vt.begin(), vt.end());
    Node* l3=convertArrayToLL(vt);
  return l3;
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
  vector<int>arr = { 2, 3, 7, 9, 11, 25 };
  vector<int>arr1 = { 3, 5, 8, 12, 19, 23, 11, 25 };
  Node* head1 = convertArrayToLL(arr);
  Node* head2 = convertArrayToLL(arr1);
  Node* head = mergeSortedLL(head1, head2);

  Display(head);
}