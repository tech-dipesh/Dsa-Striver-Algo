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


Node* deleteGivenValue(Node* head, int value){
  // Base Case:
  if(head==nullptr){
    return nullptr;
  }
  Node* temp=head;
  // When on first time that value appear:
  if(head->data==value){
      head=head->next;
      delete temp;
      return head;
  }
  
  Node* back=nullptr;
  while(temp){
      if(temp->data==value){
        back->next=back->next->next;
        delete temp;
        break;
      }
      back=temp;
      temp=temp->next;
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
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  deleteGivenValue(head, 50);
  Display(head);

}