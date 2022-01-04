#include<iostream>
#include<string>
using namespace std;

int num_reverse(int n) {
	string s;
	int answer = 0;
	while (n >= 1) {
		s += to_string(n % 10);
		n /= 10;
	}
	answer = stoi(s);
	return answer;
}

int main() {

	int first = 0;
	int second = 0;
	cin >> first >> second;
	first = num_reverse(first);
	second = num_reverse(second);
	if (first > second) {
		cout << first << endl;
	}
	else
		cout << second << endl;


	return 0;
}