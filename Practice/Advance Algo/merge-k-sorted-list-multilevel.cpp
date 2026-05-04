#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node* child;
  Node(): data(0), child(nullptr), next(nullptr){};̥
  Node(int value) : data(value), child(nullptr), next(nullptr) {};
  Node(int value, Node* ch) : data(value), child(ch), next(nullptr) {};
  Node(int value, Node* ch, Node* nxt) : data(value), child(ch), next(nxt) {};
};

Node* convertArrayToLL(vector<vector<int, int>>arr) {
  Node* head = new Node(arr[0][0]);
  Node* temp = head;
  for(int i = 1;i < arr.size();i++) {̥
    Node* eachValue = new Node(arr[i][0]);
    // Move temp to the newValue
    temp->next=eachValue;
    temp = eachValue;
  }
  return head;
}


Node* flattenLinkedList(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head;
  vector<int>vt;
  while(temp) {
    vt.push_back(temp->data);
    temp = temp->next;
  }

}

void Display(Node* head) {
  Node* temp = head;
  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  // vector<int>arr={1, 2, 3, 4};
  vector<pair<int, int>>arr={
    {1, 2, 3, 4},
    {4, 5, 6, 7},
    {8, 11, 17},
    {19, 23, 25},
    {29}
  };
  // vector<int>arr1={4, 5, 6, 7};
  // vector<int>arr2={8, 11, 17};
  // vector<int>arr3={19, 23, 25};
  // vector<int>arr4={29};
  vector<Node*>vt=convertArrayToLL(arr);
  Display(head);
}