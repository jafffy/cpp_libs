#include <variant>
#include <string>
#include <cassert>

int main()
{
  std::variant<int, float> v, w;
  v = 12;
  int i = std::get<int>(v);
  w = std::get<int>(v);
  w = std::get<0>(v);
  w = v;

  try {
    std::get<float>(w);
  }
  catch (const std::bad_variant_access&) {}

  using namespace std::literals;

  std::variant<std::string> x("abc");
  x = "def";

  std::variant<std::string, void const*> y("abc");

  assert(std::holds_alternative<void const*>(y));

  y = "xyz"s;
  assert(std::holds_alternative<std::string>(y));

  return 0;
}
