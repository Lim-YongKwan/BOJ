#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void dream(string s) {

	int k = 0;
	int bonds = 0;
	int total = 0;

	for (int i = 0; i < s.length(); i++) {
		int temp = i;
		int repeat;
		
		repeat = i+1;
		if (repeat > s.length() / 2) {
			repeat = s.length() - repeat;
		}
		int count = 1;

		while (repeat--){
			
			if (s[temp] == 'A') {
				if (s[temp+count] == 'T') {
					bonds++;
				}
				//T라면
			}
			else if (s[temp] == 'T') {
				if (s[temp+count] == 'A') {
					bonds++;
				}
				//A라면
			}
			else if (s[temp] == 'C') {
				if (s[temp+count] == 'G') {
					bonds++;
				}
				//G라면
			}
			else if (s[temp] == 'G') {
				if (s[temp+count] == 'C') {
					bonds++;
				}
				//C라면
			}
			temp--;
			count+=2;
		}

		if (bonds > total) {
			total = bonds;
			k = i+1;
		}
		bonds = 0;
	}

	cout << k << " " << total << endl;
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;
	dream(s);

	return 0;
}