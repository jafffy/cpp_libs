#include <algorithm>
#include <execution>
#include <vector>

int main()
{
  int a[] = {0,1};
  std::vector<int> v;

  std::for_each(std::execution::par, std::begin(a), std::end(b), [&](int i) {
      v.push_back(i*2+1);
      });

  return 0;
}
