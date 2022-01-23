#include<iostream>
#include<math.h>

using namespace std;

int main() {

	long long x;
	cin >> x;

	long long n;
	n = sqrt(x);

	if (n * n < x)
		n++;

	cout << n << endl;

	return 0;
}