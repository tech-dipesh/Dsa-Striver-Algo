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

Node* mergeSortedLL(Node* temp1, Node* temp2) {
  Node* t1 = temp1, * t2 = temp2;
  Node* dummyNode=new Node(0);
  Node* temp=dummyNode;
  while(t1 && t2) {
    if(t1->data < t2->data) {
        temp->next=t1;
        temp=t1;
        t1=t1->next;
    }
    else {
      temp->next=t2;
      temp=t2;
      t2=t2->next;
    }
  }

    while(t1){
      temp->next=t1;
      temp=t1;
      t1=t1->next;
}
    while(t2){
      temp->next=t2;
      temp=t2;
      t2=t2->next;
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
  vector<int>arr = { 2, 3, 7, 9, 11, 25 };
  vector<int>arr1 = { 3, 5, 8, 12, 19, 23, 11, 25 };
  Node* head1 = convertArrayToLL(arr);
  Node* head2 = convertArrayToLL(arr1);
  Node* head = mergeSortedLL(head1, head2);

  Display(head);
}