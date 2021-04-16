#pragma once

#include "Node.h"

class List {
private:
  Node *head;
  int length = 0;

public:
  ~List();
  List();
  std::string get(int loc);
  void insert(std::string data);
  void insert(int loc, std::string data);
  void remove(int loc);
  void rotate(int position);
  int getLength();
  Node *getHead();
  void setHead(Node *head);
  std::string toString();
};