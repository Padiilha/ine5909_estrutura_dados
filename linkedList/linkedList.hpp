#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template<typename Element>
class LinkedList {
  private:
    Element* first;
    Element* last;
    Element* cursor;

    bool emptyList();

  public:
    LinkedList() : first(nullptr), last(nullptr), cursor(first) {}

    ~LinkedList() {
      delete first, last, cursor;
    }
    
    template<typename Index>
    void insert(Index* index);

    template<typename Index>
    void remove(Index* index);

    template<typename Index>
    Element* search(Index* indexToFind);

    Element* access();
};

#endif
