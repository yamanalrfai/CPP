#pragma once
#include<algorithm>
#include <iterator>

template<class T>
typename T::iterator easyfind(T& bag, int need)
{
    return (std::find(bag.begin(), bag.end(), need));
}
