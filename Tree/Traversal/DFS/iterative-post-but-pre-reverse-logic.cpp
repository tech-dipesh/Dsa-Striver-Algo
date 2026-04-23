#include <iostream>
#include <algorithm>
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
void levelOrder(Node* root) {
  vector<int>ans;
  stack<Node*>st;
  if(root == nullptr) {
    return;
  }
  // First push root to the stac: and:
  Node* temp = root;
  st.push(temp);
  while(st.size()) {
    Node* topNode=st.top();
    st.pop();
    if(topNode->left) st.push(topNode->left);
    if(topNode->right) st.push(topNode->right);
    ans.push_back(topNode->data);
  }
  reverse(ans.begin(), ans.end());  
  for(int i : ans) {
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
   
  levelOrder(root);
  return 0;
}