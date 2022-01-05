#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define endl "\n"

using namespace std;

int binary[100001];

int binary_search(int binary[], int n , int finding) {
	int low = 0;
	int end = n-1;
	int middle = (low + end) / 2;
	

	while (low<=end) {
		if (binary[middle] < finding) {
			low = middle +1;
			middle = (low + end) / 2;
		}
		else if (binary[middle] > finding) {
			end = middle -1;
			middle = (low + end) / 2;
		}
		else if (binary[middle] == finding) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		binary[i] = temp;
	}

	sort(binary, binary + n);

	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << binary_search(binary, n, temp) << endl;
	}
	

	return 0;
}