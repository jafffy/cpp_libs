#include <any>
#include <iostream>

int main()
{
  std::cout << std::boolalpha;

  std::any a = 1;
  std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
  a = true;
  std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';

  try {
    a = 1;
    std::cout << std::any_cast<float>(a) << '\n';
  }
  catch (const std::bad_any_cast& e) {
    std::cout << e.what() << '\n';
  }

  a = 1;
  if (a.has_value()) {
    std::cout << a.type().name() << '\n';
  }

  a.reset();
  if (!a.has_value()) {
    std::cout << "no value\n";
  }

  a = 1;
  int* i = std::any_cast<int>(&a);
  std::cout << *i << '\n';

  return 0;
}
