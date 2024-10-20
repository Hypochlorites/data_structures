#include <memory>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ArrayList.hpp"
#include "HashMap.hpp"
#include "LinkedList.hpp"

HashMap::HashMap() : size(32), length(0) {
  array = std::make_unique<ArrayList<LinkedList>>(size);
  for (size_t i=0; i < size; i++) {
    array->append(LinkedList());
  }
}

int HashMap::get(std::string key) {
  int idx = hash(key, size);
  LinkedList collision_list = array->get(idx);
  Node* target = collision_list.find(key); 
  return target->value;
}

int HashMap::hash(std::string key, size_t table_size) {
    size_t hash = 0;
    for (char c : key) {
      hash = (hash * 31 + c) % table_size;
    }
    return hash;
}

void HashMap::add(std::string key, int val) {
    int idx = hash(key, size);
    LinkedList collision_list = array->get(idx);
    try {
      Node* node = collision_list.find(key);
      node->value = val; 
    } catch (const std::exception& e) {
      collision_list.append(key, val); 
    }
}

std::ostream& operator<<(std::ostream& os, HashMap& map) {
  os << *(map.array);
  return os;
}
// ArrayList HashMap::getArray() {
//     return &array;
// }
