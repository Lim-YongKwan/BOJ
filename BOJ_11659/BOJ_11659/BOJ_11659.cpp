#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<long long> accumulation;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		accumulation.push_back(temp);
	}

	long long answer[100001] = { 0, };
	answer[0] = 0;
	answer[1] = accumulation[0];
	for (int i = 1; i < n; i++) {
		answer[i+1] += answer[i]+accumulation[i];
	}
	
	while (m--) {
		
		int a; int b;
		cin >> a >> b;
		

		cout << answer[b] - answer[a-1] << endl;
	
	}
	

	return 0;
}