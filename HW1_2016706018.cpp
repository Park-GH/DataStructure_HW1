//2016706018 �ڰ���
#include "MyIntVector.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int main() {

	int object = 0;	//��ü ����
	int n = -1;		//��ü ��ȣ
	int num1 = 0, num2 = 0;	//���� ��� �� for���� ����� ������
	int select = 0; //�׽�Ʈ ��ȣ ����
	cout << "������ ��ü ���� �Է� : ";
	cin >> object;
	assert(object>0);

	MyIntVector * v = new MyIntVector[object]; //defult

	if(object==1)
		cout << "v[0] ��ü ���� �Ϸ� " << endl;
	else
	cout << "v[0]~v["<<object-1<<"] ��ü ���� �Ϸ� " << endl;
	while (1) {
		cout << endl;
		cout << "������ ��ü ��ȣ �Է�: ";
		cin >> n;
		//�Է¹��� n�� ���� ���� ��� �ٽ� �Է�
		while (!(n>=0 && n<object)) {
			cout << "��ü ���� ��, ���Է�: ";
			cin >> n;
		}
		system("cls");	//ȭ�� �����

		cout << "�׽�Ʈ�� ��ȣ�� �Է��ϼ���" << endl;
		cout << "** 9���� Uanry operator 13���� binary opeator **" << endl;
		cout << "1: push, 2: pop, 3: capacity, 4: size, 5: reserve, 6: is_empty, 7:clear" << endl;
		cout << "8: [], 9: -, 10: ()" << endl;
		cout << "11: +=, 12: +, 13: -, 14: *, 15: ==" << endl;
		cout << "16: ��ü �� ����, 17: ������ ����, 18: ����  19: =" << endl << endl;
		cout << "v[" << n << "]���� �� ������?" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout<<"push�� ���� �Է�:"<<endl;
			cin >> num2;
			cout << "data �Է�" << endl;
			for (int i = 0; i < num2; i++) {
				cin >> num1;
				v[n].push_back(num1);
			}
			cout << "push ���" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			cout <<"v["<<n<<"]�� size�� "<< v[n].size()<< ", CAPACITY�� " << v[n].capacity() << endl;
			break;
		case 2:
			cout << "pop Ƚ�� �Է�: " << endl;
			cin >> num2;
			cout << "pop ���" << endl;
			for (int i = 0; i < num2; i++) {
				cout << v[n][(int)v[n].size()-1] << " ";
				v[n].pop_back();
			}
			cout << endl;
			cout << "v[" << n << "]�� size�� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
		case 3:
			cout << "capacity Ȯ��" << endl;
			cout << v[n].capacity() << endl;
			break;
		case 4:
			cout << "size Ȯ��" << endl;
			cout << v[n].size() << endl;
			break;
		case 5:
			cout << "reserve�� ����?" << endl;
			cin >> num1;
			v[n].reserve(num1);
			cout << "v[" << n << "]�� size�� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
		case 6:
			cout << "is_empty ����" << endl;
			cout << v[n].is_empty() << endl;
			cout << "v[" << n << "]�� size�� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
		case 7:
			cout << "clear ����" << endl;
			v[n].clear();
			cout << "v[" << n << "]�� size�� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
	
		case 8:
			cout << "operator []" << endl;
			cout << "�������� �ε��� �Է�:";
			cin >> num1;
			cout << v[n][num1] << endl;
			break;
		case 9:
			cout << "operator -" << endl;
			cout << "������ ��ü ��ȣ �Է�" << endl;
			cin >> num1;
			v[num1]=-v[n];
			cout << "���� ��� v["<<num1<<"] ������ ���:"<<endl;
			for (int i = 0; i < (int)v[num1].size(); i++)
				cout << v[num1][i] << " ";
			cout << endl;
			break;
		case 10:
			cout << "operator ()" << endl;
			cout << "�ٲ� �� Ȯ��:";
			cin >> num1;
			v[n](num1);
			cout << "v[" << n << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			cout << "v[" << n << "]�� used �� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
	
		case 11:
			cout << "operator +=" << endl;
			cout << "������ ��ü ����" << endl;
			cin >> num1;
			v[n] += v[num1];
			cout << "v[" << n << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout<<endl;
			cout << "v[" << n << "]�� size�� " << v[n].size() << ", CAPACITY�� " << v[n].capacity() << endl;
			break;
		case 12:
			cout << "Vector +" << endl;
			cout << "���� ��� ��ü ��ȣ �Է�:" << endl;
			cin >> num1;
			cout << "���� ��� ��ü ��ȣ �Է�:" << endl;
			cin >> num2;
			v[num2] = v[n] + v[num1];
			cout << "v[" << num2 << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			break;
		case 13:
			cout << "Vector -" << endl;
			cout << "���� ��� ��ü ��ȣ �Է�:" << endl;
			cin >> num1;
			cout << "���� ��� ��ü ��ȣ �Է�:" << endl;
			cin >> num2;
			v[num2] = v[n] - v[num1];
			cout << "v[" << num2 << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			break;
		case 14:
			cout << "vector dot product" << endl;
			cout << "������ ��ü ����" << endl;
			cin >> num1;
			cout << "v["<<n<<"]�� "<<"v["<<num1<<"] ���� ��� �� : " << v[n] * v[num1] << endl;
			break;
		case 15:
			cout << "operator ==" << endl;
			cout << "������ ��ü ����" << endl;
			cin >> num1;
			cout << (v[n] == v[num1]) << endl;
			break;
		case 16:
			cout << "��ü �� ����"<<endl;
			break;
		case 17:
			cout << "v["<<n<<"]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			break;
		case 18:
			cout << "����" << endl;
			delete[] v;
			return 0;
		case 19:
			cout << "operator =" << endl;
			cout << "������ ��ü 2�� ����" << endl;
			cin >> num1>>num2;
			v[num2] = v[num1] = v[n];
			cout << "v[" << num2 << "]=v[" << num1 << "]=v[" << n << "] ����"  << endl;
			
			cout << "v[" << num2 << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[num2].size(); i++)
				cout << v[num2][i] << " ";
			cout << endl;
			cout << "v[" << num1 << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[num1].size(); i++)
				cout << v[num1][i] << " ";
			cout << endl;

			cout << "v[" << n << "]�� ������ ���" << endl;
			for (int i = 0; i < (int)v[n].size(); i++)
				cout << v[n][i] << " ";
			cout << endl;
			break;
		default:
			break;
		}
	}
}