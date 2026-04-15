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



void Print(vector<int>in, vector<int>pre, vector<int>post){
  cout<<"Preorder: ";
  
  for(int i: in){
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Inorder: ";
  for(int i: post){
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Postorder: ";
  for(int i: pre){
    cout<<i<<" ";
  }
}
void ThreeOrder1Traversal(Node* root) {
  if(root == nullptr) {
    return;
  }
  vector<int>preorder, inorder, postorder;
  stack<pair<Node*, int>>st;
  Node* temp=root;
  st.push({root, 1});
  // Left, head, right:

  while(st.size()){
    auto topElement=st.top();
    st.pop();
    // For the preorder Traversal:
      if(topElement.second==1){
        preorder.push_back(topElement.first->data);
        // st.push({root, 2});
        topElement.second++;
        st.push(topElement);
        if(topElement.first->left){
          st.push({topElement.first->left, 1});
        }
      }

     else if(topElement.second==2){
        inorder.push_back(topElement.first->data);
        topElement.second++;
        st.push(topElement);
        if(topElement.first->right){
          st.push({topElement.first->right, 1});
        }
      }
      else{
          postorder.push_back(topElement.first->data);
      }
  }
  Print(inorder, preorder, postorder);
 
}
int main() {
  Node* root = new Node(3);
  root->left = new Node(7);
  root->right = new Node(11);
  root->left->left = new Node(2);
  root->left->right = new Node(5);
  root->right->left = new Node(8);
  root->right->right = new Node(10);
   
  ThreeOrder1Traversal(root);
  return 0;
}