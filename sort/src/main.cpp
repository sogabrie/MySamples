#include <vector>
#include "MySorts.hpp"
#include "Utils.hpp"
#include "forward_list"

int main()
{
{
    std::vector<size_t> vecptr;
	// std::forward_list<size_t> flis1, flis2;
    MySorts::Generator<std::vector<size_t> , 1'000'000 >::run(vecptr);
    MySorts::Duration::start();
    auto vecptr2 = vecptr;
	auto vecptr1 = vecptr;
	std::forward_list<size_t> flis1(vecptr.begin(), vecptr.end()),flis1_2(vecptr.begin(), vecptr.end()), flis2(vecptr.begin(), vecptr.end());
	// std::copy(vecptr.begin(), vecptr.end(), flis1.begin());
	// std::copy(vecptr.begin(), vecptr.end(), flis2.begin());
    std::cout << "Copy  time   = " << MySorts::Duration::end() << std::endl;


	std::cout << "Sort Heap Vector\n";
    MySorts::Duration::start();
    MySorts::heap<size_t>(vecptr.begin(), vecptr.end());
    std::cout << " My sort time = " << MySorts::Duration::end() << std::endl;

    MySorts::Duration::start();
    MySorts::sort<size_t>(vecptr1.begin(), vecptr1.end());
    std::cout << " My MY   time = " << MySorts::Duration::end() << std::endl;

    MySorts::Duration::start();
    std::sort(vecptr2.begin(), vecptr2.end());
    std::cout << " Sort time    = " << MySorts::Duration::end() << std::endl;

	std::cout << "Sort Heap forvard_list\n";
    MySorts::Duration::start();
    MySorts::heap<size_t>(flis1.begin(),flis1.end());
    std::cout << " My sort time = " << MySorts::Duration::end() << std::endl;

    MySorts::Duration::start();
    MySorts::sort<size_t>(flis1_2.begin(),flis1_2.end());
    std::cout << " My My  time  = " << MySorts::Duration::end() << std::endl;

    MySorts::Duration::start();
    flis2.sort();
    std::cout << " Sort time    = " << MySorts::Duration::end() << std::endl;

	std::cout << MySorts::check(vecptr) << " "\
	<< MySorts::check(vecptr1) << " "\
	<< MySorts::check(vecptr2) << " "\
	<< MySorts::check(flis1) << " "\
	<< MySorts::check(flis1_2) << " "\
	<< MySorts::check(flis2) << " "\
	<< std::endl;

    // for (auto &v: vecptr)
    // {
    //     std::cout << v << std::endl;
    // }

}

    return 0;
}