#include <iostream>
#include <cwchar>
#include <memory>
#include <clocale>

int main()
{
  const wchar_t* src = L"개 means dog";
  auto dst = std::make_unique<wchar_t[]>(std::wcslen(src) + 1);
  std::wcscpy(dst.get(), src);
  dst[0] = L'뷁';
  std::setlocale(LC_ALL, "en_US.utf8");
  std::wcout.imbue(std::locale(""));
  std::wcout << src << '\n' << dst.get() << '\n';

  return 0;
}
