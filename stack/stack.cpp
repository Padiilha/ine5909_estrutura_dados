#include <stdio.h>
#include <iostream>

int main(void){
    class stack{
        public:
            int top = -1, maxElements;
            int* array;

            stack(int maxEl){
                maxElements = maxEl;
                //int arr[maxElements];
                array = (int*)malloc(sizeof(int)*maxElements);
                //array = arr;
            }

            void push(int valor){
                if (!fullStack()){
                    std::cout << "top:" << top << "\n";
                    array[top + 1] = valor;
                    top++;
                }
            }

            int pop(){
                if (!emptyStack()){
                    std::cout << top;
                    int popVal = array[top];
                    top--;
                    return popVal;
                }
            }

            bool emptyStack(){
                return (numElements() == 0);
            }

            bool fullStack(){
                return (numElements() == maxElements);
            }

            int numElements(){
                return top + 1;
            }

            int stackTop(){
                if (!emptyStack()){
                    return array[top];
                }
            }
    };

    int maxElements, valor, acao;

    std::cout << "Insira o tamanho da pilha: ";
    std::cin >> maxElements;
    stack pilha(maxElements);

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
                pilha.push(valor);
                break;
        
            case 2:
                valor = pilha.pop();
                std::cout << "O valor " << valor << " foi retirado do topo da pilha\n";
                break;
        }
    }
}