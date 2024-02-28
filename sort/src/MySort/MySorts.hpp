#pragma once

#include <algorithm>
#include <iostream>
#include <functional>
#include "Utils.hpp"

namespace MySorts{

template <class T, typename C = std::less<> >
void	life_up(std::vector<T> &cp, size_t i, C cmp = C{}) noexcept
{
	long long j = static_cast<long long>(i);
	for (; ((j + 1) / 2 - 1) >= 0 ; )
	{
		if (cmp(cp[j],cp[(j + 1) / 2 - 1]))
		{
			std::swap(cp[(j + 1) / 2 - 1], cp[j]);
			j = (j + 1) / 2 - 1;
		}
		else
			break;
	}
}

template <class T, typename IT, typename C = std::less<>>
std::vector<T>	make_heap(IT first, IT last, C cmp = C{}) noexcept
{
	MySorts::Duration::start();
	auto it = first;
	size_t i = 0;
	for (; it !=  last; ++i, ++it);
	std::vector<T> cp;
	cp.reserve(i);
	for (i = 0, it = first; it != last; ++i, ++it)
	{
		cp.push_back(std::move((*it)));
		life_up<T>(cp,i,cmp);
	}
    std::cout << "	macke heap = " << MySorts::Duration::end() << std::endl;
    // for (auto &v: cp)
    // {
    //     std::cout << v << std::endl;
    // }
	return cp;
}

template <class T>
void	myswap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <class T, typename C = std::less<>>
void	_find(std::vector<T> &cp, size_t i, C cmp = C{}) noexcept
{
	if (i > 0)
	{
		// std::swap(cp[0], cp[i]);
		// for (size_t j = 0; j < i;)
		// {
		// 	if ((j + 1) * 2 - 1 < i && (j + 1) * 2 < i && \
		// 	cmp(cp[(j + 1) * 2], cp[(j + 1) * 2 - 1]) && cmp(cp[(j + 1) * 2], cp[j]))
		// 	{
		// 		std::swap(cp[(j + 1) * 2], cp[j]);
		// 		j = (j + 1) * 2;
		// 	}
		// 	else if((j + 1) * 2 - 1 < i && cmp(cp[(j + 1) * 2 -1 ], cp[j]))
		// 	{
		// 		std::swap(cp[(j + 1) * 2 - 1], cp[j]);
		// 		j = (j + 1) * 2 - 1;
		// 	}
		// 	else
		// 		break;
		// }

		(void)cmp;
		myswap(cp[0], cp[i]);
		for (size_t j = 0; j < i;)
		{
			if ((j + 1) * 2 - 1 < i && (j + 1) * 2 < i && \
			(cp[(j + 1) * 2] < cp[(j + 1) * 2 - 1]) && (cp[(j + 1) * 2] < cp[j]))
			{
				myswap(cp[(j + 1) * 2], cp[j]);
				j = (j + 1) * 2;
			}
			else if((j + 1) * 2 - 1 < i && (cp[(j + 1) * 2 -1 ] < cp[j]))
			{
				myswap(cp[(j + 1) * 2 - 1], cp[j]);
				j = (j + 1) * 2 - 1;
			}
			else
				break;
		}
		
	}
}

template <class T, typename IT, typename C = std::less<>>
void	pop_heap(IT first, std::vector<T> &&cp, C cmp = C{}) noexcept
{
	MySorts::Duration::start();
	for (long long i = cp.size() - 1; i >= 0; --i, ++first)
	{
		_find(cp, i,cmp);
		// *first = std::move(cp[i]);
		// std::swap( *first, cp[i]);
		myswap( *first, cp[i]);
	}
	std::cout << "	Pop   heap = " << MySorts::Duration::end() << std::endl;
}

// example 1  START   (SFINEA)

template	<typename IT>
using	ItTag = typename std::iterator_traits<IT>::iterator_category;

template <class T, typename IT, typename C = std::less<>,\
				std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag, ItTag<IT>>, \
				int> = 0 >
void	heap(IT first, IT last, C cmp = C{}) noexcept
{
	// MySorts::Duration::start();
	// auto it = first;
	// size_t i = 0;
	// for (; it !=  last; ++i, ++it);
	// std::vector<T> cp;
	// cp.reserve(i);
	// for (i = 0, it = first; it != last; ++i, ++it)
	// {
	// 	cp.push_back(std::move((*it)));
	// 	life_up<T>(cp,i,cmp);
	// }
    // std::cout << "	macke heap = " << MySorts::Duration::end() << std::endl;
	// pop_heap(first, std::move(cp), cmp);
	pop_heap(first, std::move(make_heap<T>(first,last, cmp)), cmp);
}

//	END
//---------------------------------------------------------------------------------------------------------
//  example 2 START   (SFINEA)

template <class T, typename IT, typename C = std::less<>>
void	my_sort(IT first, IT last, std::forward_iterator_tag, C cmp = C{}) noexcept
{
	pop_heap(first, std::move(make_heap<T>(first,last, cmp)), cmp);
}

//	END
//---------------------------------------------------------------------------------------------------------
//  example 3 START   (SFINEA)

template <class T, typename IT, typename C = std::less<>>
void	my_sort_heap(IT first, IT last, C cmp = C{}) noexcept
{
	pop_heap(first, std::move(make_heap<T>(first,last, cmp)), cmp);
	// pop_heap(first, make_heap<T>(first,last, cmp), cmp);
}

template <class T, typename IT, typename C = std::less<>>
void	sort(IT first, IT last, C cmp = C{}) noexcept
{
	if constexpr (std::is_base_of_v<std::input_iterator_tag, ItTag<IT>> || \
	std::is_base_of_v<std::forward_iterator_tag, ItTag<IT>>)
	{
		my_sort_heap<T>(first, last, cmp);
	}
}

//	END

}