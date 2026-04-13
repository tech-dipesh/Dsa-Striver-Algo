#include <iostream>
#include <vector>
#include <stack>
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

Node *reverseLL(Node *head){
  if(head==nullptr || head->next==nullptr){
    return head;
  }
  Node* temp=head;
  stack<int>st;
  while(temp){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp){
    temp->data=st.top();
    st.pop();
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
  head=reverseLL(head);
  Display(head);

}