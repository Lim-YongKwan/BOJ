#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
using namespace std;

long long dp[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int n;
	cin >> n;
	long long temp;
	vector<long long> blobnum;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		blobnum.push_back(temp);
	}
	long long max_temp = 0;
	for (int i = 1; i < n - 1; i++) {
		dp[i] = blobnum[i]+min(blobnum[i - 1], blobnum[i + 1]);
		max_temp = max(dp[i], max_temp);
	}

	cout << max_temp << endl;

	return 0;
}