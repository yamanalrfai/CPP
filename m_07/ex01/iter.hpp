#pragma once

template <typename T>
void iter(T *arr, const int size, void(*f)(T &)){
    for (int i = 0; i < size; i++)
    {
        f(arr[i]);
    }
}

template <typename T>
void iter(const T *arr, const int size, void (*f)(const T &))
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void print(const T &num) {
    std::cout << num << std::endl;
}

template <typename T>
void add_one(T &num){
    num = num + 1;
}
