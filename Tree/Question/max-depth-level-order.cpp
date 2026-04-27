#include <iostream>
#include <queue>
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




int ThreeOrder1Traversal(Node* root) {
  if(root == nullptr) {
    return 0;
  }
  queue<Node*>q;
  int maxLevel=0;
  Node* temp=root;
  q.push(temp);
  while(q.size()){
    auto size=q.size();
    for(int i=0;i<size;i++){
      auto tp=q.front();
      q.pop();
        if(tp->left)q.push(tp->left);
        if(tp->right)q.push(tp->right);
      }
      maxLevel++;
  }
  return maxLevel;
}
int main() {
  Node* root = new Node(3);
  root->left = new Node(7);
  root->right = new Node(11);
  root->left->left = new Node(2);
  root->left->right = new Node(5);
  root->right->right = new Node(10);
  root->right->left = new Node(4);
  root->left->left->right = new Node(6);
  root->right->left->right = new Node(13);
  root->right->right->left = new Node(2);
  root->right->left->right->left = new Node(9);
  root->right->left->right->right = new Node(17);
  root->right->right->left->right = new Node(6);

  cout << ThreeOrder1Traversal(root);
  return 0;
}