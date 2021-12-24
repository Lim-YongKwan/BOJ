#include<iostream>
#include<cmath>
#define endl "\n"

using namespace std;

int main() {

	int N;
	cin >> N;

	/*

	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

	1이라면 1
	2이라면 2
	3이라면 2
	4이라면 4
	5이라면 4
	6이라면 4
	7이라면 4
	8이라면 8
	9이라면 8
	10이라면 8
	11이라면 8
	12이라면 8
	13이라면 8
	14이라면 8
	15이라면 8
	16이라면 16
	2^n의 법칙으로 커짐.
	*/

	for (int i = 0; i < N; i++)
	{
		if (pow(2, i+1) > N) {
			cout << pow(2, i) << endl;
			break;
		}

	}



	return 0;
}