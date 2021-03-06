#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

template <typename Container>
bool in_quote(const Container& cont, const std::string& s)
{
  return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

int main()
{
  return 0;
}
