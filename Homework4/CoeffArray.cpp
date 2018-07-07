#include "CoeffArray.h"

using std::endl;
using std::cerr;

CoeffArray::CoeffArray()
	:arr(nullptr)
	,cap(2)
	,size(0){
	this->arr = new int[cap];
	for (int i = 0; i < cap; i++) {
		arr[i] = 0;
	}
}

CoeffArray::CoeffArray(const CoeffArray& rhs) {
	copy(rhs);
}

CoeffArray& CoeffArray::operator=(const CoeffArray& rhs) {
	if (this != &rhs) {
		free();
		copy(rhs);
	}
	return *this;
}

CoeffArray::~CoeffArray() {
	free();
}

void CoeffArray::free() {
	delete arr;
	arr = nullptr;
	size = 0;
	cap = 0;
}

void CoeffArray::copy(const CoeffArray& rhs) {
	this->cap = rhs.cap;
	this->size = rhs.size;
	this->arr = new int[this->cap];
	for (int i = 0; i < cap; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		this->arr[i] = rhs.arr[i];
	}
}

void CoeffArray::resize() {
	cap *= 2;
	int* temp = new int[cap];
	for (int i = 0; i < cap; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	temp = nullptr;
	cap *= 2;
}

void CoeffArray::addCoeff(const int coeff) {
	if (size == cap) {
		resize();
	}
	arr[size] = coeff;
	size++;
}

void CoeffArray::removeCoeff(const int index) {
	if (index < 0) {
		cerr << "Invalid index " << index 
			<< " to be removed from the polinom!" 
			<< endl;
	}
	else {
		arr[index] = 0;
	}
}