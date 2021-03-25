#include <iostream>
#include <vector>

class Stack {
private:
  std::vector<int> stack;
  int length = 0;

public:
  Stack();
  void push(int item);
  void pop();
  int top();
  int get_length();
  bool isempty();
};

Stack::Stack() {}

void Stack::push(int item) {
  this->stack.push_back(item);
  this->length++;
};

void Stack::pop() {
  if (this->length < 1)
    return;
  this->stack.pop_back();
  this->length--;
}

int Stack::top() {
  if (this->isempty())
    return 0;
  return this->stack[this->length - 1];
}

int Stack::get_length() { return this->length; }

bool Stack::isempty() { return this->length == 0; }

int main() {

  std::cout << "Creating Stack *test_stack = new Stack()" << std::endl;
  Stack *test_stack = new Stack();

  for (int i = 0; i < 5; i++) {
    std::cout << "Inserting " << i << " to test_stack -> test_stack->push(" << i
              << ");" << std::endl;
    test_stack->push(i);
  }

  std::cout << "Getting top value -> test_stack->top(): " << test_stack->top()
            << std::endl;

  std::cout << "Popping -> test_stack->pop();" << std::endl;
  test_stack->pop();
  std::cout << "Popping -> test_stack->pop();" << std::endl;
  test_stack->pop();
  std::cout << "Getting top value -> test_stack->top(): " << test_stack->top()
            << std::endl;

  std::cout << "Length -> test_stack->get_length(): "
            << test_stack->get_length() << std::endl;
  return 0;
}