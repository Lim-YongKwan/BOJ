#include<iostream>
using namespace std;

int main() {
	
	int remainder[43] = { 0, };
	int int_num[11];
	for (int i = 1; i <= 10; i++) {
		cin >> int_num[i];
	}
	for (int i = 1; i <= 10; i++) {
		remainder[int_num[i] % 42] = 1;
	}
	int total = 0;
	for (int i = 0; i < 42; i++) {
		total += remainder[i];
	}
	cout << total << endl;

	return 0;
}