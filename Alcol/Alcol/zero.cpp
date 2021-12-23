#include<iostream>
#include<cstring>

using namespace std;


int main() {

	int  number, answer;
	float dump;
	int B, L, N;
	float glass[201][2001] = { 0, };

	int T;
	cin >> T;

	while (T--) {

		cin >> B >> L >> N;

		glass[1][1] = 7 * B;

		for (int i = 1; i < L; i++) {
			number = 1;
			for (int j = 1; j <= i; j++) {
				for (int k = 1; k <= j; k++) {
					dump = glass[i][number] - 1;
					if (dump > 0) {
						glass[i + 1][number] += dump / 3;
						glass[i + 1][number + j] += dump / 3;
						glass[i + 1][number + j + 1] += dump / 3;
						
					}
					number++;
					

				}
			}
			
		}
		if (glass[L][N] >= 1) {
			answer = 1;
		}
		else if (glass[L][N] < 1&& glass[L][N]>0) {
			answer = 2;

		}
		else
		{
			answer = 0;
		}
		cout << answer << endl;

		memset(glass, 0, sizeof(glass));
	}

}