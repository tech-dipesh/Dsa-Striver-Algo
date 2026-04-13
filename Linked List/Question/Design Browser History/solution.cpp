#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
  string data;
  Node* prev;
  Node* next;

  // no param:
  Node(): data(""), prev(nullptr), next(nullptr){};

  Node(string value, Node* forward, Node* backward) {
    data = value;
    next = forward;
    prev = backward;
  }
  // Node(int value, Node* forward, Node* backward): data(value), next(forward), prev(backward);
  Node(string value) : data(value), next(nullptr), prev(nullptr) {};
};

class BrowserHistory {
  string homepage;
  Node* current;
public:
  BrowserHistory(Node*head, string homepage){
    head=new Node(homepage);
    current=head;
  }


  void Visit(Node* head, string browser) {
      Node* newNode=new Node(browser);
      newNode->prev=current;
      current->next=newNode;
      
      current=newNode;
  }

  string Back(Node* head, int times) {
    if(current==nullptr){
    return "";
    }
      while(times--){
        if(current->prev==nullptr){
            return current->data;
        }
        current=current->prev;
      }
      return current->data;
    }
    
    string forward(Node* head, int times) {
      if(current==nullptr){
        return "";
      }
      while(times--){
        // Edge Check:
         if(current->next==nullptr){
             return current->data;
         }
        current=current->next;
      }
      return current->data;
      
  }

  void Display(Node* head) {
    Node* temp = head;
    while(temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  // Node* head=new Node();
  Node* head=nullptr;
  BrowserHistory b(head, "nepal.com");
  b.Visit(head, "nepal.com");
  b.Visit(head, "google.com");
  b.Visit(head, "twitter.com");
  b.Visit(head, "reddit.com");
  b.Visit(head, "quora.com");
  cout<<b.Back(head, 1)<<endl;
  cout<<b.Back(head, 1)<<endl;
  cout<<b.Back(head, 1)<<endl;
  cout<<b.forward(head, 1)<<endl;
  b.Visit(head, "browser.com");
  cout<<b.forward(head, 2)<<endl;
  cout<<b.Back(head, 2)<<endl;
  cout<<b.Back(head, 7)<<endl;
}