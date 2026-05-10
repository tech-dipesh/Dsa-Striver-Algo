#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node* child;
  Node(): data(0), child(nullptr), next(nullptr){};
  Node(int value) : data(value), child(nullptr), next(nullptr) {};
  Node(int value, Node* ch) : data(value), child(ch), next(nullptr) {};
  Node(int value, Node* ch, Node* nxt) : data(value), child(ch), next(nxt) {};
};

Node* convertArrayToLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i = 1;i < arr.size();i++) {
    Node* eachValue = new Node(arr[i]);
    // Move temp to the newValue
    temp->next=eachValue;
    temp = eachValue;
  }
  return head;
}


Node* convertLLToFlattenLL(vector<int>arr1, vector<int>arr2, vector<int>arr3, vector<int>arr4, vector<int>arr5){
  Node* head=new Node(arr1[0]);
  Node* temp=head;
  for(int i=0;i<arr1.size();i++){
    temp->next=new Node(arr1[i]);
    temp=temp->next;
  }

  // Now i've to attach a child ll:
  temp=head->next;
  temp->child=convertArrayToLL(arr1);


  Node* arr2Child=head->next;
  arr2Child=arr2Child->next;
  temp->child=convertArrayToLL(arr2);
  
  
  Node* arr3Child=head->next;
  arr3Child=arr3Child->next;
  temp->child=convertArrayToLL(arr3);


  Node* arr4Child=head->next;
  arr4Child=arr4Child->next;
  temp->child=convertArrayToLL(arr4);

  
}


Node* convertgivenArraytoVerticalLL(vector<int>&arr){
    sort(arr.begin(), arr.end());
    Node* newNode=new Node(arr[0]);

    for(int i=1;i<arr.size();i++){
      Node* dummyNode=new Node(arr[i]);
      newNode->next=dummyNode;
      newNode=dummyNode;
    } 
    return newNode;
  }
  Node* flattenLinkedList(Node* head) {
  if(head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* temp = head;
  vector<int>vt;
  while(temp) {
    Node* it=temp;
    while(it){
      vt.push_back(it->data);
      it=it->child;
    }
    temp=temp->next;
  }
  
  return head;
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
  vector<int>arr1={4, 5, 6, 7};
  vector<int>arr2={8, 11, 17};
  vector<int>arr3={29};
  vector<int>arr4={1, 2, 3, 4};
  vector<int>arr5={19, 23, 25};
  vector<int>arr6={10, 15, 19, 23, 26};
  
  Node* head = convertLLToFlattenLL(arr1, arr2, arr3, arr4, arr5);

  Display(head);
}