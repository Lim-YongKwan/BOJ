#include<iostream>
#include<vector>
using namespace std;

int card[1001];
int DP[1001];

int main() {

	int n;
	cin >> n;

	int temp;
	card[0] = 0;
	DP[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= n; i++) {
		DP[i] = card[i];
	}
	
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j <= i; j++) {

			if (card[i - j] + DP[j] > DP[i])
				DP[i] = card[i - j] + DP[j];
		}
	}

	cout << DP[n] << endl;



	return 0;
}