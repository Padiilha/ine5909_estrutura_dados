#include <iostream>
#include "linkedList.hpp"

template<typename Index>
struct Element {
  Index* index;
  Element* previous;
  Element* next;

  Element(Index* i, Element* p, Element* n) : index(i), previous(p), next(n) {}
};

template<typename Element>
bool LinkedList::emptyList(){
  return (first == nullptr);
}

template<typename Element>
template<typename Index>
void LinkedList::insert(Index* index) {
  Element* newElement = new Element(index, last, nullptr);
  last = newElement;
  if (emptyList())
    first = newElement;
}

template<typename Element>
template<typename Index>
void LinkedList::remove(Index* index) {
  Element* elementToRemove = search(index);
  elementToRemove->previous->next = elementToRemove->next;
  elementToRemove->next->previous = elementToRemove->previous;
}

template<typename Element>
template<typename Index>
Element* LinkedList::search(Index* indexToFind) {
  Element* fakeElement = new Element(indexToFind, last, nullptr);
  cursor = first;
  while (cursor->index != indexToFind) {
    cursor = cursor->next;  
  }
  if (cursor->index != fakeElement->index) {
    fakeElement->previous->next = fakeElement->next;
    fakeElement->next->previous = fakeElement->previous;
    delete fakeElement;
    return cursor;
  } else {
    return fakeElement;
  }
}

template<typename Element>
Element* LinkedList::access() {
  return cursor;
}
