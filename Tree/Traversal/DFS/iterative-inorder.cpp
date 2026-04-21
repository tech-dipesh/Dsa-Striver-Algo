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
void levelOrder(Node* root) {
  vector<int>vt;
  Node* temp=root;
  stack<Node*>st;
  while(temp || st.size()){
    // If element exist, first push to the stack: move it to the left side:
    if(temp){
      st.push(temp);
      temp=temp->left;
    }
    else{
      // if stack become empty that mean, there is no node to left:
      temp=st.top();
      st.pop();
      vt.push_back(temp->data);
      temp=temp->right;
    }
  } 
  
  for(int i:vt){
      cout<<i<<" ";
  }
}
int main() {
  Node* root=new Node(8);
  root->left=new Node(3);
  root->right=new Node(5);
  root->left->left=new Node(4);
  root->left->right=new Node(9);
  root->right->left=new Node(7);
  root->right->right=new Node(2);
  levelOrder(root);
  return 0;
}