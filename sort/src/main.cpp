#include <vector>
#include "MySorts.hpp"
#include "Utils.hpp"

int main()
{
    std::vector<size_t> vecptr;
    MySorts::Generator<std::vector<size_t> , 1000000 >::run(vecptr);
    MySorts::Duration::start();
    MySorts::heap(vecptr.begin(), vecptr.end());
    for (auto &v: vecptr)
    {
        std::cout << v << std::endl;
    }

    std::cout << "time = " << MySorts::Duration::end() << std::endl;
    
    return 0;
}