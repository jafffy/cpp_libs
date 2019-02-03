#include <iostream>
#include <chrono>
#include <thread>

int main()
{
  using namespace std::chrono_literals;
  std::cout << "Hello waiter\n";
  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(2s);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;
  std::chrono::duration<double> elapsed_in_sec = end - start;
  std::cout << "Waited " << elapsed.count() << " ms\n";
  std::cout << "Waited " << elapsed_in_sec.count() << " ms\n";

  return 0;
}
