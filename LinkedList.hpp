#include <string>

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class Node {
    public:
        Node();
        Node(std::string, int);
        // Node(std::string, int, Node);
        Node* next;
        string key;
        int value;
};


#endif 
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList { 
  public:  
      LinkedList();
      // void append(Node);
      void append(std::string, key);
      Node* find(std::string);
      

  private:
      Node* head;
      Node* tail;
      size_t size;

};

#endif




