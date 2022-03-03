#include<iostream>
#include<string.h>
using namespace std;

int zero;
int first;

int main() {

	int fibonacci[41];

	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(fibonacci, 0, sizeof(fibonacci));

		int n;
		cin >> n;
		if (n == 0) {
			cout << "1 0" << endl;
			continue;
		}
		else if (n == 1) {
			cout << "0 1" << endl;
			continue;
		}
	
		fibonacci[0] = 1;
		fibonacci[1] = 1;
		for (int i = 2; i <n; i++) {
			fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		}
		cout << fibonacci[n-2] << " "<<fibonacci[n-1] << endl;
	}

	return 0;
}