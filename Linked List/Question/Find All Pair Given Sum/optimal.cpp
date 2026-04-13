#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
  public:
  int data;
  Node* prev;
  Node* next;
  Node(int value, Node* forward, Node* backward){
    data=value;
    next=forward;
    prev=backward;
  }
  // Node(int value, Node* forward, Node* backward): data(value), next(forward), prev(backward);
  Node(int value) : data(value), next(nullptr), prev(nullptr) {};
};

Node* convertArrayToDLL(vector<int>arr) {
  Node* head = new Node(arr[0]);
  Node* temp = head;
  Node* previous = head;
  for(int i = 1;i < arr.size();i++) {
    Constructor:
    Node* eachValue = new Node(arr[i], nullptr, previous);
    temp->next = eachValue;
    previous->next=temp;
    previous = temp;
    // Must move to next on Linked List:
    temp = eachValue;
  }
  return head;
}

vector<pair<int, int>>allPairSum(Node* head, int k){
  unordered_map<int, int>mp;
  vector<pair<int, int>>res;
    if(head==nullptr || head->next==nullptr){
    return res;
  }


  Node* temp=head;
  while(temp->next){
    int sum=k-temp->data;
    if(mp.find(sum)!=mp.end()){
        res.push_back({mp[sum], temp->data});
      }
    mp[temp->data]++;
    temp=temp->next;
  }
  return res;
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
  vector<int>arr={1, 2, 3, 4, 9, 11};
  int k=5;
  Node* head = convertArrayToDLL(arr);
  vector<pair<int, int>>pairSum=allPairSum(head, k);
  for(auto i: pairSum){
    cout<<i.first<<" "<<i.second;
    cout<<endl;
  }

}