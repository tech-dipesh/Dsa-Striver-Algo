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
int main(){
  Node* root=new Node(1);
  root->left=new Node(2);  
  root->right=new Node(3);
  

  root->left->right=new Node(5);
return 0;
}