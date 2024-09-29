#include <memory>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ArrayList.hpp"
#include "HashMap.hpp"


HashMap::HashMap() : size(32), length(0) {
  array = std::make_unique<ArrayList>(size);
  for (size_t i=0; i < size; i++) {
    array->append(-1);
  }
}

int HashMap::get(std::string key) {
  int idx = hash(key, size);
  int to_return = array->get(idx);
  if (to_return == -1) {
      throw std::invalid_argument("Key Error: " + key);
  }
  return to_return;
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
    array->set(idx, val);
}

std::ostream& operator<<(std::ostream& os, HashMap& map) {
  os << *(map.array);
  return os;
}
// ArrayList HashMap::getArray() {
//     return &array;
// }
