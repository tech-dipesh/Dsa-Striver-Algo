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



void Display(Node* head) {
  Node* temp = head;
  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
Node *SortLL(Node *head){
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  Node *temp=head;
  Node *dummyZero=new Node(0), *dummyOne=new Node(0), *dummyTwo=new Node(0);
  Node* zeroNode=dummyZero, *oneNode=dummyOne, *twoNode=dummyTwo;
  while(temp) {
      if(temp->data==0){
        zeroNode->next=temp;
        zeroNode=zeroNode->next;
        }
        else if(temp->data==1){
          oneNode->next=temp;
          oneNode=oneNode->next;
        }
        else{
          twoNode->next=temp;
          twoNode=twoNode->next;
        }
        temp=temp->next;
  }
  // Ponit zero to one, if not point to two:
  zeroNode->next=dummyOne->next?dummyOne->next:dummyTwo->next;
  
  oneNode->next=dummyTwo->next;
  twoNode->next=nullptr;

  
  Node* newHead=dummyZero->next;

  delete dummyZero, delete dummyOne, delete dummyTwo;
  return newHead;
}
int main() {
  vector<int>arr={2, 1, 0, 1, 2, 0, 1, 1, 0, 2};
  // Result: 0, 0, 0, 1, 1, 1, 1, 2, 2, 2:
  Node* head = convertArrayToLL(arr);
  head=SortLL(head);
  Display(head);

}