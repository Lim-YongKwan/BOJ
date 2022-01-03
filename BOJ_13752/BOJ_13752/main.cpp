#include<iostream>

#define endl "\n"

using namespace std;

int main() {

	int testcase;
	cin >> testcase;
	for (int T = 1;T <= testcase; T++) {

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "=";
		}
		cout << endl;

	}

	return 0;
}