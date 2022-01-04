#include<iostream>

using namespace std;

int main() {

	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	int total;
	total = a * b * c;

	int index[10] = { 0, };
	while (total >= 1) {
		index[total % 10]++;
		total /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		cout << index[i] << endl;
	}

	return 0;
}