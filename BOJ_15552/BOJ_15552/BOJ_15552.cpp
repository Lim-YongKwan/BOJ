#include<iostream>

#define endl "\n"

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testcase;
	cin >> testcase;
	int a, b;
	while(testcase--) {
		a = 0; b = 0;
		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}