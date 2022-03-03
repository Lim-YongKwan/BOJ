#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;



int main() {

	int n;
	cin >> n;

	int temp = 2;
	for (int i = 3; i <= n; i++) {
		temp ^= i;
		cout << "i : " << i << " ";
		cout <<"temp : "<< temp << endl;
	}


	return 0;
}