#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N;
	int a;
	int b;

	cin >> N >> a >> b;

	if ((a + b - 1) > N) {
		cout << "-1" << endl;
		exit(0);
	}

	vector<int> building;

	int temp = 0;

	for (int i = 0; i < N - (a + b - 1); i++) {
		building.push_back(1);
		//수정 필요.
	}

	//1을 최대한 넣는다.
	

	temp = 1;

	for (int i = 0; i < a; i++) {
		building.push_back(temp);
		temp++;
	}

	temp = b;
	
	for (int i = 0; i < b; i++) {
		building.push_back(temp);
		temp--;
	}
	

	
	

	for (int i = 0; i < N - (a + b - 1); i++) {
		cout << building[i];
		cout << " ";
		
	}
	if (a > b) {
		for (int i = N - (a + b - 1); i < N; i++) {
			cout << building[i];
			if (i != N - 1)
				cout << " ";
		}
	}
	else {
		for (int i = N - 1; i >= N - (a + b - 1); i--) {
			cout << building[i];
			if (i != N - (a + b - 1))
				cout << " ";
		}
	}
	
	return 0;
}