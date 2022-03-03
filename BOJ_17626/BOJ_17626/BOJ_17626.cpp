#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int DP[50001] = { 0, };

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for (int i = 4; i <= n; i++) {
		DP[i] = DP[1]+DP[i-1];
		for (int j = 2; j*j <= i; j++) {
			DP[i] = min(DP[i], 1 + DP[i - j * j]);
		}
		
	}
	cout << DP[n] << endl;

	return 0;
}