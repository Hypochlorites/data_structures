#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList() {
  this->head = new Node();
  this->tail = head;
  size = 0;
}

void LinkedList::append(std::string key_, int value_) {
  Node* newest = new Node(key_, value_);
  tail->next = newest;
  tail = newest;
  size++;
}

Node* LinkedList::find(std::string key_) {
  Node* current = head->next;
  while (current != nullptr) {
    if (current->key == key_) {
      return current;
    } 
    current = current->next;
  }
  throw std::invalid_argument("Key not found");
}

Node::Node(): next(nullptr) {}

Node::Node(std::string key_, int value_): key(key_), value(value_), next(nullptr) {}






