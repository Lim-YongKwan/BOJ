#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
using namespace std;

long long sticker[2][100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		
		int n;
		cin >> n;

		int temp;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp;
				sticker[i][j] = temp;
			}
		}

		sticker[0][1] += sticker[1][0];
		sticker[1][1] += sticker[0][0];

		for (int j = 2; j < n; j++){
			sticker[1][j] += max(sticker[0][j - 1], sticker[0][j - 2]);
			sticker[0][j] += max(sticker[1][j - 1], sticker[1][j - 2]);
		}

		cout << max(sticker[0][n-1], sticker[1][n-1]) << endl;
	}

	return 0;
}