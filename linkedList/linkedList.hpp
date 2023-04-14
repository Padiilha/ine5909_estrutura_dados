#include "element.hpp"

template<typename T>
class LinkedList{
  private:
    T* first, last;

  public:
    LinkedList(){}

    LinkedList<T>(){}

    ~LinkedList(){
      delete[];
    }

    void insertFirst(int value){
      if (!emptyList()){
        Element<int> firstElement = accessFirst();
        Element<int> newElement(value, &firstElement);
        first = &newElement;
      } else {
        Element<int> newElement(value, NULL);
        first = &newElement;
        last = &newElement;
      }
    }

    void insertLast(int value){
      Element<int> lastElement = accessLast();
      Element<int> newElement(value, NULL);
      lastElement.next = &newElement;
      last = &lastElement;
    }

    void removeFirst(){
      first = &first.next;
    }

    Element accessFirst(){
      return *first;
    }

    Element accessLast(){
      return *last;
    }

    bool emptyList(){
      return (first == NULL && last == NULL);
    }
};

