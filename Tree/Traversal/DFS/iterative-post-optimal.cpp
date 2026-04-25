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
  while( temp || st.size()){
    if(temp){
      st.push(temp);
      temp=temp->left;
    }
    else{
      temp=st.top();
      st.pop(); 
    }
  }
    
  
  // for(int i:vt){
  //     cout<<i<<" ";
  // }
}
int main() {
  // Node* root=new Node(8);
  // root->left=new Node(3);
  // root->right=new Node(5);
  // root->left->left=new Node(4);
  // root->left->right=new Node(9);
  // root->right->left=new Node(7);
  // root->right->left->right=new Node(29);
  // root->right->right=new Node(2);

  
  Node* root=new Node(1);
  root->left=new Node(2);
  root->left->right=new Node(7);
  root->left->right=new Node(8);
  root->left->left=new Node(3);
  root->left->left->right=new Node(4);
  root->left->left->right->right=new Node(5);
  root->left->left->right->right->right=new Node(6);
  levelOrder(root);
  return 0;
}