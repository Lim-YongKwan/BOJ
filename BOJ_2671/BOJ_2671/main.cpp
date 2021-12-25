#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

int main() {

	//3������ ������.
	//1��°�� 100����
	//2��°�� 1
	//3��°�� 01
	//100�� �ڰ� �ƹ��� ������� ����� ����. 1000/10000/1000000/1000000000
	//1�� �ƹ��� �ڰ� ������� ����� ����, 1/11/111/11111/1111111
	//�� 100�� �ڿ� 1�� ���;� �Ѵ�.
	//01�� 1001�� ���̵� 1001�� ���̵� ����� ����.
	//�̻��� ������ �ް� �ִ��� �ƹ��� �ݺ��� �ƹ��� �Ͽ��� ����� ����.
	
	//10010111 �� false �ֳ��ϸ� �̿� ���� ��쿡�� 100101������ �������� �� �ڿ� 1�� �������� �ü��� ���� �����̴�. ���� 10010101111�̾����� true;
	//100000000001101 �� true �ֳ��ϸ� �̿Ͱ��� ��쿡�� ��� 0�� 1�� �ݺ��Ǿ��� �� ������ ��� ���� ����.
	
	string s;
	cin >> s;

	queue<char> submarine;
	for (int i = 0;i<s.length(); i++) {
		submarine.push(s[i]);
	}
	if (s.substr(s.length() - 3, 3) == "100") {
		cout << "NOISE" << endl;
		return 0;
	}


	for (int i = 0; i < s.length(); i++) {
		//1001100
		if (s.substr(i,3) == "100")
		{
			//cout << "100 : "<<i << endl;
			i += 3;
			submarine.pop();
			submarine.pop();
			submarine.pop();
			//1�� ���ö����� 0�� ��� ������.
			while (s[i] == '0') {
				submarine.pop();
				i++;
				
			}
			if (s[i] == '1')
			{
				//100 ������ 1�̶�� 
				submarine.pop();
				i++;
			}
			else {
				//���� 100������ 1�� �ƴ϶�� NOISE
				cout << "NOISE" << endl;
				return 0;
			}
			while (s[i] == '1') {
				//1001������ �ٽ� 100�� ���� ���ɼ��� �ִ�.
				if (s.substr(i, 3) == "100")
				{
					//ó������ ���ư���.
					break;
				}
				//cout<<"1 : " << i << endl;
				submarine.pop();
				i++;
			}
			i--;
		}
		if (s.substr(i, 2) == "01") {
			//������.
		//	cout<<"01 : " << i << endl;
			i ++;
			submarine.pop();
			submarine.pop();
		}
		//�ݺ�
	}

	if (submarine.size() != 0) {
		cout << "NOISE" << endl;
	}
	else {
		cout << "SUBMARINE" << endl;
	}
	return 0;
}