
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
Node* reverseGivenLL(Node* head){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head, *previous=nullptr;
  while(temp){
    Node* front=temp->next;
    temp->next=previous;
    previous=temp;
    temp=front;
  }
  return previous;
}

Node* findtheKthGroupSize(Node* temp, int k){
  k--;
  while(k>0 && temp ){
    temp=temp->next;
    k--;
  }
  return temp;
}

Node* RemoveKNodesGroup(Node* head, int k){
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head, *previousNode=nullptr;
  while(temp){
    Node* kthNodePoint=findtheKthGroupSize(temp, k);
    // If the size is smaller than the given k:
    if(kthNodePoint==nullptr){
      if(previousNode)previousNode->next=temp;
      break;
    }
    // Preserve the next node for the next call:
    Node* nextNode=kthNodePoint->next;
    kthNodePoint->next=nullptr;
    reverseGivenLL(temp);
    
    if(temp==head){
      head=kthNodePoint;
    }
    else{
      previousNode->next=kthNodePoint;
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
  head=RemoveKNodesGroup(head, k);
  Display(head);
  cout<<endl;
  
  vector<int>arr1={7, 3, 8, 4, 5, 9, 5, 2};
  int k1=3;
  // Result should be: 3, 2, 1, 6, 5, 4, 9, 8, 7, 10
  Node* head1 = convertArrayToDLL(arr1);
  head1=RemoveKNodesGroup(head1, k1);
  Display(head1);
}