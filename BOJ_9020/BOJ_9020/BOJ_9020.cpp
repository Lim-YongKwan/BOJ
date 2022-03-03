#include<iostream>
#include<algorithm>

using namespace std;

int prime[10000];

void eratos() {

	prime[1] = 1;
	prime[0] = 1;
	for (int i = 2; i <= 100; i++) {

		if (prime[i] == 0) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = 1;
			}
		}
	}
	return;
}

void goldbach(int n) {

	int a = 0;
	int b = 0;
	int temp_min = 10000;

	for (int i = 2; i < n; i++) {
		if (prime[i] == 0) {
			if (prime[n - i] == 0) {
				
				if (temp_min > abs(n - i - i)) {
					
					a = i;
					b = n - i;
					temp_min = abs(n - i - i);
				}

			}
		}
	}
	cout << a << " " << b << endl;
	return;
}

int main() {

	int testcase;
	cin >> testcase;

	int n;
	eratos();
	while (testcase--) {
		cin >> n;
		goldbach(n);
	}

	return 0;
}