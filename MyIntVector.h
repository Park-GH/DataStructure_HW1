//2016706018 �ڰ���
#include <cstdlib>
#include <algorithm>
#include <cassert>


using namespace std;
class MyIntVector {
private:
	int* data;
	size_t CAPACITY;
	size_t used;
public:

	//������ �� �Ҹ���
	MyIntVector();	//default ������
	MyIntVector(const MyIntVector& source);	//for deep copy
	~MyIntVector();	//�Ҹ���

	////////////push & pop////////////
	
	void push_back(int x);	
	//precondition: ���� x�Է�
	//postcondtion: x�� data�� push�ϰ� size�� ��ĭ �ø��� capacity�� ���ڶ� ��� ��ĭ �ø���.
	
	void pop_back();		
	//precondition: push���ִ�, �� size�� 0���� ū ��ü���� ����
	//postcondtion: �����͸� ������ size�� �� ĭ ���δ�. capacity�� �����ȴ�.

	//////////////////////////////////
	size_t capacity() const;
	//precondition: 
	//postcondtion: capacity ����

	size_t size() const;		
	//precondition:
	//postcondtion: size ����

	//////////////////////////////////
	void reserve(size_t n);
	//precondition: 0�̻��� ���� n �Է�
	//postcondtion: capacity ����

	bool is_empty() const;	
	//precondition: 
	//postcondtion: used�� 0�� ��� true, �ƴ� ��� false ����

	void clear();			
	//precondition:
	//postcondtion: data ��ȯ �� size, capacity 0���� �ʱ�ȭ
	

	////////////////////////������//////////////////////

	int& operator [](int x);		
	//precondition: ��ü index ������ŭ�� ���� x (0<=x<used)
	//postcondtion: x�� ������ ����
	
	void operator ()(int x);	
	//precondition: ���� x
	//postcondtion:	���� x�� ��ü�� ��� �����ͷ� ��ȯ

	MyIntVector operator -();		
	//precondition: 
	//postcondtion: �������� ��ȣ�� �ݴ�� �� MyIntVector ��ü ��ȯ


	MyIntVector& operator =(const MyIntVector& append);	
	//precondition: MyIntVector ��ü
	//postcondtion: �Է¹��� ��ü�� deepcopy �� ���۷��� return

	void operator +=(const MyIntVector& append);		
	//precondition: MyIntVector ��ü
	//postcondtion: append�� data��ŭ�� ���� �����Ϳ� �ٿ��ְ� ����� �� ��ŭ �÷���, capacity�� ���ڶ� ��� �Ҵ�

	bool operator ==(const MyIntVector& append);		
	//precondition: MyIntVector ��ü
	//postcondtion: ������ �����Ͱ� ��������� True �ƴϸ� false ��ȯ, �� �� capacity�� ������� �ʴ´�.
	
	
	////////////////vector ����///////////////////////
	
		
	MyIntVector operator +(const MyIntVector& append);	
	//precondition: size�� ������ MyIntVector ��ü
	//postcondtion:	�� operand �����Ͱ� ���� +���� �� MyIntVector ��ü ��ȯ

	MyIntVector operator -(const MyIntVector& append);	
	//precondition: size�� ������ MyIntVector ��ü
	//postcondtion:	�� operand �����Ͱ� ���� -���� �� MyIntVector ��ü ��ȯ
	
	int operator *(const MyIntVector& append);			
	//precondition: size�� ������ MyIntVector ��ü
	//postcondtion:	�� operand�� data�� ���� ���� �� ��� �� ��ȯ
};


