#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int visit[51][51];
int cabbage[51][51];

struct node {
	int a;
	int b;
};

void DFS(queue<node>& organic,int n, int m) {

	node temp;
	int h = organic.front().a;
	int w = organic.front().b;
	organic.pop();
	visit[h][w] = 1;
	
	for (int i = 0; i < 4; i++) {
		if (visit[h + directions[i][0]][w + directions[i][1]] == 0 and cabbage[h + directions[i][0]][w + directions[i][1]] == 1) {
			if (h + directions[i][0] != 0 or h + directions[i][0] != m or w + directions[i][1] != 0 or w + directions[i][1] != n) {

				temp.a = h + directions[i][0];
				temp.b = w + directions[i][1];
				organic.push(temp);
				DFS(organic, n, m);
			}
		}
	}
	return;
}

int main() {

	int testcase;
	cin >> testcase;
	while (testcase--) {

		

		int m, n, k;
		cin >> m >> n >> k;

		queue<node> organic;
		for (int i = 0; i < k; i++) {
			int a = 0;
			int b = 0;
			cin >> a >> b;
			cabbage[a + 1][b + 1] = 1;
			
		}


		int count = 0;

		
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i][j] == 0 and cabbage[i][j] == 1) {

					node temp;
					temp.a = i;
					temp.b = j;
					organic.push(temp);
					DFS(organic,n,m);
					count++;
				}
			}
		}

		cout << count << endl;

		for (int i = 0; i <= m; i++) {
			memset(cabbage[i], 0, sizeof(cabbage[i]));
			memset(visit[i], 0, sizeof(visit[i]));
		}
	}

	return 0;
}