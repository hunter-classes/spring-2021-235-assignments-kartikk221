#include <iostream>
#include <vector>

class Queue {
private:
  std::vector<int> queue;
  int length = 0;

public:
  Queue();
  void enqueue(int item);
  void dequeue();
  bool isEmpty();
  int front();
  int get_length();
};

Queue::Queue() {}

void Queue::enqueue(int item) {
  this->queue.push_back(item);
  this->length++;
}

void Queue::dequeue() {
  if (this->isEmpty())
    return;
  this->queue.erase(this->queue.begin());
  this->length--;
}

bool Queue::isEmpty() { return this->length == 0; }

int Queue::front() { return this->queue[0]; }

int Queue::get_length() { return this->length; }

int main() {

  std::cout << "Creating Queue -> Queue *test_queue = new Queue();"
            << std::endl;
  Queue *test_queue = new Queue();

  for (int i = 0; i < 5; i++) {
    std::cout << "Adding " << i << " to test_queue -> test_queue->enqueue(" << i
              << ");" << std::endl;
    test_queue->enqueue(i);
  }

  std::cout << "Getting front value -> test_queue->front(): "
            << test_queue->front() << std::endl;

  std::cout << "Removing From Queue -> test_queue->dequeue();" << std::endl;
  test_queue->dequeue();
  std::cout << "Removing From Queue Again -> test_queue->dequeue();"
            << std::endl;
  test_queue->dequeue();
  std::cout << "Getting Front value -> test_queue->front(): "
            << test_queue->front() << std::endl;

  std::cout << "Length -> test_queue->get_length(): "
            << test_queue->get_length() << std::endl;

  return 0;
}