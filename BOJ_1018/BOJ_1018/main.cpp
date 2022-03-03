#include<iostream>
#include<algorithm>

using namespace std;

char chess[51][51];

int chessboard(int n, int m) {

	int white = 0;
	int black = 0;

	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if ((i+j)%2 == 0) {
				if (chess[i][j] == 'W') {
					white++;
				}
				else if (chess[i][j] == 'B') {
					black++;
				}
			}
			else if((i+j)%2 != 0){
				if (chess[i][j] == 'B') {
					white++;
				}
				else if (chess[i][j] == 'W') {
					black++;
				}
			}
		}
	}

	int temp = min(white, black);
	return temp;
}

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	int answer = 123456789;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			answer = min(answer, chessboard(i,j));
		}
	}
	cout << answer << endl;

	return 0;
}