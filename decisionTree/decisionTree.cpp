#include <iostream>
#include <string>

struct Node {
  std::string content;
  Node* left;
  Node* right;

  Node(std::string cnt) : content(cnt), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* node, std::string cnt) {
  if (node == nullptr)
    return new Node(cnt);
  
  node->left = insertNode(node->left, cnt);
  
  return node;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    return newRoot;
}

Node* findAnimal(Node* root) {
  char answer;

  if (root == nullptr)
    return NULL;
  
  while (root->right != nullptr || root->right != nullptr) {
    std::cout << "Seu animal " << root->content << "? (S/N) "; // pergunta caracteristica
    std::cin >> answer;

    switch (answer) {
      case 'S':
        findAnimal(root->right);
        return root->right;    
      case 'N':
        findAnimal(root->left);
        return root->left;
      default:
        break;
    }
  }
  return root;
}

int main() {
  Node* root = nullptr;
  char answer;
  std::string thoughtAnimal;
  std::string difference;

  root = insertNode(root, "baleia");

  while (answer != 'S') {
    std::cout << "Pense em um animal" << std::endl;
    
    Node* foundAnimal = findAnimal(root);
    std::cout << "Seu animal é " << foundAnimal->content << "? (S/N) "; // pergunta animal
    std::cin >> answer;

    switch(answer){
      case 'S':
        std::cout << "Isso! Consegui outra vez xD" << std::endl;
        break;
      case 'N':
        std::cout << "Qual animal você pensou?" << std::endl;
        std::cin >> thoughtAnimal;
        std::cout << "O que diferencia " << foundAnimal->content << " de " << thoughtAnimal << "?" << std::endl;
        std::cin >> difference;

        insertNode(foundAnimal, difference);
        insertNode(foundAnimal->left, thoughtAnimal);
        root = rotateRight(foundAnimal);
        break;
      default:
        break;
    }
  }
  return 0;
}