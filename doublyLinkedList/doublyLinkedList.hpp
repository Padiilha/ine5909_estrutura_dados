#include "element.hpp"


class DoublyLinkedList {
  private:
    int maxElements, numElements = 0, position = 1;
    Element* first;
    Element* cursor;

    // cursor methods

    /*
      Metodo advanceNPositions()
      se a lista esta vazia: lanca excessao
      se nao:
        avanca o cursor n vezes e a cada iteracao adiciona 1 ao contador de posicao
        setta o contador de posicao conforme o modulo do numero de elementos presentes
    */
    void advanceNPositions(int n) {
      if (!emptyList()) {
        for (int i = 0; i < n; i++) {
          cursor = cursor->getNext();
          position++;
        }
        position = position % numElements;
      } else {
        // throw ...
      }
    }

    /*
      Metodo recedeNPositions()
      se a lista esta vazia: lanca excessao
      se nao:
        retrocede o cursor n vezes e a cada iteracao subtrai 1 ao contador de posicao
        setta o contador de posicao conforme o modulo do numero de elementos presentes
    */
    void recedeNPositions(int n) {
      if (!emptyList()) {
        for (int i = 0; i < n; i++) {
          cursor = cursor->getPrevious();
          position--;
        }
        position = position % numElements;
      } else {
        // throw ...
      }
    }

    /*
      Metodo goFirst()
      setta o cursor com o valor de first
    */
    void goFirst() {
      cursor = first;
    }

    /*
      Metodo goLast()
      setta o cursor com o valor anterior de first, ou seja, o ultimo
    */
    void goLast() {
      cursor = first->getPrevious();
    }

    /*
      Metodo goToPosition()
      utiliza o metodo goFirst()
      setta a posicao como 1
      itera pelo numero de elementos na lista:
        se o contador de posicao eh igual a posicao inserida: sai do escopo
        se nao: utiliza o metodo advanceNPositions() para avancar 1 posicao
      se nao tiver saido do escopo: lanca uma excessao
    */
    void goToPosition(int pos) {
      goFirst();
      position = 1;
      for (int i = 0; i < numElements; i++) {
        if (position == pos) {
          break;
        }
        advanceNPositions(1);
      }
      // throw ...
    }

    // auxiliar methods

    /*
      Metodo emptyList()
      retorna se numero de elementos da lista eh 0
    */
    bool emptyList() {
      return (numElements == 0);
    }

    /*
      Metodo fullList()
      retorna se numero de elementos da lista eh o definido no construtor
    */
    bool fullList() {
      return (numElements == maxElements);
    }

    /*
      Metodo positionOf()
      utiliza o metodo search() para levar o cursor para a posicao da chave inserida
      se encontra: retorna o contador de posicao
      se nao: lanca uma excessao
    */
    int positionOf(int key) {
      if (search(key)) {
        return position;
      } else {
        // throw ...
      }
    }

    // list private methods

    /*
      Metodo insertEmpty()
      cria um novo elemento com a chave recebida sem declarar antecessor e sucessor
      setta o endereco do novo elemento como first
      setta o elemento anterior do novo elemento o first
      setta o elemento seguinte do novo elemento o first
      setta o first como cursor
      adiciona ao numero de elementos
    */
    void insertEmpty(int key) {
      Element* newElement = new Element(key);
      first = newElement;
      first->setPrevious(first);
      first->setNext(first);
      cursor = first;
      numElements++;
    }

  public:
    DoublyLinkedList(int maxEl) {
      maxElements = maxEl;
    }
    
    // list public methods

    /*
      Metodo acessCurrent()
      retorna o cursor, o endereco do elemento
    */
    Element* accessCurrent() {
      if (!emptyList()){
        return cursor;
      } else {
        return NULL;
      }
    }

    /*
      Metodo insertBeforeCurrent()
      se a lista estiver vazia: utiliza o metodo insertEmpty() para inserir o primeiro elemento na lista
      se não se a lista estiver cheia: lanca uma excessao
      se não:
        cria um novo elemento com os parametros:
          chave recebida,
          setta o anterior com o endereco do elemento anterior ao cursor
          setta o proximo com o endereco do elemento em que o cursor esta
        adiciona ao numero de elementos
    */
    void insertBeforeCurrent(int key) {
      if (emptyList()) {
        insertEmpty(key);
      } else if (fullList()) {
        // throw ...
      } else {
        Element* newElement = new Element(key, cursor->getPrevious(), cursor);
        cursor->getPrevious()->setNext(newElement);
        cursor->setPrevious(newElement);
        numElements++;
      }
    }

    /*
      Metodo insertAfterCurrent()
      se a lista estiver vazia: utiliza o metodo insertEmpty() para inserir o primeiro elemento na lista
      se não se a lista estiver cheia: lanca uma excessao
      se não:
        cria um novo elemento com os parametros:
          chave recebida,
          setta o anterior com o endereco do elemento em que o cursor esta
          setta o proximo com o endereco do elemento com o elemento seguinte ao cursor
        adiciona ao numero de elementos
    */
    void insertAfterCurrent(int key) {
      if (emptyList()) {
        insertEmpty(key);
      } else if (fullList()) {
        // throw ...
      } else {
        Element* newElement = new Element(key, cursor, cursor->getNext());
        cursor->setNext(newElement);
        cursor = newElement; // set cursor to point to new element
        cursor->getNext()->setPrevious(cursor);
        numElements++;
      }
    }

    /*
      Metodo insertFirst()
      utiliza o metodo goFirst() para settar o cursor na primeira posicao
      utiliza o metodo insertBeforeCurrent() para adicionar o elemento na posicao anterior ao primeiro
      setta o first com o endereco do elemento anterior do cursor, o novo elemento
      setta first como sucessor do elemento anterior de first
    */
    void insertFirst(int key) {
      goFirst();
      insertBeforeCurrent(key);
      first = cursor->getPrevious();
      first->getPrevious()->setNext(first);
    }

    /*
      Metodo insertLast()
      utiliza o metodo goLast() para settar o cursor na ultima posicao
      utiliza o metodo insertAfterCurrent() para adicionar o elemento na posicao seguinte ao ultimo
    */
    void insertLast(int key) {
      goLast();
      insertAfterCurrent(key);
    }


    /*
      Metodo insertInPosition()
      utiliza o metodo goToPosition() para mover o cursor para a posicao desejada
      utiliza o metodo inserBeforeCurrent() para adicionar o elemento na posicao anterior ao elemento da posicao inserida tornando-se o novo elemento na posicao
      setta o cursor como o anterior de cursor
    */
    void insertInPosition(int pos, int key) {
      goToPosition(pos);
      insertBeforeCurrent(key);
      cursor = cursor->getPrevious();
    }

    /*
      Metodo deleteCurrent()
      se a lista nao esta vazia: lanca uma excessao
      se nao estiver:
        setta como proximo elemento do elemento anterior do cursor o elemento seguinte ao cursor
        setta como elemento anterior do elemento seguinte do cursor o elemento anterior ao cursor
        move o cursor para o elemento seguinte
        subtrai o numero de elementos
    */
    void deleteCurrent() {
      if (!emptyList()) {
        cursor->getPrevious()->setNext(cursor->getNext());
        cursor->getNext()->setPrevious(cursor->getPrevious());
        cursor = cursor->getNext();
        numElements--;
      } else {
        // throw ...
      }
    }

    /*
      Metodo deleteFirst()
      utiliza o metodo goFirst() para settar o cursor na primeira posicao
      setta o elemento seguinte de first como first
      utiliza o metodo deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a primeira
    */
    void deleteFirst() {
      goFirst();
      first = first->getNext();
      deleteCurrent();
    }

    /*
      Metodo deleteLast()
      utiliza o metodo goLast() para settar o cursor na ultima posicao
      utiliza o metodo deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a ultima
    */
    void deleteLast() {
      goLast();
      deleteCurrent();
    }

    /*
      Metodo deleteElement()
      se a lista esta vazia: lanca uma excessao
      se nao estiver:
        se o elemento nao existe na lista: lanca uma excessao
        se estiver:
          utiliza o metodo deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a do elemento desejado (foi settado enquanto fazia a busca pelo elemento)
    */
    void deleteElement(int key) {
      if (!emptyList()) {
        if (search(key)) {
          deleteCurrent();
        } else {
          // throw ...
        }
      } else {
        // throw ...
      }
    }

    /*
      Metodo deleteFromPosition()
      utiliza o metodo goToPosition() para mover o cursor para a posicao desejada
      utiliza o metodo deleteCurrent() para deletar o elemento na posicao do cursor
    */
    void deleteFromPosition(int pos) {
      goToPosition(pos);
      deleteCurrent();
    }

    /*
      Metodo search()
        cria um elemento fake para otimizar a busca
        utiliza o metodo goFirst() para mover o cursor para a primeira posicao
        itera sobre a lista enquanto a chave do elemento for diferente da chave inserida
        se o elemento encontrado for diferente do fake:
          apaga elemento fake
          retorna true
        se nao:
          apaga o elemento fake
          utiliza o metodo goLast() para mover o cursor para a ultima posicao
          retorna false
    */
    bool search(int key) {
      Element* fakeElement = new Element(key);
      first->getPrevious()->setNext(fakeElement);

      goFirst();
      while (cursor->getKey() != key) {
        advanceNPositions(1);
      }
      if (cursor != fakeElement) {
        first->getPrevious()->setNext(first);
        return true;
      } else {
        first->getPrevious()->setNext(first);
        goLast();
        return false;
      }
    }

    /*
      Metodo printList()
      cria um cursor do escopo e setta ele com o valor de first
      itera sobre os elementos da lista:
        logga:
          endereco do elemento anterior,
          endereco do elemento atual,
          endereco do elemento seguinte,
          chave do elemento atual
        move o cursor para o elemento seguinte
    */
    void printList() {
      Element* scopeCursor;
      scopeCursor = first;
      std::cout << "--------------------------------------------------------" << "\n";
      for (int i = 0; i < numElements; i++) {
        std::cout << scopeCursor->getPrevious() << " -- " << scopeCursor << " -- " << scopeCursor->getNext() << " -> " << scopeCursor->getKey() << "\n";
        scopeCursor = scopeCursor->getNext();
      }
    }
};

