#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int prime[10001];

void eratos() {
	prime[1] = 1;
	prime[0] = 1;

	for (int i = 2; i <= 100; i++) {
		if (prime[i] == 0) {
			for (int j = i*i; j <= 10000; j += i) {
				prime[j] = 1;
			}
		}
	}
	return;
}

int main() {


	eratos();
	
	int m, n;
	cin >> m >> n;
	vector<int> answer;
	int total = 0;
	for (int i = m; i <= n; i++) {
		if (prime[i] == 0){
			total += i;
			answer.push_back(i);
		}
	}
	if (answer.size() < 1) {
		cout << "-1" << endl;
		return 0;
	}
	else {
		cout << total << endl;
		cout << answer[0] << endl;
	}
	return 0;
}