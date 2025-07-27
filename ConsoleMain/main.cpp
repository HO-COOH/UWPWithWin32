#include "pch.h"
#include <iostream>
using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls! Press enter to exit\n", uri.AbsoluteUri().c_str());
    std::cin.get();
}
