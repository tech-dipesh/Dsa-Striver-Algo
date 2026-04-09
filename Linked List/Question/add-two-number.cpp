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
  Node* temp1=first, *temp2=second;
  Node* dummyNode=new Node(0);
  Node* current=dummyNode;
  int carry=0;
  while(temp1 || temp2){
    int sum=carry;
    sum+=temp1?temp1->data:0;
    sum+=temp2?temp2->data:0;
    Node* newNode=new Node(sum%10);
    current->next=newNode;
    current=current->next;

    carry=sum/10;
   if(temp1) temp1=temp1->next;
   if(temp2) temp2=temp2->next;
  }  
  // If Any carry element left:
  if(carry){
    Node* newNode=new Node(carry);
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
  vector<int>arr={2, 4, 6};
  vector<int>arr1={3, 8, 7};
  Node* head1 = convertArrayToLL(arr);
  Node* head2 = convertArrayToLL(arr1);
  Node *head=addTwoNumber(head1, head2);
  // Result: 6 3 3
  Display(head);

}