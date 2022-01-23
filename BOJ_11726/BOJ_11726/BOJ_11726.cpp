#include<iostream>

using namespace std;


int fibbonachi[1002];

int main() {

	//피보나치

	int a;
	cin >> a;
	fibbonachi[1] = 1;
	fibbonachi[2] = 2;
	fibbonachi[3] = 3;
	fibbonachi[4] = 5;

	for (int i = 5; i <= a; i++) {
		fibbonachi[i] = (fibbonachi[i - 1] + fibbonachi[i - 2])%10007;
	}

	cout << fibbonachi[a] % 10007 << endl;

	return 0;
}