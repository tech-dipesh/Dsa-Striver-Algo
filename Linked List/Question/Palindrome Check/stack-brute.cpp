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

bool checkPalindrome(Node *head){
  if(head==nullptr ||head->next==nullptr){
    return true;
  }
  Node* temp=head;
  stack<int>st;
  // push all element to the stack:
  while(temp){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp){
    if(temp->data!=st.top()){
      return false;
  }
    temp=temp->next;
    st.pop();
  }
  return true;
}


int main() {
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  
  vector<int>arr1 = { 2,3, 4, 5, 4, 3, 2 };
  Node* head1 = convertArrayToLL(arr1);

  if(checkPalindrome(head)){
    cout<<"Yes it's a palindrome."<<endl;
  }
  else {
    cout<<"No it's not palindrome."<<endl;
  }

  if(checkPalindrome(head1)){
    cout<<"Yes it's a palindrome."<<endl;
  }
  else {
    cout<<"No it's not palindrome."<<endl;
  }
}