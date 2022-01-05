#include<iostream>
#include<algorithm>
#include<string>
#define endl "\n"

using namespace std;

int main() {

	string s;
	string reverse_s = "";
	while (cin >> s) {
		if (s == "0")
			break;
		else
		{
			reverse_s = s;
			reverse(s.begin(), s.end());
			if (reverse_s == s)
			{
				cout << "yes" << endl;
			}
			else
				cout << "no" << endl;
		}
		reverse_s = "";
		s = "";
	}

	return 0;
}