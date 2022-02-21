#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visit[20001];

void binary_bfs(vector<vector<bool>>& component, int n, queue<int>& graph) {
	
	int temp = graph.front();
	graph.pop();
	component[temp][temp] = 0;
	
	for (int i = 1; i <= n; i++) {
		if (visit[i - 1] == 0 and component[temp][i] == 1) {
			visit[i] = 1;
			component[temp][i] = 0;
			component[i][temp] = 0;
			component[i][i] = 0;
			graph.push(i);
		}
		else if (visit[i - 1] = 1 and component[temp][i] == 1) {
			visit[i] = 0;
			component[temp][i] = 0;
			component[i][temp] = 0;
			component[i][i] = 0;
			graph.push(i);
		}
	}

	if (graph.size() > 0) {
		binary_bfs(component, n, graph);
	}

	return;
}


int main() {

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int v, e;
		cin >> v >> e;


		int a, b;
		vector<vector<bool>> graph;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
			graph[a][a] = 1;
			graph[b][b] = 1;
		}

		queue<int> temp;
		for (int i = 1; i <= v; i++) {
			if (graph[i][i] == 1) {
				temp.push(i);
				binary_bfs(graph, v, temp);
			}
		}

		int count = 0;
		for (int i = 1; i <= v; i++) {
			if (visit[i - 1] != visit[i]) {
				count++;
			}
		}
		if (count == v / 2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}