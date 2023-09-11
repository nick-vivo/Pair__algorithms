#include <container_pair.h>
#include <iostream>
#include <string>

int main()
{
    Container_Pair<std::string, int> cont(5);
    
    cont.add( pair<std::string, int> ("123", 1) );

    //std::cout << cont.verification(pair<std::string, int> ("123", 2));

    cont.print(std::cout);

    return 1;
}