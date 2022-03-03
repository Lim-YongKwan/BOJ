#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int testcase;
	cin >> testcase;

	while (testcase--) {
		
		int temp = 0;
		vector<int> bigger;
		for (int i = 0; i < 10; i++) {
			cin >> temp;
			bigger.push_back(temp);
		}
		sort(bigger.begin(), bigger.end());
		cout << bigger[7] << endl;
	}

	return 0;
}