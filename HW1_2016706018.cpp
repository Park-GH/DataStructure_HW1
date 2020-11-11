//2016706018 박건희
#include "MyIntVector.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int main() {

	int object = 0;	//객체 갯수
	int n = -1;		//객체 번호
	int num1 = 0, num2 = 0;	//연산 대상 및 for문에 사용할 변수들
	int select = 0; //테스트 번호 선택
	cout << "생성할 객체 갯수 입력 : ";
	cin >> object;
	assert(object>0);

	MyIntVector * v = new MyIntVector[object]; //defult

	if(object==1)
		cout << "v[0] 객체 생성 완료 " << endl;
	else
	cout << "v[0]~v["<<object-1<<"] 객체 생성 완료 " << endl;
	while (1) {
		cout << endl;
		cout << "연산할 객체 번호 입력: ";
		cin >> n;
		//입력받은 n이 범위 밖인 경우 다시 입력
		while (!(n>=0 && n<object)) {
			cout << "객체 범위 밖, 재입력: ";
			cin >> n;
		}
		system("cls");	//화면 지우기

		cout << "테스트할 번호를 입력하세요" << endl;
		cout << "** 9번은 Uanry operator 13번은 binary opeator **" << endl;
		cout << "1: push, 2: pop, 3: capacity, 4: size, 5: reserve, 6: is_empty, 7:clear" << endl;
		cout << "8: [], 9: -, 10: ()" << endl;
		cout << "11: +=, 12: +, 13: -, 14: *, 15: ==" << endl;
		cout << "16: 객체 재 선택, 17: 데이터 나열, 18: 종료  19: =" << endl << endl;
		cout << "v[" << n << "]으로 할 동작은?" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout<<"push할 갯수 입력:"<<endl;
			cin >> num2;
			cout << "data 입력" << endl;
			for (int i = 0; i < num2; i++) {
				cin >> num1;
				v[n].push_back(num1);
			}
			cout << "push 결과" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			cout <<"v["<<n<<"]의 size는 "<< v[n].size()<< ", CAPACITY는 " << v[n].capacity() << endl;
			break;
		case 2:
			cout << "pop 횟수 입력: " << endl;
			cin >> num2;
			cout << "pop 결과" << endl;
			for (int i = 0; i < num2; i++) {
				cout << v[n][(int)v[n].size()-1] << " ";
				v[n].pop_back();
			}
			cout << endl;
			cout << "v[" << n << "]의 size는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
		case 3:
			cout << "capacity 확인" << endl;
			cout << v[n].capacity() << endl;
			break;
		case 4:
			cout << "size 확인" << endl;
			cout << v[n].size() << endl;
			break;
		case 5:
			cout << "reserve할 값은?" << endl;
			cin >> num1;
			v[n].reserve(num1);
			cout << "v[" << n << "]의 size는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
		case 6:
			cout << "is_empty 실행" << endl;
			cout << v[n].is_empty() << endl;
			cout << "v[" << n << "]의 size는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
		case 7:
			cout << "clear 실행" << endl;
			v[n].clear();
			cout << "v[" << n << "]의 size는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
	
		case 8:
			cout << "operator []" << endl;
			cout << "데이터의 인덱스 입력:";
			cin >> num1;
			cout << v[n][num1] << endl;
			break;
		case 9:
			cout << "operator -" << endl;
			cout << "연산대상 객체 번호 입력" << endl;
			cin >> num1;
			v[num1]=-v[n];
			cout << "연산 결과 v["<<num1<<"] 데이터 출력:"<<endl;
			for (int i = 0; i < (int)v[num1].size(); i++)
				cout << v[num1][i] << " ";
			cout << endl;
			break;
		case 10:
			cout << "operator ()" << endl;
			cout << "바꿀 값 확인:";
			cin >> num1;
			v[n](num1);
			cout << "v[" << n << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			cout << "v[" << n << "]의 used 는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
	
		case 11:
			cout << "operator +=" << endl;
			cout << "연산대상 객체 선택" << endl;
			cin >> num1;
			v[n] += v[num1];
			cout << "v[" << n << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout<<endl;
			cout << "v[" << n << "]의 size는 " << v[n].size() << ", CAPACITY는 " << v[n].capacity() << endl;
			break;
		case 12:
			cout << "Vector +" << endl;
			cout << "연산 대상 객체 번호 입력:" << endl;
			cin >> num1;
			cout << "연산 결과 객체 번호 입력:" << endl;
			cin >> num2;
			v[num2] = v[n] + v[num1];
			cout << "v[" << num2 << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			break;
		case 13:
			cout << "Vector -" << endl;
			cout << "연산 대상 객체 번호 입력:" << endl;
			cin >> num1;
			cout << "연산 결과 객체 번호 입력:" << endl;
			cin >> num2;
			v[num2] = v[n] - v[num1];
			cout << "v[" << num2 << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			break;
		case 14:
			cout << "vector dot product" << endl;
			cout << "연산대상 객체 선택" << endl;
			cin >> num1;
			cout << "v["<<n<<"]과 "<<"v["<<num1<<"] 내적 결과 값 : " << v[n] * v[num1] << endl;
			break;
		case 15:
			cout << "operator ==" << endl;
			cout << "연산대상 객체 선택" << endl;
			cin >> num1;
			cout << (v[n] == v[num1]) << endl;
			break;
		case 16:
			cout << "객체 재 선택"<<endl;
			break;
		case 17:
			cout << "v["<<n<<"]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			break;
		case 18:
			cout << "종료" << endl;
			delete[] v;
			return 0;
		case 19:
			cout << "operator =" << endl;
			cout << "연산대상 객체 2개 선택" << endl;
			cin >> num1>>num2;
			v[num2] = v[num1] = v[n];
			cout << "v[" << num2 << "]=v[" << num1 << "]=v[" << n << "] 실행"  << endl;
			
			cout << "v[" << num2 << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			cout << "v[" << num1 << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[num1].size(); i++)
				cout << v[num1][i] << " ";
			cout << endl;

			cout << "v[" << n << "]의 데이터 출력" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			break;
		default:
			break;
		}
	}
}