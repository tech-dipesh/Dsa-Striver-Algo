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

Node* findMiddleLL(Node* head){
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  int count=0;
  Node *temp=head;
  while(temp){
    count++;
    temp=temp->next;
  }
  temp=head;
  count/=2;
  for(int i=0;i<count;i++){
    temp=temp->next;
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
  vector<int>arr = { 1, 2, 3, 4, 5 };
  vector<int>arr1 = { 1, 2, 3, 4, 5, 6 };
  vector<int>arr2={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  Node* head = convertArrayToLL(arr);
  Node* head1 = convertArrayToLL(arr1);
  head=findMiddleLL(head);
  head1=findMiddleLL(head1);
  Display(head);
  cout<<endl;
  Display(head1);
  
  Node* head2 = convertArrayToLL(arr2);
  head2=findMiddleLL(head2);
  cout<<endl;
  Display(head2);
}