#include<iostream>
#define endl "\n"
using namespace std;

int sorting[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int max=0;
	int temp=0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		sorting[temp]++;
		if (max < temp) {
			max = temp;
		}
	}

	for (int i = 1; i <= max; i++) {
		if (sorting[i] != 0)
		{
			for (int j = 0; j < sorting[i]; j++) {
				cout << i << endl;
			}
		}
	}


	return 0;
}