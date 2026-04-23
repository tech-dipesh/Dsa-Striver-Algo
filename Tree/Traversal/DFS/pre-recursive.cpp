#include <iostream>
#include <vector>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  // Constructor:
  Node(): data(0), left(nullptr), right(nullptr){};
  Node(int value): data(value), left(nullptr), right(nullptr){};
  Node(int value, Node* leftchild, Node* rightchild): data(value), left(leftchild), right(rightchild){};
};
void Inorder(Node* head){
  if(head==nullptr){
  return;
  }
  Node* temp=head;
  cout<<temp->data<<" ";
  Inorder(temp->left);
  Inorder(temp->right);
}
int main(){
  Node* root=new Node(1);
  root->left=new Node(2);  
  root->right=new Node(3);


  root->left->right=new Node(5);
  root->left->left=new Node(14);
  root->left->right->left=new Node(7);
  root->left->right->right=new Node(1);
  root->left->left->left=new Node(9);
  root->left->left->right=new Node(19);
  root->left->left->right->left=new Node(13);
  root->left->left->right->right=new Node(29);
  root->left->left->left->right=new Node(31);
  root->left->left->left->left=new Node(16);
  Inorder(root);
  return 0;
}