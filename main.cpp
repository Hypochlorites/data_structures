#include <iostream>
#include "HashMap.hpp"
#include "LinkedList.hpp"

using namespace std;

void hashMapTest() {
  HashMap map = HashMap();

  string key1 = "adfsdfsdfasfd";
  int val1 = 1; 
  string key2 = "bzcvzxvzxvcz";
  int val2 = 2;
  string key3 = "cerqwreqrqr";
  int val3 = 3;
  string key4 = "devefvevebt";
  int val4 = 4;
  string key5 = "e7thkghkghm";
  int val5 = 5;

  map.add(key1, val1);
  map.add(key2, val2);
  map.add(key3, val3);
  map.add(key4, val4);
  map.add(key5, val5);
}

int main() { 
  // hashMapTest();
  LinkedList list = LinkedList();
  
  string key = "key1";
  int value = 1;

  list.append(key, value);

  Node* result = list.find(key);
  std::cout << result->key << " : " << result-> << std::endl;
}

// clang++ ArrayList.cpp HashMap.cpp main.cpp