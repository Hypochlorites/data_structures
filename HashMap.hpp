#include "memory"
#include <string>
#include "ArrayList.hpp"
#include <iostream>

#ifndef HASH_MAP_H
#define HASH_MAP_H

class HashMap {
  public:
    HashMap();
    int get(std::string);
    void add(std::string, int);
    int remove(std::string);
    bool keyExists(std::string);
    int getSize();
    int getLength();
    ArrayList getArray();
    friend std::ostream & operator<<(std::ostream& os, HashMap& map);
    std::unique_ptr<ArrayList> array;
  private:
    size_t size;
    size_t length;
    int hash(std::string key, size_t table_size);
};
  
#endif