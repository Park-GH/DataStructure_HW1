//2016706018 박건희
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

	//생성자 및 소멸자
	MyIntVector();	//default 생성자
	MyIntVector(const MyIntVector& source);	//for deep copy
	~MyIntVector();	//소멸자

	////////////push & pop////////////
	
	void push_back(int x);	
	//precondition: 정수 x입력
	//postcondtion: x를 data에 push하고 size를 한칸 늘리고 capacity가 모자란 경우 한칸 늘린다.
	
	void pop_back();		
	//precondition: push되있는, 즉 size가 0보다 큰 객체에서 실행
	//postcondtion: 데이터를 빼내어 size를 한 칸 줄인다. capacity는 유지된다.

	//////////////////////////////////
	size_t capacity() const;
	//precondition: 
	//postcondtion: capacity 리턴

	size_t size() const;		
	//precondition:
	//postcondtion: size 리턴

	//////////////////////////////////
	void reserve(size_t n);
	//precondition: 0이상의 정수 n 입력
	//postcondtion: capacity 조절

	bool is_empty() const;	
	//precondition: 
	//postcondtion: used가 0인 경우 true, 아닌 경우 false 리턴

	void clear();			
	//precondition:
	//postcondtion: data 반환 및 size, capacity 0으로 초기화
	

	////////////////////////연산자//////////////////////

	int& operator [](int x);		
	//precondition: 객체 index 범위만큼의 정수 x (0<=x<used)
	//postcondtion: x의 데이터 리턴
	
	void operator ()(int x);	
	//precondition: 정수 x
	//postcondtion:	정수 x로 객체의 모든 데이터로 변환

	MyIntVector operator -();		
	//precondition: 
	//postcondtion: 데이터의 부호가 반대로 된 MyIntVector 객체 반환


	MyIntVector& operator =(const MyIntVector& append);	
	//precondition: MyIntVector 객체
	//postcondtion: 입력받은 객체를 deepcopy 후 레퍼런스 return

	void operator +=(const MyIntVector& append);		
	//precondition: MyIntVector 객체
	//postcondtion: append의 data만큼을 기존 데이터에 붙여주고 사이즈를 그 만큼 늘려줌, capacity는 모자란 경우 할당

	bool operator ==(const MyIntVector& append);		
	//precondition: MyIntVector 객체
	//postcondtion: 동일한 데이터가 들어있으면 True 아니면 false 반환, 이 때 capacity는 고려하지 않는다.
	
	
	////////////////vector 연산///////////////////////
	
		
	MyIntVector operator +(const MyIntVector& append);	
	//precondition: size가 동일한 MyIntVector 객체
	//postcondtion:	두 operand 데이터간 벡터 +연산 된 MyIntVector 객체 반환

	MyIntVector operator -(const MyIntVector& append);	
	//precondition: size가 동일한 MyIntVector 객체
	//postcondtion:	두 operand 데이터간 벡터 -연산 된 MyIntVector 객체 반환
	
	int operator *(const MyIntVector& append);			
	//precondition: size가 동일한 MyIntVector 객체
	//postcondtion:	두 operand간 data의 벡터 내적 후 결과 값 반환
};


