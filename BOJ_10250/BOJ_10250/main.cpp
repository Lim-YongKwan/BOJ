#include<iostream>

using namespace std;

int main() {

	int h;
	int w;
	int n;

	int testcase;
	cin >> testcase;

	int first = 0; 
	int last = 0;

	for (int T = 1; T <= testcase; T++) {

		first = 0;
		last = 0;
		//������ 101

		//2 2 4
		//���� ���� : 4/2 = 2
		//���� ���� : ���� 0�̶� 2
		//6 12 7
		// 102
		//���� ���� :7/6 = 1
		//���� ���� : ���� 1�ε� 6*1<7 �̴� ���� 1�� ����.
		//2 10 1
		//���� ���� : 1/2 = 0
		//���� ���� : ���� 1�̰� 0*2 <1�̴� ���� ó������.
		//2 2 4
		// 202
		// ���� ���� : 4/2 = 2
		//���� ���� : ���� 0�̶� 2
		//99 99 1
		//���� ���� : 1/ 99 = 0
		// ���� ���� : ���� 1��. 0*99<1.....
		//3 10 2
		//201
		//���� ���� : 2/3 = 0
		//���� ���� : ���� 2�̴� �״�� 2

		cin >> h >> w >> n;
		first = n % h;

		first *= 10;

		if (first == 0)
			first=h*10;


		last = n / h;

		if (n > h*last) {
			last++;
		}

		if (last >= 10)
			first /= 10;

		cout << first << last << endl;

	}
	return 0;
}