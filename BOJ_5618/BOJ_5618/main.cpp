#include<iostream>
#define endl "\n"

using namespace std;

int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num = 0;
	cin >> num;

	
	int a;
	int b;
	int c;
	int factor;
	if (num > 2) {
		cin >> a >> b >> c;
		factor = gcd(gcd(a, b), c);
	}
	else {
		cin >> a >> b;
		factor = gcd(a, b);
	}

	for (int i = 1; i <= factor; i++) {
		if (factor % i == 0)
			cout << i << endl;
	}

	return 0;
}

int gcd(int a, int b) {

	int c;

	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}