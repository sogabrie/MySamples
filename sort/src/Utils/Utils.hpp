#pragma once

#include <random>
#include <functional>
// #include <cuchar>
#include <chrono>

namespace MySorts{

template <typename Conteyner, size_t count = 1000>
struct Generator
{
    static void run(Conteyner &str)
    {
        std::mt19937_64 engine { std::random_device{}()};
        std::uniform_int_distribution<size_t> distr {0, 2'000'0000'000};

        for (size_t i = 0; i < count; i++)
        {
            str.push_back(distr(engine));
        }
    }
};

template <typename Counteyner, typename C = std::less<>,
			class IT = typename Counteyner::const_iterator>
std::string	check(Counteyner &str, C cmp = C{})
{
	if (std::is_sorted(std::begin(str), std::end(str), cmp))
		return (std::string("OK"));
	return (std::string("ERROR"));
}


class Duration
{
private:
    static std::chrono::steady_clock::time_point   _start;
public:
    Duration();

    static  void start();
    static  size_t end();
    ~Duration();
};



}
