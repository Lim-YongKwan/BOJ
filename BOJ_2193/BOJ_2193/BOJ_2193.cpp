#include<iostream>

using namespace std;

long long DP[92];

int main() {

	int n;
	cin >> n;

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 2;


	for (int i = 4; i <= n; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n] << endl;

	return 0;
}