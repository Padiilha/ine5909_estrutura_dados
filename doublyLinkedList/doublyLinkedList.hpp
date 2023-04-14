#include "element.hpp"

template<typename T>
class DoublyLinkedList {
  private:
    int maxElements, numElements, position;
    T* first, fake, cursor;

    // cursor methods
    void advanceNPositions(int n) {
      if (!emptyList()) {
        for (i = 0; i < n; i++) {
          cursor = &cursor.getNext();
          position++;
        }
        position = position % numElements;
      } else {
        throw ...
      }
    }

    void recedeNPositions(int n) {
      if (!emptyList()) {
        for (i = 0; i < n; i++) {
          cursor = &cursor.getPrevious();
          position--;
        }
        position = position % numElements;
      } else {
        throw ...
      }
    }

    void goFirst() {
      cursor = &first;
    }

    void goLast() {
      cursor = &first.getPrevious();
    }

    // auxiliar methods
    bool emptyList() {
      return (first == NULL && last == NULL);
    }

    bool fullList() {
      return (numElements == maxElements);
    }

    int positionOf(int key) {
      if (search(key)) {
        return position;
      } else {
        throw ...
      }
    }

  public:
    DoublyLinkedList() {}

    DoublyLinkedList<int>(int maxEl) {
      maxElements = maxEl;
    }

    ~DoublyLinkedList() {
      delete[];
    }
    
    // list methods

    /*
      Funcao acessCurrent()
      retorna o valor do cursor, o elemento
    */
    Element accessCurrent() {
      return *cursor;
    }

    /*
      Funcao insertBeforeCurrent()
      se a lista estiver vazia: usa a funcao insertEmpty() para inserir o primeiro elemento na lista;
      se não se a lista estiver cheia: lanca uma excessao;
      se não:
        cria um novo elemento com os parametros:
          chave recebida,
          setta o anterior com o endereco do elemento anterior ao cursor
          setta o proximo com o endereco do elemento em que o cursor esta
        adiciona o numero de elementos
    */
    void insertBeforeCurrent(int key) {
      if (emptyList()) {
        insertEmpty(key);
      } else if (fullList()) {
        throw ...
      } else {
        Element newElement(key, &cursor.getPrevious(), &cursor);
        numElements++;
      }
    }

    /*
      Funcao insertAfterCurrent()
      se a lista estiver vazia: usa a funcao insertEmpty() para inserir o primeiro elemento na lista;
      se não se a lista estiver cheia: lanca uma excessao;
      se não:
        cria um novo elemento com os parametros:
          chave recebida,
          setta o anterior com o endereco do elemento em que o cursor esta
          setta o proximo com o endereco do elemento com o elemento seguinte ao cursor
        adiciona o numero de elementos
    */
    void insertAfterCurrent(int key) {
      if (emptyList()) {
        insertEmpty(key);
      } else if (fullList()) {
        throw ...
      } else {
        Element newElement(key, &cursor, &cursor.getNext());
        cursor = &newElement; // set cursor to point to new element
        numElements++;
      }
    }

    /*
      Funcao insertEmpty()
      cria um novo elemento com a chave recebida e com o anterior e o sucessor nulos
      setta o endereco do novo elemento como first
      setta o elemento anterior do novo elemento o endereco de first
      setta o elemento seguinte do novo elemento o endereco de first
      setta o cursor com o endereco de first
      adiciona o numero de elementos
    */
    void insertEmpty(int key) {
      Element newElement(key, NULL, NULL);
      first = &newElement;
      first.setPrevious(&first);
      first.setNext(&first);
      cursor = &first;
      numElements++;
    }

    /*
      Funcao insertFirst()
      usa a funcao goFirst() para settar o cursor na primeira posicao
      usa a funcao insertBeforeCurrent() para adicionar o elemento na posicao anterior ao primeiro
      setta o first com o endereco do elemento anterior do cursor, o novo elemento
    */
    void insertFirst(int key) {
      goFirst();
      insertBeforeCurrent(key);
      first = &cursor.getPrevious();
    }

    /*
      Funcao insertLast()
      usa a funcao goLast() para settar o cursor na ultima posicao
      usa a funcao insertAfterCurrent() para adicionar o elemento na posicao seguinte ao ultimo
    */
    void insertLast(int key) {
      goLast();
      insertAfterCurrent(key);
    }

    void insertInPosition(int pos) {}

    /*
      Funcao deleteCurrent()
      verifica se a lista nao esta vazia, se estiver: lanca uma excessao; se nao estiver:
        setta como proximo elemento do elemento anterior do cursor o elemente seguinte ao cursor
        setta como elemento anterior do elemento seguinte do cursor o elemento anterior ao cursor
        move o cursor para o elemento seguinte
        subtrai o numero de elementos
    */
    void deleteCurrent() {
      if (!emptyList()) {
        cursor.getPrevious().setNext(&cursor.getNext());
        cursor.getNext().setPrevious(&cursor.getPrevious());
        cursor = &cursor.getNext(); // set cursor to point to next element
        numElements--;
      } else {
        throw ...
      }
    }

    /*
      Funcao deleteFirst()
      usa a funcao goFirst() para settar o cursor na primeira posicao
      usa a funcao deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a primeira
    */
    void deleteFirst() {
      goFirst();
      deleteCurrent();
    }

    /*
      Funcao deleteLast()
      usa a funcao goLast() para settar o cursor na ultima posicao
      usa a funcao deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a ultima
    */
    void deleteLast() {
      goLast();
      deleteCurrent();
    }

    /*
      Funcao deleteElement()
      verifica se a lista nao esta vazia, se estiver: lanca uma excessao; se nao estiver:
        verifica se o elemento existe na lista, se nao estiver, lanca uma excessao, se estiver:
          usa a funcao deleteCurrent() para apagar o elemento na posicao que o cursor esta, no caso a do elemento desejado (foi settado enquanto fazia a busca pelo elemento)
    */
    void deleteElement(int key) {
      if (!emptyList()) {
        if (search(key)) {
          deleteCurrent();
        } else {
          throw ...
        }
      } else {
        throw ...
      }
    }

    void deleteFromPosition(int pos) {}

    bool search(int key) {
      // creating element fake to optimize search
      Element fake(key, NULL, NULL);
      first.getPrevious().setNext(&fake);

      // searching for element in List
      goFirst();
      while (cursor.getKey() != key) {
        advanceNPositions(1);
      }
      if (cursor != fake) {
        first.getPrevious().setNext(&first);
        return true;
      } else {
        first.getPrevious().setNext(&first);
        goLast();
        return false;
      }
    }
};

