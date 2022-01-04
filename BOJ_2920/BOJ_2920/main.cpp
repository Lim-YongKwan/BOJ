#include<iostream>

using namespace std;

int main() {

	int ascending[9];
	for (int i = 1; i <= 8; i++) {
		cin >> ascending[i];
	}

	int asc = 0;
	int des = 0;

	for (int i = 1; i <= 8; i++) {
		
		if (ascending[i] == i) {
			asc++;
		}
		else if (ascending[i] == 9 - i) {
			des++;
		}
	}
	if (asc == 8) {
		cout << "ascending" << endl;
	}
	else if (des == 8) {
		cout << "descending" << endl;
	}
	else
		cout << "mixed" << endl;

	return 0;
}