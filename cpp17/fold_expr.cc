#include <iostream>

template<typename... Args>
bool all(Args... args) { return (... && args); }

int main() {
  std::cout << std::boolalpha;

  std::cout << "all(): " << all() << '\n';
  std::cout << "all(true): " << all(true) << '\n';
  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << '\n';

  return 0;
}
