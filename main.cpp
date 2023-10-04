#include <container_pair.h>
#include <string>

int main()
{
    Container_Pair<std::string, std::string> container(10);

    container.add(pair(std::string("Nina"), std::string("+7927655345611")));
    container.add(pair(std::string("Anna"), std::string("+79276553456")));

    container.add(pair(std::string("Anna"), std::string("+79276553456")) + pair(std::string("Nina"), std::string("+7927655345611")));

    container.print(std::cout);

    std::cout << "\n\nI search: " << container["Anna"] << "\n\n";
}