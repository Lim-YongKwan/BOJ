#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

int directions[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int visit[101][101];
int safety[101][101];
int emergency[101][101];

struct node {
	int h;
	int w;
};

void BFS(int n,queue<node>& flood) {

	node temp;
	temp = flood.front();
	flood.pop();
	int a = temp.h;
	int b = temp.w;
	visit[a][b] = 1;
	if (a == n + 1 or b == n + 1 or a == 0 or b == 0) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (visit[a + directions[i][0]][b + directions[i][1]] == 0 and safety[a + directions[i][0]][b + directions[i][1]] >= 1)
		{
			if (a + directions[i][0] != 0 or a + directions[i][0] != n or b + directions[i][1] != 0 or b + directions[i][1] != n)
			{
				temp.h = a + directions[i][0];
				temp.w = b + directions[i][1];
				flood.push(temp);
				BFS(n, flood);
			}
		}
	}

	return;
}

int main() {

	int n;
	cin >> n;

	int max_temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> emergency[i][j];
			max_temp = max(emergency[i][j], max_temp);
		}
	}

	queue<node> flood;

	int count = 0;
	int answer_count = 0;

	for (int i = 0; i <= max_temp; i++) {
	//	cout << "i : " << i << endl;
		for (int j = 1; j <= n; j++) {
			memset(safety[j], 0, sizeof(safety[j]));
			memset(visit[j], 0, sizeof(visit[j]));
		}

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				safety[j][k] = emergency[j][k] - i;
				
				if (safety[j][k] <= 0) {
					visit[j][k] = 1;
				}
			}
		}
		

		for(int j = 1;j<=n;j++){
			for (int k = 1; k <= n; k++) {
				if (safety[j][k] >= 1 and visit[j][k] == 0) {
					node temp;
					temp.h = j;
					temp.w = k;
					flood.push(temp);
					BFS(n, flood);
					count++;
				}
			}
		}
		answer_count = max(count, answer_count);
		count = 0;
	}

	cout << answer_count << endl;

	return 0;
}