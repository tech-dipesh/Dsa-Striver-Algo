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
Node *SortLL(Node* head){
  // Base Case:
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  Node* temp=head;
  int zero=0, ones=0, twos=0;
  while(temp){
    if(temp->data==0){
      zero++;
    }
    else if(temp->data==1){
      ones++;
    }
    else if(temp->data==2){
      twos++;
    }
    temp=temp->next;
  }
  temp=head;
  while(zero--){
    temp->data=0;
    temp=temp->next;
  }
  while(ones--){
    temp->data=1;
    temp=temp->next;
  }
  while(twos--){
    temp->data=2;
    temp=temp->next;
  }
  return head;
}
int main() {
  vector<int>arr={2, 1, 0, 1, 2, 0, 1, 1, 0, 2};
  // Result: 0, 0, 0, 1, 1, 1, 1, 2, 2, 2:
  Node* head = convertArrayToLL(arr);
  head=SortLL(head);
  Display(head);

}