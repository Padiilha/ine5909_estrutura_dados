#include <iostream>
#include "arrayList.hpp"

template<typename Object>
void ArrayList<Object>::resize() {
  size = size * 2;
  Object* newArray = new Object[size];
  for (int i; i < size/2; i++) {
    newArray[i] = array[i];
  }
  array = newArray;
  delete newArray;
}

template<typename Object>
bool ArrayList<Object>::emptyList() {
  bool isEmpty = true;
  for (int i = 0; i < size; i++) {
    if (array[i] != nullptr) {
      isEmpty = false;
      break;
    }
  }
  return isEmpty;
}

template<typename Object>
void ArrayList<Object>::insert(
  std::string nome,
  std::string curso,
  std::string semestre_ingresso,
  std::string cidade_origem
) {
  for (int i = 0; i < size; i++) {
    if (array[i] == nullptr) {
      Object* obj = new Object(
        i + 1,
        nome,
        curso,
        semestre_ingresso,
        cidade_origem
      )
      break;
    }
  }
}

template<typename Object>
bool ArrayList<Object>::remove(int id) {
  for (int i = 0; i < size; i++) {
    if (array[i]->id == id) {
      delete array[i];
      array[i] = nullptr;
      return true;
      break;
    }
  }
  return false;
}

template<typename Object>
Object* ArrayList<Object>::access(int id) {
  return array[id - 1];
}