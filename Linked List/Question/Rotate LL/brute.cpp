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

Node* rotateLL(Node* head, int k) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head, *preserveFront=head;
  int count=0;
  while(temp){
    count++;
    temp=temp->next;
  }
  // if the count size is larger:
  if(k%count==0){
    return head;
  }
  temp=head;
  k%=count;
 while(k--){
   while(temp->next->next){
     temp=temp->next;
    }
  Node* thatNode=temp->next;
  temp->next=nullptr;
  thatNode->next=head;
  head=thatNode;
  temp=head;
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
  // vector<int>arr={2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35};
  vector<int>arr = { 1, 2, 3, 4, 5 };
  int k = 3881;
  Node* head = convertArrayToLL(arr);
  head = rotateLL(head, k);
  Display(head);
  cout<<endl;
  
  vector<int>arr1 = {98, 23, 2, 98,5 , 9, 23, 5, 8, 23, 52, 56, 29, 13, 5,63, 34, 89, 54,25 ,34, 43 ,141,72, 134 };
  int k1 = 98239237492;
  Node* head1 = convertArrayToLL(arr1);
  head1 = rotateLL(head1, k1);
  Display(head1);
  // Result should be: 4 5 1 2 3
}