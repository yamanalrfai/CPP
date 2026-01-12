#include "easyfind.hpp"
#include <iostream>
#include <vector>
int main(){
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    std::vector<int>::iterator it1 = easyfind(arr, 4);
    std::vector<int>::iterator it2 = easyfind(arr, 3);
    if (it1 != arr.end())
    {
        std::cout << "found : "<< *it1 << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
    if (it2 != arr.end())
    {
        std::cout << "found : "<< *it2 << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
}