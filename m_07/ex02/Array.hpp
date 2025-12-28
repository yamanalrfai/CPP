#pragma once
#include <stdexcept>

template<typename T> class Array
{
	private:
		T*				arr;
		unsigned int	siz;
	public:
		Array()
		{
			arr = new T[0]();
			siz = 0;
		}
		Array(unsigned int n)
		{
			arr = new T[n]();
			siz = n;
		}
		Array(const Array& other)
		{
			siz = other.siz;
			arr = new T[siz];
			for(unsigned int i = 0; i < siz; i++)
				arr[i] = other[i];
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete [] arr;
				siz = other.siz;
				arr = new T[siz];
				for(unsigned int i = 0; i < siz; i++)
					arr[i] = other[i];
			}
			return (*this);
		}

		~Array()
		{
			delete [] arr;
		}

		unsigned int size() const
		{
			return (this.siz);
		}

		T& operator[](unsigned int index)
		{
			if (index >= siz)
				throw std::out_of_range("index out of range");
			return (arr[index]);
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= siz)
				throw std::out_of_range("index out of range");
			return (arr[index]);
		}
};
