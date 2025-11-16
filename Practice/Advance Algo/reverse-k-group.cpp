#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(): data(0), next(nullptr){};
  Node(int value) : data(value), next(nullptr) {};
  Node(int value, Node* forward): data(value), next(forward){};
};

Node* convertArrayToDLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
    for(int i=1;i<arr.size();i++){
      // Node* temp=new Node(arr[i]);
      Node *eachValue=new Node(arr[i]);
      temp->next=eachValue;
      temp=eachValue;
    }   
    return head;
}

Node* reverseLL(Node* head){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
   Node* temp=head, *previousNode=nullptr;
  while(temp){
    Node* front=temp->next;
    temp->next=previousNode;
    previousNode=temp;
    temp=front;
  }
  return previousNode;
}
Node* findKthNode(Node* temp, int k){
  if(temp==nullptr || temp->next==nullptr){
  return temp;
  }
  k--;
  // Node* temp=head;
  while( temp && k>0){
    k--;
    temp=temp->next;
  }
  return temp;
}
Node* reverseKGroup(Node* head, int k){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head, *previousNode=nullptr;
  while(temp){
    Node* kthGroup=findKthNode(temp, k);
    if(kthGroup==nullptr){
      if(previousNode) previousNode->next=temp;
      break;
    }
    
    Node* nextNode=kthGroup->next;
    kthGroup->next=nullptr;
    reverseLL(temp);
    if(temp==head){
      head=kthGroup;
    }
    else{
      previousNode->next=kthGroup;
    }
    previousNode=temp;
    temp=nextNode;
  }
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
  vector<int>arr={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k=3;
  // Result should be: 3, 2, 1, 6, 5, 4, 9, 8, 7, 10
  Node* head = convertArrayToDLL(arr);
  head=reverseKGroup(head, k);
  Display(head);
}