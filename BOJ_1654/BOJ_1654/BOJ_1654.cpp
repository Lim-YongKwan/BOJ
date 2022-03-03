#include<iostream>
#include<vector>

using namespace std;

int k, n;
int ransun[10002];

bool solve(long long x) {
	long long cur = 0;
	for (int i = 0; i < k; i++) {
		cur += ransun[i] / x;
	}
	return cur >= n;
}

int main() {

	cin >> k >> n;

	int max = 0;
	for (int i = 0; i < k; i++) {
		cin >> ransun[i];
		if (max < ransun[i])
			max = ransun[i];
	}

	long long high = max;
	long long low = 1;
	long long mid;

	while (low < high) {
		mid = (low + high+1) / 2;
		if (solve(mid))
		{
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << low << endl;

	return 0;
}