#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int directions[4][2] = { {0,1}, {1,0},{-1,0},{0,-1} };
int maze[101][101];
int visit[101][101];

struct node {
	int a;
	int b;
};

void BFS(int n, int m,queue<node>& graph) {

	
	int w = graph.front().a;
	int h = graph.front().b;
	if (w == n + 1 or w == 0 or h == m + 1 or h == 0)
		return;
	graph.pop();

	visit[w][h] = 1;


	for (int i = 0; i < 4; i++) {
		if (visit[w + directions[i][0]][h+directions[i][1]] == 0 and maze[w+directions[i][0]][h+directions[i][1]] == 1) {
			if (w + directions[i][0] != 0 and w + directions[i][0] != n + 1 and h + directions[i][1] != 0 and h + directions[i][1] != m + 1) {
				maze[w + directions[i][0]][h + directions[i][1]] = maze[w][h] + 1;
				node temp_graph;
				temp_graph.a = w + directions[i][0];
				temp_graph.b = h + directions[i][1];
				graph.push(temp_graph);
			}
		}
	}

	return;
}

int main() {

	int n, m;
	cin >> n >> m;

	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			maze[i][j] = temp - '0';
		}
	}
	queue<node> graph;
	node temp_graph;
	temp_graph.a = 1;
	temp_graph.b = 1;
	graph.push(temp_graph);

	while (true) {
		if (graph.size() < 1) {
			break;
		}
		BFS(n, m, graph);

	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << maze[n][m] << endl;

	return 0;
}