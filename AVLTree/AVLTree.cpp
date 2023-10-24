#include <iostream>

// Definição da estrutura do nó da árvore AVL
struct Node {
  int key;
  int height;
  Node* left;
  Node* right;

  Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Função para obter a altura de um nó
int getHeight(Node* node) {
  if (node == nullptr)
    return 0;
  return node->height;
}

// Função para obter o fator de balanceamento de um nó
int getBalanceFactor(Node* node) {
  if (node == nullptr)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

// Função para atualizar a altura de um nó
void updateHeight(Node* node) {
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);
  node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Função para realizar uma rotação simples à direita
Node* rotateRight(Node* node) {
  Node* newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;

  updateHeight(node);
  updateHeight(newRoot);

  return newRoot;
}

// Função para realizar uma rotação simples à esquerda
Node* rotateLeft(Node* node) {
  Node* newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;

  updateHeight(node);
  updateHeight(newRoot);

  return newRoot;
}

// Função para balancear um nó e sua subárvore
Node* balanceNode(Node* node) {
  updateHeight(node);

  if (getBalanceFactor(node) == 2) {
    if (getBalanceFactor(node->left) < 0)
      node->left = rotateLeft(node->left);
    return rotateRight(node);
  }
  if (getBalanceFactor(node) == -2) {
    if (getBalanceFactor(node->right) > 0)
      node->right = rotateRight(node->right);
    return rotateLeft(node);
  }
  return node;
}

// Função para inserir um nó na árvore AVL
Node* insertNode(Node* root, int key) {
  if (root == nullptr)
    return new Node(key);
  if (key < root->key)
    root->left = insertNode(root->left, key);
  else if (key > root->key)
    root->right = insertNode(root->right, key);
  else
    return root; // Não são permitidas chaves duplicadas

  return balanceNode(root);
}

// Função para encontrar o nó com a chave mínima
Node* findMinNode(Node* node) {
  while (node->left != nullptr)
    node = node->left;
  return node;
}

// Função para remover um nó da árvore AVL
Node* removeNode(Node* root, int key) {
  if (root == nullptr)
    return nullptr;

  if (key < root->key)
    root->left = removeNode(root->left, key);
  else if (key > root->key)
    root->right = removeNode(root->right, key);
  else {
    if (root->left == nullptr || root->right == nullptr) {
      Node* temp = root->left ? root->left : root->right;
      if (temp == nullptr) {
        temp = root;
        root = nullptr;
      } else {
        *root = *temp;
      }
      delete temp;
    } else {
      Node* minRight = findMinNode(root->right);
      root->key = minRight->key;
      root->right = removeNode(root->right, minRight->key);
    }
  }

  if (root == nullptr)
    return nullptr;
  return balanceNode(root);
}

// Função para imprimir a árvore AVL em ordem
void printInOrder(Node* root) {
  if (root == nullptr)
    return;

  printInOrder(root->left);
  std::cout << root->key << " ";
  printInOrder(root->right);
}

// Função principal (exemplo de uso)
int main() {
    Node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    std::cout << "Árvore AVL em ordem: ";
    printInOrder(root);
    std::cout << std::endl;

    root = removeNode(root, 30);

    std::cout << "Árvore AVL após remover o nó 30: ";
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}
