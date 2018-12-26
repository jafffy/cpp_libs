#include <atomic>

template <typename T>
struct node
{
  T data;
  node* next;
  node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class stack
{
  std::atomic<node<T>*> head;

public:
  void push(const T& data)
  {
    node<T>* new_node = new node<T>(data);

    new_node->next = head.load(std::memory_order_relaxed);

    while (!head.compare_exchange_weak(new_node->next, new_node,
          std::memory_order_release,
          std::memory_order_relaxed));
  }
};

int main()
{
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  return 0;
}
