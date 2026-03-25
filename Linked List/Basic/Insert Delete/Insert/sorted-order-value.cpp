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

  
  Node* insertAtSortedOrder(Node* head, int value){
      Node* val=new Node(value);
      Node* temp=head;
      // Base Case:
      if(head==nullptr){
        head=val;
        return head;
      }
      if(head->data>value){
        val->next=head;
        head=val;
        return head;
      }


      // For any order:
      while(temp->next){
        if(temp->next->data>value){
            val->next=temp->next;
            temp->next=val->next;
            break;
        }
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
  vector<int>arr = {13, 20, 23, 27, 29, 32, 46, 73, 85, 93};
  // vector<int>arr;
  Node* head = convertArrayToLL(arr);
  head=insertAtSortedOrder(head, 28);
  Display(head);

}