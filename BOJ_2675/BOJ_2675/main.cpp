#include<iostream>
#include<string>
using namespace std;

int main() {

	int testcase;
	cin >> testcase;

	for (int T = 1; T <= testcase; T++) {

		int a;
		cin >> a;
		string s;
		cin >> s;
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < a; j++) {
				cout << s[i];
			}
		}
		cout << endl;
	}

	return 0;
}