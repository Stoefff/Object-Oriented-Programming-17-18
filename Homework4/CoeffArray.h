#ifndef __COEFF__ARRAY__HEADER__
#define __COEFF__ARRAY__HEADER__

#include <iostream>

class CoeffArray {
public:
	CoeffArray();
	CoeffArray(const CoeffArray& rhs);
	CoeffArray& operator=(const CoeffArray& rhs);
	~CoeffArray();

	void addCoeff(const int coeff);
	void removeCoeff(const int index);
//	void removeCoeff(const int coeff);

private:
	void free();
	void copy(const CoeffArray& rhs);
	void resize();

private:
	int* arr;
	size_t cap;
	size_t size;
};

#endif
