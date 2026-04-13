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

Node* findMiddle(Node* head){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head;
  Node* slow=head, *fast=head->next;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}

Node* mergeTwoSortList(Node* t1, Node* t2){
  Node* temp1=t1, *temp2=t2;
  Node* dummyNode=new Node(-1);
  Node* temp=dummyNode;

  while(temp1 && temp2){
      if(temp1->data<=temp2->data){
          temp->next=temp1;
          temp=temp1;
          temp1=temp1->next;
        }
        else{
          temp->next=temp2;
          temp=temp2;
          temp2=temp2->next;
        }
      }
      while(temp1){
        temp->next=temp1;
        temp=temp1;
        temp1=temp1->next;
      }
      while(temp2){
        temp->next=temp2;
        temp=temp2;
        temp2=temp2->next;
    }
    return dummyNode->next;
}

Node* sortLLMergeSort(Node* head) {
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  return head;
  Node* low=head;
  Node* middle=findMiddle(head);
  middle->next=nullptr;
  low=sortLLMergeSort(low);
  return mergeTwoSortList(low, middle);
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