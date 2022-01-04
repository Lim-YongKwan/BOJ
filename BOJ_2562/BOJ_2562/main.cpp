#include<iostream>

using namespace std;

int main() {

	int index=0;
	int max=0;
	int a;
	for (int i = 1; i <= 9; i++) {
		cin >> a;
		if (max < a) {
			max = a;
			index = i;
		}
	}
	cout << max << endl;
	cout << index << endl;
	return 0;
}