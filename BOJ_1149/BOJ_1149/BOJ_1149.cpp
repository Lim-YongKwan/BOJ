#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int RGB[1001][3] = { 0, };

	for (int i = 1; i <= n; i++) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
	int DP[1002][3] = { 0, };
	DP[0][0] = 0;
	DP[0][1] = 0;
	DP[0][2] = 0;
	RGB[0][0] = 0;
	RGB[0][1] = 0;
	RGB[0][2] = 0;

	for (int i = 1; i <= n; i++) {

		DP[i][0] += min(DP[i-1][1], DP[i-1][2]) + RGB[i][0];
		DP[i][1] += min(DP[i-1][0], DP[i-1][2]) + RGB[i][1];
		DP[i][2] += min(DP[i-1][0], DP[i-1][1]) + RGB[i][2];

	}
	
	int answer = 0;
	answer = min(min(DP[n][0], DP[n][1]), DP[n][2]);

	cout << answer << endl;

	return 0;
}