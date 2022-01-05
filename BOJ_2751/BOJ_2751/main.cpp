#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> sorting;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sorting.push_back(a);
	}
	sort(sorting.begin(), sorting.end());

	vector<int>::iterator iter;
	
	for (iter = sorting.begin(); iter != sorting.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}