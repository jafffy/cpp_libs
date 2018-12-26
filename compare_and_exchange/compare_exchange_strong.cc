#include <atomic>
#include <iostream>

std::atomic<int> ai;

int tst_val = 4;
int new_val = 5;
bool exchanged = false;

void valsout()
{
  std::cout << "ai= " << ai
            << "  tst_val= " << tst_val
            << "  new_val= " << new_val
            << "  exchanged= " << std::boolalpha << exchanged
            << "\n";
}

int main()
{
  ai = 3;
  valsout();

  exchanged = ai.compare_exchange_strong(tst_val, new_val);
  valsout();

  exchanged = ai.compare_exchange_strong(tst_val, new_val);
  valsout();

  return 0;
}
