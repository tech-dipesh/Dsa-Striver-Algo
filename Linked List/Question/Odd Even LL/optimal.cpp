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
Node* oddEvenLL(Node *head){
  // Base Case:
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  Node* odd=head, *even=head->next, *evenHead=head->next;
  // first insert even odd number:
  while(even && even->next){
    // move two both:
      odd->next=odd->next->next;
      even->next=even->next->next;

      // skipping once:
      odd=odd->next;
      even=even->next;
  }
  // Connect odd to even:
  odd->next=evenHead;
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
  vector<int>arr={1, 3, 4, 2, 5, 6};
  // Output: 1 4 5 3 2 6.
  Node* head = convertArrayToLL(arr);
  head=oddEvenLL(head);
  Display(head);

}