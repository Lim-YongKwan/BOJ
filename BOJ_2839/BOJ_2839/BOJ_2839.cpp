#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int sugar[5001] = { 0, };

	sugar[0] = 0;
	sugar[1] = 0;
	sugar[2] = 0;
	sugar[3] = 1;
	sugar[4] = 0;
	sugar[5] = 1;

	for (int i = 6; i <= n; i++) {
		sugar[i] = 0;
		if(sugar[i-3]>0 and sugar[i-5]>0)
			sugar[i] = min(sugar[i - 3]+1,sugar[i-5]+1) ;
		else if (sugar[i - 3] > 0) {
			sugar[i] = sugar[i - 3] + 1;
		}
		else if (sugar[i - 5] > 0) {
			sugar[i] = sugar[i - 5] + 1;
		}
	}

	if (sugar[n] == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << sugar[n] << endl;
	}

	return 0;
}