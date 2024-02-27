#include <vector>
#include "MySorts.hpp"
#include "Utils.hpp"

int main()
{
    std::vector<size_t> vecptr;
    MySorts::Generator<std::vector<size_t> , 10000000 >::run(vecptr);
    MySorts::Duration::start();
    auto vecptr2 = vecptr;
    std::cout << "Copy  time   = " << MySorts::Duration::end() << std::endl;
    // for (auto &v: vecptr)
    // {
    //     std::cout << v << std::endl;
    // }

    MySorts::Duration::start();
    MySorts::heap<size_t>(vecptr.begin(), vecptr.end());
    std::cout << "My sort time = " << MySorts::Duration::end() << std::endl;

    MySorts::Duration::start();
    std::sort(vecptr2.begin(), vecptr2.end());
    std::cout << "Sort time    = " << MySorts::Duration::end() << std::endl;

    // for (auto &v: vecptr)
    // {
    //     std::cout << v << std::endl;
    // }
    return 0;
}