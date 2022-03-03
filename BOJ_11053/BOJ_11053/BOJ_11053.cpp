#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int DP[1001];

int main() {

	int n;
	cin >> n;

	vector<int> sequence;
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}


	//1���� �������� �ְ� �� �������� ����.
	//if(�����ִ°ͺ��� Ŭ��)
	//���� or �� ����.

	int count = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				if (DP[i] <= DP[j]) {
					DP[i] = DP[j]+1;

					DP[i] = DP[j] + 1;
				}
			}
			else if (sequence[i] < sequence[j]) {
				continue;
			}
			else {
				DP[i] = DP[j];
			}
		}
	}

	cout << *max_element(DP, DP+n)+1 << endl;
	cout << *max_element(DP, DP + n) + 1 << endl;

	return 0;
}