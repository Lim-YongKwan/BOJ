#include<iostream>

using namespace std;

int main() {

	int year;
	cin >> year;

	if (year % 400 == 0) {
		cout << 1 << endl;
	}
	else if (year % 4 == 0) {
		if (year % 100 == 0) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else
		cout << 0 << endl;
	return 0;
}