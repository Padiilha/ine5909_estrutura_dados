#include <iostream>
#include "hashTable.hpp"

template<typename Element>
HashTable<Element>::HashTable(int size) {
  array = new Element[size];
}

template<typename Element>
LinkedList* HashTable<Element>::hashing(int bucket) {
  if (array[bucket] == nullptr) {
    LinkedList* list = new LinkedList();
    array[bucket] = list;
  }
  return array[bucket];
}

template<typename Element>
template<typename Index>
void HashTable<Element>::insert(Index* index, int bucket) {
  list = hashing(bucket);
  list->insert(index);
}

template<typename Element>
template<typename Index>
bool HashTable<Element>::remove(Index* index) {
  list = hashing(index);
  list->remove(index);
}

template<typename Element>
template<typename Index>
Element* HashTable<Element>::access(Index* index) {
  list = hashing(index);
  list->access();
}