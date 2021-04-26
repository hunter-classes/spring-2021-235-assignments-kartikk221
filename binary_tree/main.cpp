#include <iostream>
using namespace std;

// Node Structure
struct Node {
  int data;
  int size;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = nullptr;
    this->right = nullptr;
    this->size = 0;
  }
};

void btree_insert(Node *&root, int data) {
  if (root == nullptr) {
    root = new Node(data);
  } else {
    if (data < root->data) {
      btree_insert(root->left, data);
    } else {
      btree_insert(root->right, data);
    }
  }
}

void printBT(const string &prefix, const Node *node, bool isLeft) {
  if (node != nullptr) {

    cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    cout << node->data << endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

void printBT(const Node *node) { printBT("", node, false); }

int main() {
  Node *tree = new Node(1);
  btree_insert(tree, 2);
  btree_insert(tree, 3);
  btree_insert(tree, 4);
  btree_insert(tree, 5);
  btree_insert(tree, 6);
  printBT(tree);
  return 0;
}