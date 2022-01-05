#include<iostream>

#define endl "\n"

using namespace std;

int gcd(int a, int b) {
	int c = 0;
	if (a >= b) {
		c = a % b;
	}
	else {
		c = b;
		b = a;
		a = c;
		c = a % b;
	}

	while (c>0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int lcm(int a, int b, int gcd_num) {
	return a * b / gcd_num;
}

int main() {
	int a;
	int b;
	int gcd_num = 0;
	cin >> a >> b;
	gcd_num = gcd(a, b);
	cout << gcd_num<< endl;
	cout <<lcm(a,b,gcd_num) << endl;
	return 0;
}