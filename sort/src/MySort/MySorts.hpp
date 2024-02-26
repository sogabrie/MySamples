#pragma once

#include <algorithm>
#include <iostream>

namespace MySorts{

template <typename IT>
void heap(IT first, IT last)
{
    std::sort(first, last);
}

}