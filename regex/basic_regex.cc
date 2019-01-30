#include <iostream>
#include <regex>

int main()
{
  std::regex r1{"abcde"};
  std::cout << "r1 has " << r1.mark_count() << " subexpressions" << '\n';

  std::regex r2{"ab(c)de"};
  std::cout << "r2 has " << r2.mark_count() << " subexpressions" << '\n';

  std::regex r3{"a(bc)d(e)"};
  std::cout << "r3 has " << r3.mark_count() << " subexpressions" << '\n';

  std::regex r4{"abc(de(fg))"};
  std::cout << "r4 has " << r4.mark_count() << " subexpressions" << '\n';

  std::regex r5{"a(bc\\(\\)de)"};
  std::cout << "r5 has " << r5.mark_count() << " subexpressions" << '\n';
 
  std::regex r6{"ab(c)de", std::regex_constants::nosubs};
  std::cout << "r6 has " << r6.mark_count() << " subexpressions" << '\n';

  return 0;
}
