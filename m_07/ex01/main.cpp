#include <iostream>
#include "iter.hpp"



int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    double arrr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(arr, 5, print);
    iter(arrr, 5, print);
    iter(arr, 5, add_one);
    iter(arr, 5, print);
}
