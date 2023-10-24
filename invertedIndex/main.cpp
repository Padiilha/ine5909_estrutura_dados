#include <iostream>

#include "arrayList.hpp"
#include "invertedIndex.hpp"

struct Object {
  int id;
  string nome;
  string curso;
  string semestre_ingresso;
  string cidade_origem;

  Object(
    int i,
    string n,
    string c,
    string si,
    string co
  ) : id(i),
      nome(n),
      curso(c),
      semestre_ingresso(si),
      cidade_origem(co) {}
};

using namespace std;
int main(void){
  int acao, diretorioId;
  string curso, semestre, cidade;

  cout << "Trabalho Final - Lista Invertida" << endl;
  cout << endl;
  
  while (acao != 0) {
    cout << "Digite a ação que deseja realizar" << endl;
    cout << "0 -> encerrar programa" << endl;
    cout << "1 -> carga de dados" << endl;
    cout << "2 -> busca simples" << endl;
    cout << "3 -> busca composta" << endl;
    cout << "4 -> inclusão de elemento" << endl;
    cout << "5 -> remoção de elemento" << endl;
    cout << "6 -> exibir todos os dados" << endl;
    cin >> acao;

    switch (acao) {
      case 1: // carga de dados
        cout << endl << "Carga de Dados" << endl;
        ArrayList<Object>* documento = new ArrayList<Object>(8);
        documento->insert(
          "Cauã Padilha",
          "Sistemas de Informação",
          "22.1",
          "Joinville"
        );
        documento->insert(
          "Arthur Winck",
          "Ciências da Computação",
          "19.2",
          "Caxias do Sul"
        );
        documento->insert(
          "Laís Coelho",
          "Enfermagem",
          "17.1",
          "Florianópolis"
        );
        documento->insert(
          "Lucas Pasti",
          "Sistemas de Informação",
          "22.1",
          "Joinville"
        );
        documento->insert(
          "Christian Aurich",
          "Sistemas de Informação",
          "18.2",
          "Florianópolis"
        );
        documento->insert(
          "Laura Bertassi",
          "Sistemas de Informação",
          "20.2",
          "Caxias do Sul"
        );

        // criacao dos diretorios
        InvertedIndex* listaInvertida = new InvertedIndex(
          documento, [
            cursos,
            semestres,
            cidades
          ]
        );

        cout << "carga de dados realizada!" << endl;
        break;
      case 2: // busca simples
        cout << endl << "Busca Simples" << endl;
        cout << "1 -> curso" << endl;
        cout << "2 -> semestre de ingresso" << endl;
        cout << "3 -> cidade" << endl;
        cout << "Digite o diretório que deseja utilizar na busca: ";
        cin >> diretorioId;

        switch(diretorioId) {
          case 1:
            cout << "Qual curso gostaria de buscar?" << endl;
            //cursos = listaInvertida->getId(curso);
            cursos = [
              "Sistemas de Informação",
              "Ciência da Computação",
              "Enfermagem"
            ];
            for (int i = 0; i < 3; i++) {
              cout << i << " -> " << cursos[i] << endl;
            }
            cin >> curso;
            listaInvertida->simpleSearch(1, curso);
            break;
          case 2:
            cout << "Qual semestre de ingresso gostaria de buscar?" << endl;
            //semestres = listaInvertida->getId(semestre);
            semestres = [
              "17.1",
              "18.2",
              "19.2",
              "20.2",
              "22.1"
            ];
            for (int i = 0; i < 5; i++) {
              cout << i << " -> " << semestres[i] << endl;
            }
            cin >> semestre;
            listaInvertida->simpleSearch(2, semestre);
            break;
          case 3:
            cout << "Qual cidade gostaria de buscar?" << endl;
            //cidades = listaInvertida->getId(cidade);
            cidades = [
              "Joinville",
              "Caxias do Sul",
              "Florianópolis"
            ];
            for (int i = 0; i < 3; i++) {
              cout << i << " -> " << cidades[i] << endl;
            }
            cin >> cidade;
            listaInvertida->simpleSearch(3, cidade);
            break;
          default:
            cout << "Diretório não localizado" << endl;
            break;
        }
      case 3:
      case 4:
      case 5:
      case 6:
      default:
    }
  }

  // Hash* diretorio_curso = new Hash();
  // for (int i = 0; i < 8; i++) {
  //   Object* reg = documento->access(i);
  //   diretorio_curso->insert(curso, reg)
  // }

  // Hash* diretorio_semestre = new Hash();
  // for (int i = 0; i < 8; i++) {
  //   Object* reg = documento->access(i);
  //   diretorio_semestre->insert(semestre, reg)
  // }

  // Hash* diretorio_cidade = new Hash();
  // for (int i = 0; i < 8; i++) {
  //   Object* reg = documento->access(i);
  //   diretorio_cidade->insert(cidade, reg)
  // }
  
  // busca composta
  listaInvertida->multiSearch(
    diretorio1,
    termoToSearch1,
    diretorio2,
    termoToSearch2
  );

  // insercao de novos valores
  documento->insert(nome, curso, semestre_ingresso, cidade_origem);
  delete listaInvertida;

  // remocao de valor
  documento->remove(id);
  delete listaInvertida;

  // exibir todos os dados
  for (int i = 0; i < 8; i++) {
    documento->access();
  }
}