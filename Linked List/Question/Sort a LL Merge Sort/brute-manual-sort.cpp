#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node {
public:
  int data;
  Node* next;
  Node(int value) : data(value), next(nullptr) {};
  Node(int value, Node* nxt) : data(value), next(nxt) {};
};

Node* convertArrayToLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i = 1;i < arr.size();i++) {
    Node* eachValue = new Node(arr[i]);
    temp->next = eachValue;
    // Move temp to the newValue
    temp = eachValue;
  }
  return head;
}

void mergeTwoSortList(int low,  int middle, int high, vector<int>&vt){
  vector<int>temp;
  int i=low, j=middle+1;
  while(i<=middle && j<=high){
      if(vt[i]<=vt[j]){
          temp.push_back(vt[i]);
          i++;
      }
      else{
        temp.push_back(vt[j]);
        j++;
      }
  }
  while(i<=middle){
      temp.push_back(vt[i]);
      i++;
  }
  while(j<=high){
      temp.push_back(vt[j]);
      j++;
  }
  for(int i=low;i<high;i++){
      vt[i]=temp[i-low];
  }
}

void MergeSort(vector<int>&vt, int low,int  high){
  if(low==high){
    return;
  }
  int middle=low+high/2;
  MergeSort(vt, low, middle);
  MergeSort(vt, middle+1, high);
  mergeTwoSortList(low, middle, high, vt);
}

Node* sortLLMergeSort(Node* head) {
  if(head==nullptr || head->next==nullptr){
  return head;
  }
  Node* temp=head;
  vector<int>vt;
  while(temp){
    vt.push_back(temp->data);
    temp=temp->next;
  }
  MergeSort(vt, 0, vt.size()-1);
  head=convertArrayToLL(vt);
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
  vector<int>arr = { 2, 9, 10, 1, 29, 30, 18, 50, 5, 21, 25, 30, 14, 35 };
  Node* head = convertArrayToLL(arr);
  head=sortLLMergeSort(head);
  Display(head);
}