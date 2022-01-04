#include<iostream>

using namespace std;

int main() {

	int a;

	int verify = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		verify += a * a;

	}
	cout << verify % 10 << endl;

	return 0;
}