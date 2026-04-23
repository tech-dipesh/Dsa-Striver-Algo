#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* left;
  Node* right;
  // Constructor:
  Node() : data(0), left(nullptr), right(nullptr) {};
  Node(int value) : data(value), left(nullptr), right(nullptr) {};
  Node(int value, Node* leftchild, Node* rightchild) : data(value), left(leftchild), right(rightchild) {};
};
void PostOrder(Node* root) {
  stack<int>ans;
  stack<Node*>st;
  if(root == nullptr) {
    return;
  }
  Node* temp=root;
  st.push(temp);
  // Left, head, right:
  while(st.size()){
    temp=st.top();
    st.pop();
    ans.push(temp->data);
    if(temp->left)st.push(temp->left);
    if(temp->right)st.push(temp->right);
  }
  vector<int>vt;
  while(ans.size()){
    vt.push_back(ans.top());
    ans.pop();
  }
  for(int i : vt) {
    cout << i << " ";
  }
}
int main() {
  Node* root = new Node(3);
  root->left = new Node(7);
  root->right = new Node(11);
  root->left->left = new Node(2);
  root->left->right = new Node(5);
  root->right->left = new Node(8);
  root->right->right = new Node(10);
   
  PostOrder(root);
  return 0;
}