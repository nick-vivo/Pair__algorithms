#include <pair.h>
#include <iostream>
#include <string.hpp>

int main()
{
    
    pair a(mstd::string("123"), 3);
    std::cout << a.key().c_str() << " " << a.value();

}