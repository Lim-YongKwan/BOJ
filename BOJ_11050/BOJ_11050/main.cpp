#include<iostream>

using namespace std;


int main() {
	//���װ�� ���ϴ� �˰���.

	int a;
	int b;
	cin >> a >> b;
	int first = 1;
	int last = 1;

	for (int i = a; i > (a - b); i--) {
		first *= i;
	}

	for (int i = b; i > 1; i--) {
		last *= i;
	}
	cout << first / last << endl;

	return 0;
}