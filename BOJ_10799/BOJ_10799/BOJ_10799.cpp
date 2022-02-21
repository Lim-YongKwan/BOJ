#include<iostream>
#include<stack>

using namespace std;

int main() {

	string s;
	cin >> s;

	stack<int> stick;

	int answer = 0;
	int max = 0;
	for (int i = 0; i < s.length(); i++) {


		if (s[i] == '(' and stick.size() != 0) {
			stick.push(s[i]);
			answer++;
		}
		else if (s[i] == '(' and stick.size() == 0) {
			stick.push(s[i]);
		}

		else if (s[i] = ')' and stick.top() == '(') {
			stick.pop();
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}