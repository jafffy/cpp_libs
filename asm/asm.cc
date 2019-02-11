#include <iostream>

extern "C" int func(); // CHECK: Why should use extern "C" to use asm in C++?

// Raw string literal
asm(R"(
.global func
  .type func, @function
  func:
  .cfi_startproc
  movl $7, %eax
  ret
  .cfi_endproc
)");

int main()
{
  int n = func();

  asm ("leal (%0,%0,4),%0"
       : "=r" (n)
       : "0" (n));
  std::cout << "7*5 = " << n << std::endl;

  asm ("movq $60, %rax\n\t"
       "movq $2 , %rdi\n\t"
       "syscall");

  return 0;
}
