#include<iostream>
#include<cmath>
#define endl "\n"

using namespace std;

int main() {

	int N;
	cin >> N;

	/*

	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

	1�̶�� 1
	2�̶�� 2
	3�̶�� 2
	4�̶�� 4
	5�̶�� 4
	6�̶�� 4
	7�̶�� 4
	8�̶�� 8
	9�̶�� 8
	10�̶�� 8
	11�̶�� 8
	12�̶�� 8
	13�̶�� 8
	14�̶�� 8
	15�̶�� 8
	16�̶�� 16
	2^n�� ��Ģ���� Ŀ��.
	*/

	for (int i = 0; i < N; i++)
	{
		if (pow(2, i+1) > N) {
			cout << pow(2, i) << endl;
			break;
		}

	}



	return 0;
}