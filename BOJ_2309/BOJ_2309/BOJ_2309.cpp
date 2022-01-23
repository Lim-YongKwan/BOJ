#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main() {

	vector<int> dwarf;

	int temp;
	int total = 0;

	for (int i = 0; i < 9; i++) {
		cin >> temp;
		total += temp;
		dwarf.push_back(temp);
	}
	int a;
	int b; 
	int count = 0;
	for (int i = 0; i < 8; i++) {
		a = dwarf[i];
		for (int j = i + 1; j < 9; j++) {
			b = dwarf[j];
			if (total - (a + b) == 100) {
				count = 1;
				break;
			}
		}
		if (count == 1)
			break;
	}
	sort(dwarf.begin(), dwarf.end());

	for (int i = 0; i < 9; i++) {
		if (dwarf[i] == a || dwarf[i] == b)
			continue;
		cout << dwarf[i] << endl;
		
	}
	return 0;
}