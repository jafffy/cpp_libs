#include <iostream>
#include <csetjmp>

std::jmp_buf jump_buffer;

[[noreturn]] void a(int count)
{
  std::cout << "a(" << count << ") called\n";
  std::longjmp(jump_buffer, count+1);
}

int main()
{
  volatile int count = 0;
  if (setjmp(jump_buffer) != 0) {
    a(++count);
  }

  return 0;
}
