#include<iostream>

using namespace std;

int tree[1000001];

int main() {

	int n, m;

	int temp_max = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		if (tree[i] > temp_max) {
			temp_max = tree[i];
		}
	}


	long long start;
	long long end = temp_max;
	long long mid;

	while (start < end) {

	}

	return 0;
}