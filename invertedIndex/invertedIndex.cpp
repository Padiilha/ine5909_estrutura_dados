#include <iostream>
#include "invertedIndex.hpp"

template<typename Element>
void InvertedIndex::createDirectory(int id, int size) {
  Hash* diretorio = new Hash<Element>(size);
  array[id] = diretorio;
}

void insert(int id, Index* index, int bucket) {
  array[id]->insert(index, bucket);
}

template<typename Element>
Element* InvertedIndex::simpleSearch(int diretorio, int termo) {}

template<typename Element>
Element* InvertedIndex::multiSearch(
  int diretorio1,
  int termo1,
  int diretorio2,
  int termo2
) {

}