#include <iostream>
#include <string>
#include <vector>
#include "List.h"

int length(Node *l) {
  if (l == nullptr)
    return 0;
  int length = 0;
  while (l != nullptr) {
    length++;
    l = l->getNext();
  }
  return length;
}

Node *merge(Node *left, Node *right) {
  std::vector<int> merged;

  // check front values of both array and sort accordingly
  while (left.size() > 0 && right.size() > 0) {
    if (left.front() < right.front()) {
      merged.push_back(left.front());
      left.erase(left.begin());
    } else {
      merged.push_back(right.front());
      right.erase(right.begin());
    }
  }

  // push back any remaining values left over from initial sorting for odd
  // scenarios
  if (!left.empty()) {
    while (!left.empty()) {
      merged.push_back(left[0]);
      left.erase(left.begin());
    }
  } else {
    while (!right.empty()) {
      merged.push_back(right[0]);
      right.erase(right.begin());
    }
  }

  return merged;
}

Node *msort(Node *head) {
  // Check current head's length
  int chunk_size = length(head);
  if (list_size < 2)
    return head;

  // Split the head link into half
  int v_half = chunk_size / 2;
  std::vector<Node *> chunk1;
  std::vector<Node *> chunk2;

  Node *init_position = head;
  Node *middle_position = v_half;
  for (int i = 0; i < v_half; i++) {
    chunk1.push_back(init_position);
    chunk2.push_back(middle_position);
    init_position = init_position->getNext();
    middle_position = middle_position->getNext();
    head = head->getNext();
  }

  // Push stray element in odd scenarios to chunk2
  if (head != nullptr)
    chunk2.push_back(head);

  return merge(msort(chunk1.front()), msort(chunk2.front()));
}

int main() {

  // Note! See List.cpp method List->rotate(int position) for source

  // Define dataset
  int dataset[] = {6, 30, 0, 55, 22, 17, 12};

  // Convert dataset into Node List
  List *data_list = new List();
  for (int i = 0; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
    data_list->insert(std::to_string(dataset[i]));
  }

  std::cout << "Demonstrating correct rotate() method implementation:"
            << std::endl
            << std::endl;
  std::cout << "data_list->toString():" << std::endl;
  std::cout << data_list->toString() << std::endl;

  std::cout << "data_list->rotate(5);" << std::endl;
  data_list->rotate(5);

  std::cout << "data_list->toString():" << std::endl;
  std::cout << data_list->toString() << std::endl << std::endl;

  std::cout << "Demonstrating correct merge() mergesort implementation:"
            << std::endl
            << std::endl;

  int dataset_a[] = {6, 30, 0, 55, 22, 17, 12};
  int dataset_b[] = {2, 40, 9, 95, 32, 67, 52};
  List *data_list_a = new List();
  List *data_list_b = new List();

  for (int i = 0; i < sizeof(dataset_a) / sizeof(dataset_a[0]); i++) {
    data_list_a->insert(std::to_string(dataset_a[i]));
  }

  for (int i = 0; i < sizeof(dataset_b) / sizeof(dataset_b[0]); i++) {
    data_list_b->insert(std::to_string(dataset_b[i]));
  }

  std::cout << "data_list_a->toString():" << std::endl;
  std::cout << data_list_a->toString() << std::endl;
  std::cout << "data_list_b->toString():" << std::endl;
  std::cout << data_list_b->toString() << std::endl;
}
