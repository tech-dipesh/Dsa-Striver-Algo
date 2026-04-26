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

int maxCount=0;
int isBalanced(Node* root){
  if(root==nullptr){
    return 0;
  }
  int lh=isBalanced(root->left);
  int rh=isBalanced(root->right);
  maxCount=max(maxCount, lh+rh+1);
  // return max(lh, rh)+1;
  return maxCount;
}
int main(){
  Node* root=new Node(7);
  root->left=new Node(9);
  root->right=new Node(11);
  root->left->left=new Node(13);
  root->left->right=new Node(17);
  root->left->left->left=new Node(4);
  root->left->left->right=new Node(20);
  root->left->left->right->left=new Node(14);
  root->left->right->left=new Node(29);
  root->left->right->right=new Node(31);
  root->left->right->right->left=new Node(27);

  
  root->right->left=new Node(20);
  root->right->right=new Node(25);
  root->right->left->left=new Node(10);
  root->right->left->right=new Node(13);
  root->right->right->right=new Node(9);
  root->right->right->left=new Node(7);

  cout<<isBalanced(root);

return 0;
}