// If Capacity exceed exceed we've to pop out the least recenetly used element from the pair.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// With doubly linked list we can track the get to move first with teh head pointer, with tail remove teh least recently used.
// With the unordered map, can achieve the get any value with o(1), with store teh key and node address.
class LRU{
  class Node{
    public:
    Node* prev;
    int key;
    int value;
    Node* next;
    // Constructor:
    Node(int ky, int val): key(ky), value(val), prev(nullptr), next(nullptr){};
  };
  int capacity;
  public:
  unordered_map<int, Node*>mp;
  Node *head=nullptr, *tail=nullptr;

  // Constructore Value:
  LRU(int size){
    this->capacity=size;
    head=new Node(-1, -1);  
    tail=new Node(-1, -1);  
    head->next=tail;
    tail->prev=head;
    mp.clear();
  }

  void deleteTheNode(Node* temp){
    Node *previousNode=temp->prev;
    Node* afterNode=temp->next;
    previousNode->next=afterNode;
    afterNode->prev=previousNode;
  }
  void insertAfterHeadatStart(Node* temp){
    Node* afterTheHead=head->next;
    head->next=temp;
    temp->next=afterTheHead;
    temp->prev=head;
    afterTheHead->prev=temp;
  }

  // Return the value of the key, if exist else return -1;
  int get(int key){
    // If That value doesn't have
    // Key doesn't exist:
      if(mp.find(key)==mp.end()){
        return -1;
      }
      // Store the node:
      Node* temp=mp[key];
      // If Touched someone we've to mvoe to othe front:
      deleteTheNode(temp);


      insertAfterHeadatStart(temp);
      
      return temp->value;
    }
    // Update the value of the key if exists, else add to the cache, if it's exced the capacity remove teh least recently used.
    void put(int key, int value){
      if(mp.find(key)!=mp.end()){
        Node* temp=mp[key];
        temp->value=value;
        // If Touched someone we've to mvoe to othe front:
          deleteTheNode(temp);
      
          insertAfterHeadatStart(temp);
        }
        else{
          // The size is exceeded:
          if(mp.size()==capacity){
            // Remove that lru from both hashing and also from the dll.
            Node* temp=tail->prev;
            mp.erase(temp->key);
            deleteTheNode(temp);
          }
          // Create a new Node:
              Node* temp=new Node(key, value);
              mp[key]=temp;
              insertAfterHeadatStart(temp);
        }
  }
};
int main(){
  // Size of teh lRU
   LRU l(4); 
   l.put(2, 6);
   l.put(4, 7);
   l.put(8, 11);
   l.put(7, 10);
   //  LRu Order:
    // Linked List and HashMap: (7, 10), (8, 11), (4, 9), (2, 6)
   cout<<l.get(2)<<endl;
   cout<<l.get(8)<<endl;
  //  Get Result: 6, 11:
  //  Now: (8, 11), (2, 6), (7, 10), (4, 9):
  l.put(5, 6);
  //  Replace lru of 4 to 5.
  //  Now: (5, 6), (8, 11), (2, 6), (7, 10):
  cout<<l.get(7)<<endl;
  // Now: (7, 10), (5, 6), (8, 11), (2, 6)
  l.put(5, 7);
  // Result: (5, 7), (7, 10), (8,11), (2, 6)
return 0;
}