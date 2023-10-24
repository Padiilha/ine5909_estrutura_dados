#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "linkedList.hpp"

template<typename Element>
class HashTable {
  private:
    Element* array;

    LinkedList* hashing(int bucket);

  public:
    HashTable<Element>(int size);

    template<typename Index>
    void insert(Index* index, int bucket);

    template<typename Index>
    bool remove(Index* index);
    
    template<typename Index>
    Element* access(Index* index);
};

#endif
