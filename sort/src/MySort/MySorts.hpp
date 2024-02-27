#pragma once

#include <algorithm>
#include <iostream>
#include <functional>

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
	return cp;
}

template <class T, typename C = std::less<>>
void	_find(std::vector<T> &cp, size_t i, C cmp = C{}) noexcept
{
	if (i > 0)
	{
		std::swap(cp[0], cp[i]);
		for (size_t j = 0; j < i;)
		{
			if ((j + 1) * 2 - 1 < i && (j + 1) * 2 < i && \
			cmp(cp[(j + 1) * 2], cp[(j + 1) * 2 - 1]))
			{
				std::swap(cp[(j + 1) * 2], cp[j]);
				j = (j + 1) * 2;
			}
			else if((j + 1) * 2 - 1 < i)
			{
				std::swap(cp[(j + 1) * 2 - 1], cp[j]);
				j = (j + 1) * 2 - 1;
			}
			else
				break;
		}
		
	}
}

template <class T, typename IT, typename C = std::less<>>
void	pop_heap(IT first, std::vector<T> cp, C cmp = C{}) noexcept
{
	for (long long i = cp.size() - 1; i >= 0; --i, ++first)
	{	
		_find(cp, i,cmp);
		*first = std::move(cp[i]);
	}
}

template <class T, typename IT, typename C = std::less<>>
void	heap(IT first, IT last, C cmp = C{}) noexcept
{
	pop_heap(first, std::move(make_heap<T>(first,last, cmp)), cmp);
}

}