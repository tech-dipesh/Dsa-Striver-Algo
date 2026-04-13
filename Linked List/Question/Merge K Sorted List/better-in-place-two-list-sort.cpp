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




Node* mergeKSortedList(vector<Node*>head){
  if(head.empty()){
  return head[0];
  }
  Node* temp=head[0];
  for(int i=1;i<head.size();i++){
    temp=mergeSortedLL(temp, head[i]);
  }
  return temp;
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