#include<iostream>
#include<vector>

using namespace std;

void gcd(vector<int>* v) {
	
	cout << v[0][0] << endl;
	
}

int main() {


	vector<int> v[100];
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	v[0] = temp;
	gcd(v);

	return 0;
}