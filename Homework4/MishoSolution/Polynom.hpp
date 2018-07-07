#ifndef __POLYNOM__HEADER__INCLUDED
#define __POLYNOM__HEADER__INCLUDED
#include <iostream>

template <typename T>
class Polynom
{
public:
	Polynom(unsigned int pow, T * coefficients); //the user will be entering the power of the polynom
	Polynom(const Polynom &);
	Polynom & operator=(const Polynom &);
	~Polynom();

	//operators

	Polynom & operator+=(const Polynom &);
	Polynom & operator-=(const Polynom &);
	Polynom & operator*=(const Polynom &);
	Polynom & operator*=(int n); //for the coefficients
	Polynom & operator/=(const Polynom &);
	Polynom & operator/=(int n); //for the coefficients
	Polynom & operator%=(const Polynom &);
	T operator[](unsigned int x); //return the coefficient in front of the asked power
	T operator()(int x); //solves the polynom for the given x
	T operator()(int a, int b); //solves an integral from a to b
	unsigned int operator()(double); //returns the power of the polynom

	//binary operators
	friend bool operator==(const Polynom & first, const Polynom & second);
	friend bool operator!=(const Polynom & first, const Polynom & second);
	friend bool operator<(const Polynom & first, const Polynom & second);
	friend bool operator>(const Polynom & first, const Polynom & second);

	Polynom & operator++(); //integral
	Polynom operator++(int);

	Polynom & operator--(); //derivative
	Polynom operator--(int);

	operator bool() const;
	bool operator!() const;

	//streams
	
	template <typename T>
	friend std::ostream& operator<<(std::ostream &, const Polynom<T> &);
	
	template <typename T>
	friend std::istream& operator>>(std::istream &, Polynom<T> &);

	//Iterator

	class Iterator
	{
		friend class Polynom;
	public:
		bool operator==(const Iterator & i) const
		{
			return data == i.data;
		}
		bool operator!=(const Iterator & i) const
		{
			return !(*this == i);
		}
		int & operator*()
		{
			return *data;
		}
		Iterator & operator++()
		{
			++data;
			return *this;
		}
		Iterator operator++(int) = delete; 
		Iterator & operator--()
		{
			--data;
			return *this;
		}
		Iterator operator--(int) = delete;

		//bool operator>(const Iterator & i)
	private:
		int * data;
		Iterator(int * data)
			:data(data)
		{}
	};
public:
	Iterator begin()
	{
		return Iterator(coefficients);
	}
	Iterator end()
	{
		return Iterator(coefficients + size);
	}

private:
	void copyFrom(const Polynom & other);
	void freeData();

private:
	T * coefficients;
	unsigned int size;
};

template <typename T>
inline bool operator==(const Polynom<T> & lhs, const Polynom<T> & rhs)
{
	if (lhs.size != rhs.size)
		return false;
	else
	{
		for (int i = 0; i < lhs.size; i++)
			if (lhs.coefficients[i] != rhs.coefficients[i])
				return false;
		return true;
	}
}

template <typename T>
inline bool operator!=(const Polynom<T> & lhs, const Polynom<T> & rhs)
{
	return !(lhs == rhs);
}

template <typename T>
inline bool operator>(const Polynom<T> & lhs, const Polynom<T> & rhs)
{
	return (lhs.size > rhs.size);
}

template <typename T>
inline std::ostream & operator<<(std::ostream & out, const Polynom<T> & output)
{
	//out << output.size << std::endl;
	for (int i = 0; i < output.size; i++)
	{
		out << output.coefficients[i] << " ";
	}
	out << '\n';
	return out;
}

template <typename T>
inline std::istream & operator>>(std::istream & in, Polynom<T> & input)
{
	in >> input.size;
	delete[] input.coefficients;
	try
	{
		input.coefficients = new T[input.size];
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	for (int i = 0; i < input.size; i++)
		in >> input.coefficients[i];
	return in;
}

template <typename T>
inline bool operator<(const Polynom<T> & lhs, const Polynom<T> & rhs)
{
	return (lhs.size < rhs.size);
}

template <typename T>
Polynom<T>::Polynom(unsigned int pow, T * coefficients)
	:size(pow + 1)
{
	try
	{
		this->coefficients = new T[size];
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	
	for (int i = 0; i < size; i++)
		this->coefficients[i] = coefficients[i];
}

template <typename T>
Polynom<T>::Polynom(const Polynom & other)
{
	copyFrom(other);
}

template <typename T>
Polynom<T> & Polynom<T>::operator=(const Polynom<T> & other)
{
	if (this != &other)
	{
		freeData();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Polynom<T>::~Polynom()
{
	freeData();
}

template <typename T>
void Polynom<T>::freeData()
{
	delete[] coefficients;
}

template <typename T>
void Polynom<T>::copyFrom(const Polynom<T> & other)
{
	size = other.size;
	try
	{
		coefficients = new T[size];
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	for (int i = 0; i < size; i++)
		coefficients[i] = other.coefficients[i];
}
\
template <typename T>
Polynom<T> & Polynom<T>::operator+=(const Polynom<T> & other)
{
	if (other.size > size)
	{
		T * temp = coefficients;
		coefficients = nullptr;

		try
		{
			coefficients = new T[other.size];
		}
		catch (std::bad_alloc & e)
		{
			std::cerr << "Error when allocating memory.\n";
			throw;
		}
		int i = 0;
		for (int j = 0; i < other.size; i++)
		{
			if (other.size - i > size)
				coefficients[i] = other.coefficients[i];
			else
				coefficients[i] = other.coefficients[i] + temp[j++];
		}
		size = other.size;
		delete[] temp;
	}
	else
	{
		for (int i = size - other.size, j = 0; j < other.size; i++, j++)
			coefficients[i] += other.coefficients[j];
	}
	return *this;
}

template <typename T>
Polynom<T> & Polynom<T>::operator-=(const Polynom<T> & other)
{
	if (other.size > size)
	{
		T * temp = coefficients;
		coefficients = nullptr;

		try
		{
			coefficients = new T[other.size];
		}
		catch (std::bad_alloc & e)
		{
			std::cerr << "Error when allocating memory.\n";
			throw;
		}
		int i = 0;
		for (int j = 0; i < other.size; i++)
		{
			if (other.size - i > size)
				coefficients[i] = -other.coefficients[i];
			else
				coefficients[i] = -other.coefficients[i] + temp[j++];
		}
		size = other.size;
		delete[] temp;
	}
	else
	{
		for (int i = size - other.size, j = 0; j < other.size; i++, j++)
			coefficients[i] -= other.coefficients[j];
	}

	return *this;
}

template <typename T>
Polynom<T> & Polynom<T>::operator*=(const Polynom<T> & other)
{
	T * temp = coefficients;
	coefficients = nullptr;

	unsigned int newSize = size + other.size - 1;
	try
	{
		coefficients = new T[newSize];
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (i == 0 || j == other.size - 1)
			{
				coefficients[i + j] = temp[i] * other.coefficients[j];
			}
			else
				coefficients[i + j] += temp[i] * other.coefficients[j];
		}
	}

	size = newSize;
	delete[] temp;
	return *this;
}

template <typename T>
inline Polynom<T> & Polynom<T>::operator*=(int n)
{
	for (int i = 0; i < size; i++)
		coefficients[i] *= n;
	return *this;
}

template <typename T>
inline Polynom<T> & Polynom<T>::operator/=(const Polynom<T> & other)
{
	T * temp = coefficients;
	coefficients = nullptr;

	size -= other.size;
	size++;
	try
	{
		coefficients = new T[size]; 
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	for (int i = 0; i < size; i++)
	{
		coefficients[i] = temp[i] / other.coefficients[0];
		for (int j = i; j < size; j++)
			temp[j] -= coefficients[i] * other.coefficients[j];
	}
	
	delete[] temp;

	return *this;
}
template <typename T>
inline Polynom<T> & Polynom<T>::operator%=(const Polynom<T> & other)
{
	T * temp = coefficients;
	coefficients = nullptr;

	size -= other.size;
	try
	{
		coefficients = new T[size]; 
	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	
	for (int i = 0; i < size; i++)
	{
		coefficients[i] = temp[i] / other.coefficients[0];
		for (int j = i; j < size; j++)
			temp[j] -= coefficients[i] * other.coefficients[j];
	}

	for (int i = 0, j = 0; i < size; i++)
	{
		if (temp[i] != 0)
			coefficients[j++] = temp[i];
	}
	
	delete[] temp;
	return *this;
}

template <typename T>
inline T Polynom<T>::operator[](unsigned int x)
{
	return coefficients[size - x - 1];
}

template <typename T>
inline T Polynom<T>::operator()(int x)
{
	T sum = 0;
	for (int i = 0; i < size - 1; i++)
	{
		sum += (pow(coefficients[i], size - i - 1)) * x;
	}
	sum += coefficients[size - 1];
	return sum;
}

template <typename T>
inline Polynom<T> & Polynom<T>::operator/=(int n)
{
	if (n == 0)
	{
		throw std::invalid_argument("Can't divide anything to zero!\n");
	}

	for (int i = 0; i < size; i++)
		coefficients[i] /= n;
	return *this;
}

template <typename T>
const Polynom<T> operator+(const Polynom<T> & first, const Polynom<T> & second)
{
	Polynom<T> temp(first);
	temp += second;
	return temp;
}

template <typename T>
const Polynom<T> operator-(const Polynom<T> & first, const Polynom<T> & second)
{
	Polynom<T> temp(first);
	temp -= second;
	return temp;
}

template <typename T>
const Polynom<T> operator*(const Polynom<T> & first, const Polynom<T> & second)
{
	Polynom<T> temp(first);
	temp *= second;
	return temp;
}

template <typename T>
inline const Polynom<T> operator*(const Polynom<T> & polynom, int n)
{
	Polynom<T> temp(polynom);
	temp *= n;
	return temp;
}

template <typename T>
inline const Polynom<T> operator/(const Polynom<T> & first, const Polynom<T> & second)
{
	Polynom<T> temp(first);
	temp /= second;
	return temp;
}

template <typename T>
inline const Polynom<T> operator%(const Polynom<T> & first, const Polynom<T> & second)
{
	Polynom<T> temp(first);
	temp %= second;
	return temp;
}

template <typename T>
inline const Polynom<T> operator/(const Polynom<T> & polynom, int n)
{
	Polynom<T> temp(polynom);
	temp /= n;
	return temp;
}

template <typename T>
inline T Polynom<T>::operator()(int a, int b)
{
	T sumB = 0;
	T sumA = 0;

	for (int i = 0; i < size; i++)
	{
		sumB += coefficients[i] * pow(b, size - i) / (size - i);
		sumA += coefficients[i] * pow(a, size - i) / (size - i);
	}
	return sumB - sumA;
}

template <typename T>
inline unsigned int Polynom<T>::operator()(double)
{
	return size - 1;
}

template <typename T>
inline Polynom<T> & Polynom<T>::operator++()
{
	for (int i = 0; i < size; i++)
		coefficients[i] /= (size - i);
	return *this;
}

template <typename T>
inline Polynom<T> Polynom<T>::operator++(int)
{
	Polynom temp(*this);
	++(*this);
	return temp;
}

template <typename T>
inline Polynom<T> & Polynom<T>::operator--()
{
	T * temp = coefficients;
	coefficients = nullptr;

	try
	{
		coefficients = new T[--size]; //the last coefficient will turn into 0, so we can skip it

	}
	catch (std::bad_alloc & e)
	{
		std::cerr << "Error when allocating memory.\n";
		throw;
	}
	for (int i = 0; i < size; i++)
		coefficients[i] = temp[i] * (size - i);
	delete[] temp;
	return *this;
}

template <typename T>
Polynom<T> Polynom<T>::operator--(int)
{
	Polynom temp(*this);
	--(*this);
	return temp;
}

template<typename T>
inline Polynom<T>::operator bool() const
{
	return !(*this);
}

template<typename T>
inline bool Polynom<T>::operator!() const
{
	return (coefficients[size - 1] == 0? true : false);
}

#endif // !__POLYNOM__HEADER__INCLUDED
