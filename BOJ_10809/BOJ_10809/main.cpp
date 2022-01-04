#include<iostream>

using namespace std;

int main() {

	string s;
	cin >> s;
	//a = 97;

	int alphabet[28];
	fill_n(alphabet, 27, -1);
	
	for (int i = 0; i < s.length(); i++) {
		if(alphabet[s[i]-97] == -1)
			alphabet[s[i] - 97]=i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}


	return 0;
}