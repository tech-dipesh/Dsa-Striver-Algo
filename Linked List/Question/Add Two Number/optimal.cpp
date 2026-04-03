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

Node* addTwoNumber(Node* first, Node* second){
  Node* dummyNode=new Node(-1);
  Node* current=dummyNode;
  Node* t1=first, *t2=second;
  int carry=0;
  while(t1 || t2){
    int sum=carry;
    if(t1)
      sum+=t1->data;
    if(t2) sum+=t2->data;
    
    Node *newNode=new Node(sum%10);
    current->next=newNode;
    current=current->next;
    
    carry=sum/10;
    if(t1) t1=t1->next;
    if(t2) t2=t2->next;
  }
  // If carry left:
  if(carry){
    Node *newNode=new Node(carry);
    current->next=newNode;
  }
  return dummyNode->next;
} 
void Display(Node* head) {
  Node* temp = head;
  while(temp) {
    cout << temp->data <<"  " ;
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  // vector<int>arr={2, 4, 6};
  // vector<int>arr1={3, 8, 7};
    vector<int>arr1= {4, 7, 6 };
  vector<int>arr2= {5, 6, 5};
  Node* head1 = convertArrayToLL(arr1);
  Node* head2 = convertArrayToLL(arr2);
  Node *head=addTwoNumber(head1, head2);
  // Result: 6 3 3
  Display(head);

}