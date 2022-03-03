#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int block[26][26];
int visit[26][26];

int direction[5][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int graph_num;

void DFS(int n,int x, int y) {
	
	if (x == 0 or y == 0) {
		return;
	}
	if (x == n+1 or y == n+1) {

		return;
	}
	if (visit[x][y] == 1) {
		return;
	}
	if (block[x][y] == 0){
		return;
	}

	visit[x][y] = 1;
	

	for (int i = 0; i < 4; i++) {
		if (block[x + direction[i][0]][y + direction[i][1]] == 1 and visit[x + direction[i][0]][y + direction[i][1]] == 0) {
			graph_num++;
			DFS(n,x+direction[i][0],y+direction[i][1]);
		}	
	}

	return ;
}

int main() {

	int n = 0;
	cin >> n;

	int total = 0;
	
	char temp;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			block[i][j] = temp-'0';
			if (block[i][j] == 1) {
				total++;
			}
		}
	}

	int count = 0;
	vector<int> answer;
	int number = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (block[i][j] != 0 and visit[i][j] == 0) {
				graph_num = 1;
				count++;
				DFS( n, i, j);
				answer.push_back(graph_num);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << count << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}