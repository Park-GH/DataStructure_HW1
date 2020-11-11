//2016706018 박건희
#include "MyIntVector.h"

//생성자
MyIntVector::MyIntVector() {
	data = NULL;
	CAPACITY = 0;
	used = 0;
}


//복사
MyIntVector::MyIntVector(const MyIntVector& source) {
	CAPACITY = source.CAPACITY;
	used = source.used;
	data = new int[CAPACITY];
	copy(source.data, source.data + used, data);
}

//소멸자
MyIntVector::~MyIntVector() {
	delete[] data;
}

//push

void MyIntVector::push_back(int x) {
	assert(!(used > CAPACITY));
	if (used == CAPACITY) {
		reserve(used + 1);
	}
	data[used++] = x;
}

//pop

void MyIntVector::pop_back() {
	assert(used > 0);
	used--;
}


size_t MyIntVector::capacity() const { return CAPACITY; }

size_t MyIntVector::size() const { return used; }



void MyIntVector::reserve(size_t n) {
	assert(!(n<0));
	int* larger_array;
	if (n == CAPACITY)
		return;
	if (n < used)
		n = used;
	larger_array = new int[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	CAPACITY = n;
}


bool MyIntVector::is_empty() const {
	if (used == 0)
		return true;
	return false;
}


void MyIntVector::clear() {
	int* void_array = NULL;
	used = 0;
	CAPACITY = 0;
	delete[] data;
	data = void_array;
}

//연산자


MyIntVector& MyIntVector::operator =(const MyIntVector& append) {
	CAPACITY = append.CAPACITY;
	used = append.used;
	data = new int[CAPACITY];
	copy(append.data, append.data + used, data);
	return *this;
}


void MyIntVector::operator +=(const MyIntVector& append) {
	if (used + append.used > CAPACITY)
		reserve(used + append.used);
	copy(append.data, append.data + append.used, data + used);
	used += append.used;
}


int& MyIntVector::operator [](int x) {
	assert(x >= 0 && x < used);
	int& val = data[x];
	return val;
}


MyIntVector MyIntVector::operator +(const MyIntVector& append) {
	MyIntVector v_temp;
	assert(used == append.used);
	v_temp.reserve(used);
	for (int i = 0; i < (int)used; i++)
	{
		v_temp.data[i] = data[i] + append.data[i];
		v_temp.used++;
	}
	return v_temp;
}


MyIntVector MyIntVector::operator -(const MyIntVector& append) {
	MyIntVector v_temp;
	assert(used == append.used);
	v_temp.reserve(used);
	for (int i = 0; i < (int)used; i++)
	{
		v_temp.data[i] = data[i] - append.data[i];
		v_temp.used++;
	}
	return v_temp;
}

int MyIntVector::operator *(const MyIntVector& append) {
	int temp = 0;
	assert(used == append.used);
	for (int i = 0; i < (int)used; i++)
	{
		temp += data[i] * append.data[i];
	}
	return temp;
}


MyIntVector MyIntVector::operator -() {
	MyIntVector v_temp(*this);

	for (int i = 0; i < (int)used; i++)
	{
		v_temp.data[i] = v_temp.data[i] * -1;
	}
	return v_temp;
}


bool MyIntVector::operator ==(const MyIntVector& append) {
	if (used != append.used)
		return false;
	for (int i = 0; i < (int)used; i++) {
		if (data[i] != append.data[i])
			return false;
	}
	return true;
}


void MyIntVector::operator ()(int x) {
	for (int i = 0; i < (int)used; i++)
		data[i] = x;

}
