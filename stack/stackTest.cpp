#include <stdio.h>
#include <iostream>
#include "stack.hpp"

int main(void){
    int maxElements, valor, acao;

    std::cout << "Insira o tamanho da pilha: ";
    std::cin >> maxElements;
    Stack<int> pilha(maxElements);

    while(acao != 0){
        std::cout << "Digite a ação que deseja realizar:\n";
        std::cout << "0. encerrar programa\n";
        std::cout << "1. empilhar\n";
        std::cout << "2. desempilhar\n";
        std::cin >> acao;
        switch (acao){
            case 1:
                std::cout << "Digite o valor que deseja empilhar: ";
                std::cin >> valor;
                try{
                    pilha.push(valor);
                } catch (int) {
                    std::cout << "Stack overflow\n";
                }
                break;
        
            case 2:
                try {
                    valor = pilha.pop();
                    std::cout << "O valor " << valor << " foi retirado do topo da pilha\n";
                } catch (int) {
                    std::cout << "Stack empty\n";
                }
                break;
        }
    }
}