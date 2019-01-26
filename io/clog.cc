#include <iostream>

struct Foo {
  int n;

  Foo() {
    std::clog << "static constructor\n";
  }

  ~Foo() {
    std::clog << "static destructor\n";
  }
};

Foo f;

int main()
{
  std::cout << "main function\n";
}
