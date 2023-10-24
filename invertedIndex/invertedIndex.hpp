#ifndef INVERTEDINDEX_HPP
#define INVERTEDINDEX_HPP

#include "hash.hpp"

template<typename Element>
class InvertedIndex {
  private:
    Hash* array;

  public:
    InvertedIndex(int size) {
      array = new Hash[size];
    }

    void createDirectory(int id, int size);

    void insertIndex(int id, int bucket, int term);

    Element* simpleSearch(int diretorio, int termo);

    Element* multiSearch(
      int diretorio1,
      int termo1,
      int diretorio2,
      int termo2
    );
  };

#endif
