#include <iostream>
using namespace std;

// Node Structure
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *btree_insert(Node *&root, int value) {
  // Handle empty root scenario
  if (!root)
    return new Node(value);

  if (value > root->data) {
    // Process right nodes when greater than root
    root->right = btree_insert(root->right, value);
  } else {
    // Process left nodes when less than root
    root->left = btree_insert(root->left, value);
  }

  return root;
}

// Determines and returns left most (smallest) node
Node *btree_min_node(Node *node) {
  Node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

Node *btree_delete(struct Node *root, int data) {
  // Handle base case for recursion - null root
  if (root == NULL)
    return root;

  // traverse down left subtree as data is smaller than parent/relative_root
  if (data < root->data) {
    root->left = btree_delete(root->left, data);
  } else if (data > root->data) {
    // traverse down right subtree as data is greater than parent/relative_root
    root->right = btree_delete(root->right, data);
  } else {
    // Found target data node - begin deletion process

    // Handle one child/no child node scenario
    if (root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // Get smallest node in right subtree
    Node *temp = btree_min_node(root->right);

    // Copy data from smallest node to successor root
    root->data = temp->data;

    // Delete the min node successor
    root->right = btree_delete(root->right, temp->data);
  }

  return root;
}

#define COUNT 5

void btree_print_recur(Node *root, int space) {
  // Handle root null scenario
  if (root == NULL)
    return;

  space += COUNT;

  // Process with right bias
  btree_print_recur(root->right, space);

  // Add padding horizontally for visualization
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << " ";
  cout << root->data << "\n";

  // Process left nodes
  btree_print_recur(root->left, space);
}

// Wrapper over btree_print_recur()
void btree_print(Node *root) { btree_print_recur(root, 0); }

int btree_count_leaves(Node *root) {
  // Handle base case
  if (root == NULL)
    return 0;

  // Handle no children case
  if (root->left == NULL && root->right == NULL) {
    return 1;
  } else {
    // Recursively count and add leaves from both subtrees
    return btree_count_leaves(root->left) + btree_count_leaves(root->right);
  }
}

int btree_level_count(Node *root, int target_level, int current_level = 1) {
  // Handle no children scenario
  if (root == NULL)
    return 0;

  // Recursively search subtrees and add result
  if (current_level < target_level) {
    return btree_level_count(root->left, target_level, current_level + 1) +
           btree_level_count(root->right, target_level, current_level + 1);
  }

  return 1;
}

int btree_count(Node *root) {
  // Handle empty root scenario
  if (root == NULL)
    return 0;
  // Recursively search further and count self as 1 depth
  return 1 + btree_count(root->left) + btree_count(root->right);
}

int btree_depth(Node *node) {
  // Handle base case
  if (node == NULL)
    return 0;

  // Compute sub-depth of both sides
  int left_depth = btree_depth(node->left);
  int right_depth = btree_depth(node->right);

  // To count absolute depth, return the larger side sub-depth + 1
  if (left_depth > right_depth)
    return (left_depth + 1);
  else
    return (right_depth + 1);
}

int main() {
  cout << "Creating Binary Tree & Populating..." << endl;
  Node *tree = new Node(1);
  btree_insert(tree, 2);
  btree_insert(tree, 8);
  btree_insert(tree, 3);
  btree_insert(tree, -6);
  btree_insert(tree, 21);
  btree_insert(tree, -7);
  btree_insert(tree, -68);

  cout << "Tree Node Count: " << btree_count(tree) << endl;
  cout << "Tree Leaves Count: " << btree_count_leaves(tree) << endl;
  cout << "Nodes Count @ Level 4: " << btree_level_count(tree, 4) << endl;
  cout << "Tree Depth: " << btree_depth(tree) << endl;
  cout << "Printing Tree: " << endl;
  btree_print(tree);

  btree_delete(tree, 3);
  btree_delete(tree, 2);
  btree_delete(tree, -68);
  cout << "Deleted 3" << endl;
  cout << "Deleted 2" << endl;
  cout << "Deleted -68" << endl;

  cout << "Tree Node Count: " << btree_count(tree) << endl;
  cout << "Tree Leaves Count: " << btree_count_leaves(tree) << endl;
  cout << "Nodes Count @ Level 3: " << btree_level_count(tree, 3) << endl;
  cout << "Tree Depth: " << btree_depth(tree) << endl;
  cout << "Printing Tree: " << endl;
  btree_print(tree);

  return 0;
}