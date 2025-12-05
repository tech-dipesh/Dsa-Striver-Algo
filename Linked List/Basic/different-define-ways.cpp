// // Manula Pointer toboject:
// #include <iostream>
// using namespace std;
// struct Node{
//   int data;
//   Node* next;
//   Node(int data1, Node* data2){
//     data=data1;
//     next=data2;
//   }
// };
// int main(){
//   // Node n(20, nullptr);
//   Node a=Node(20, nullptr);  
//   Node *b=&a;

// return 0;
// }

// Create new Memory:
#include <iostream>
using namespace std;
struct Node{
  int data;
  Node* next;
  Node(int data1, Node* data2){
    data=data1;
    next=data2;
  }

  // Single pass
  Node(int onlyvariabledata){
    data=onlyvariabledata;
    next=nullptr;
  }
};
int main(){
  int arr[]={3, 9, 10, 23, 93};
  // Node* newMemory=new Node(arr[3], nullptr);
  // Print the memory location of teh third array variable.

  Node *newM=new Node(arr[2], nullptr);
  // cout<<newM->data;
  cout<<newM->data;
return 0;
}