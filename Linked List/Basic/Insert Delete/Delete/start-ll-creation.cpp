#include <iostream>
#include <vector>
using namespace std;
class Delete {
  // Multiple Value with data and next pointer address:
  class Node {
  public:
    int data;
    Node* next;
    // Default Constructor:
    Node(int value) :data(value), next(nullptr) {};
  };
public:
  Node* head = nullptr;
  void createLinkedList(int key) {
    Node* val = new Node(key);
    Node* temp = head;
    if(temp == nullptr) {
      head = val;
    }
    else{
      while(temp->next) {
        temp = temp->next;
      }
      temp->next = val;
    }
  }

  Node* DeleteFirstNode() {
    Node* temp = head, *newTemp = head;
    if(head == nullptr) {
      return head;
    }
    head = head->next;
    delete temp;
    return head;
  }

  // Display final linked list:
  void Display() {
    Node* temp = head;
    while(temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

};


int main() {
  Delete d;
  d.createLinkedList(23);
  d.createLinkedList(20);
  d.createLinkedList(17);
  d.createLinkedList(29);
  d.createLinkedList(52);
  d.createLinkedList(23);
  d.createLinkedList(29);
  d.createLinkedList(46);
  d.createLinkedList(73);
  d.createLinkedList(93);
  d.DeleteFirstNode();
  d.DeleteFirstNode();
  d.DeleteFirstNode();

  d.DeleteFirstNode();
  d.DeleteFirstNode();
  return 0;
}