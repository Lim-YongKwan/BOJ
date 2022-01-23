#include<iostream>

using namespace std;

int DP[101][10];

int main() {

	int a;
	cin >> a;

	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= a; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j == 1) {
				DP[i][j] = (DP[i - 1][2] + DP[i - 1][9]) % 1000000000;
			}
			else if (j == 9) {
				DP[i][j] = (DP[i - 1][8]) % 1000000000;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	long long answer = 0;
	
	for (int i = 1; i <= 9; i++) {
		answer += DP[a][i];
	}

	cout << answer % 1000000000 << endl;
	return 0;
}