#include <iostream>
#include "doublyLinkedList.hpp"

int main() {
  DoublyLinkedList dll(7); // criando um objeto DoublyLinkedList com nº maximo de elementos 7

  std::cout << "Previous Address" << " -- " << "Cursor Address" << " -- " << "Next Address" << " -> " << "Key" << "\n";

  dll.insertBeforeCurrent(1); // com a lista vazia, insere em primeiro o elemento com a key 1
  dll.printList(); // 1
  dll.insertAfterCurrent(2); // insere após o elemento 1
  dll.printList(); // 1, 2
  dll.insertFirst(3); // insere em primeiro, antes do elemento 1
  dll.printList(); // 3, 1, 2
  dll.insertLast(4); // insere em último, após o elemento 2
  dll.printList(); // 3, 1, 2, 4
  dll.insertInPosition(3, 5); // insere antes do elemento 2 e após o elemento 1
  dll.printList(); // 3, 1, 5, 2, 4
  Element* current = dll.accessCurrent();
  std::cout << "--------------------------------------------------------" << "\n";
  std::cout << "Esse é o endereço do elemento atual: " << current << " e esse é o seu valor: " << current->getKey() << "\n";
  dll.deleteCurrent(); // deleta o elemento 5
  dll.printList(); // 3, 1, 2, 4
  dll.deleteFirst();// deleta o elemento 3
  dll.printList(); // 1, 2, 4
  dll.deleteFromPosition(2); // deleta o elemento 2
  dll.printList(); // 1, 4
  dll.deleteLast();// deleta o elemento 4
  dll.printList(); // 1
  dll.deleteElement(1); // deleta o elemento 1
  dll.printList(); // <vazio>
}
