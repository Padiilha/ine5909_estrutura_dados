#include "element.hpp"

template<typename T>
class DoublyLinkedList{
  private:
    T* first, fake, cursor;

    // cursor methods
    advanceNPositions(){}

    recedeNPositions(){}

    goFirst(){}

    goLast(){}

    // auxiliar methods
    bool emptyList(){}

    bool fullList(){}

    int position(){}

  public:
    DoublyLinkedList(){}

    DoublyLinkedList<int>(){}

    ~DoublyLinkedList(){
      delete[];
    }
    
    // list methods
    Element accessCurrent(){}

    void insertBeforeCurrent(){}

    void insertAfterCurrent(){}

    void insertFirst(){}

    void insertLast(){}

    void insertInPosition(){}

    void deleteCurrent(){}

    void deleteFirst(){}

    void deleteLast(){}

    void deleteElement(){}

    void deleteFromPosition(){}

    bool Search(T *key){
      Element fake(key, NULL, NULL);
      first.getBefore().setNext(&fake);

      goFirst();
      while (cursor.getKey()) != *key{
        advanceNPositions(1);
      }
      if (cursor != fake){
        first.getBefore().setNext(&first);
      } else {
	first.getBefore().setNext(&first);
	goLast();
      }
    }
};

