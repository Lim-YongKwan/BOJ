#include<iostream>

using namespace std;

int n, m;
int natural[10];
int visit[10];

void backtracking(int k) {

	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << natural[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if(visit[i] == 0){
			natural[k] = i;
			visit[i] = 1;
			backtracking(k + 1);
			visit[i] = 0;
		}
	}
}



int main() {

	cin >> n >> m;

	backtracking(0);

	return 0;
}