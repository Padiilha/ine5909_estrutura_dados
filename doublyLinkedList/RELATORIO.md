# Lista Duplamente Encadeada

## Visão Geral

Este projeto implementa o comportamento de uma lista duplamente encadeada em C++ e contém três arquivos:

> - **element.hpp**
> - **doublyLinkedList.hpp**
> - **main.cpp**

O arquivo de header `element.hpp` implementa a classe Element, que contém os métodos e atributos do Elemento.

O arquivo de header `doublyLinkedList.hpp` implementa a classe DoublyLinkedList, que é o escopo principal deste projeto e usa a classe Element.

O arquivo `main.cpp` usa a classe DoublyLinkedList e demonstra os seus métodos na prática

## Métodos Criados

### Element

> - **getKey()**
> - **setPrevious()**
> - **getPrevious()**
> - **setNext()**
> - **getNext()**

### DoublyLinkedList

#### Métodos da lista

##### Inserção

> - **insertEmpty()** (privado)
> - **insertBeforeCurrent()**
> - **insertAfterCurrent()**
> - **insertFirst()**
> - **insertLast()**
> - **insertInPosition()**

##### Remoção

> - **deleteCurrent()**
> - **deleteFirst()**
> - **deleteLast()**
> - **deleteElement()**
> - **deleteFromPosition()**

##### Acesso

> - **accessCurrent()**
> - **search()**

##### Impressão

> - **printList()**

#### Métodos do cursor

> - **advanceNPositions()**
> - **recedeNPositions()**
> - **goFirst()**
> - **goLast()**
> - **goToPosition()**

#### Métodos Auxiliares

> - **emptyList()**
> - **fullList()**
> - **positionOf()**