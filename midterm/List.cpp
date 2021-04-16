#include <iostream>
#include "List.h"

List::List() { this->head = nullptr; }

List::~List() {
  Node *position = this->head;
  while (position->getNext() != nullptr) {
    Node *temp = position;
    position = position->getNext();
    delete temp;
    this->length--;
  }
}

Node *List::getHead() { return this->head; }

void *List::setHead(Node *head) { this->head = head; }

int List::getLength() { return this->length; }

void List::insert(int loc, std::string data) {
  // Do not allow insertions greater than the maximum length of the List
  if (loc < 0 || loc > this->length)
    throw "cannot insert to non existent position in List. Bounds [0, length]";

  // Create new node for future insertion
  Node *new_node = new Node(data);

  if (this->head == nullptr) {
    // Handle empty chain scenario
    this->head = new_node;
  } else if (loc == 0) {
    // Handle 0th position insertion scenario
    new_node->setNext(this->head);
    this->head = new_node;
  } else {
    // Handle custom location insertion scenario
    Node *position = this->head;
    while (loc > 1) {
      position = position->getNext();
      loc--;
    }
    new_node->setNext(position->getNext());
    position->setNext(new_node);
  }

  // Iterate length by 1
  this->length++;
}

void List::remove(int loc) {
  // Do not allow deletions greater than the maximum length of the List
  if (loc < 0 || loc >= this->length)
    throw "cannot remove from non existant position in List. Bounds [0, "
          "length)";

  if (loc == 0) {
    // Handle 0th position removal scenario
    Node *temp = this->head->getNext();
    delete this->head;
    this->head = temp;
  } else {
    // Handle custom position removal scenario with n-1 while loop
    Node *position = this->head;
    while (loc > 1) {
      position = position->getNext();
      loc--;
    }
    Node *temp = position->getNext()->getNext();
    delete position->getNext();
    position->setNext(temp);
  }

  // Iterate length by 1
  this->length--;
}

std::string List::get(int loc) {
  // Do not allow deletions greater than the maximum length of the List
  if (loc < 0 || loc >= this->length)
    throw "cannot get from non existant position in List. Bounds [0, length)";

  Node *position = this->head;
  while (loc > 0) {
    position = position->getNext();
    loc--;
  }

  return position->getData();
}

void List::insert(std::string data) {
  // Inserts to the end of tail simulating a push
  this->insert(this->length, data);
}

std::string List::toString() {
  std::string result = "head";
  Node *position = this->head;
  for (int i = 0; i < this->length; i++) {
    result += "-->" + position->getData();
    position = position->getNext();
  }
  return result + "-->nullptr";
}

void List::rotate(int position) {
  // Do not allow deletions greater than the maximum length of the List
  if (position < 1 || position > this->length)
    throw "cannot rotate from non existant position in List. Bounds [1, "
          "length)";

  // Lists of size 1 cannot be rotated
  if (this->length == 1)
    return;

  // Offset to account for Indexing
  position--;

  // Sort to the node at defined position
  Node *last_node = this->head;
  Node *new_head = this->head;
  Node *new_head_prev = nullptr;
  while (last_node->getNext() != nullptr) {
    last_node = last_node->getNext();
    if (position > 0) {
      new_head = new_head->getNext();
      new_head_prev = new_head;
      position--;
    }
  }

  Node *old_head = this->head;
  this->head = new_head;
  last_node->setNext(old_head);
}