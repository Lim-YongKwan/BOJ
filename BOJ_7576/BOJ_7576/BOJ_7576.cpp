#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int tomato[1001][1001];
int visit[1001][1001];
int directions[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };

struct node {
	int a;
	int b;
};

int answer=0;

void BFS(queue<node>& vegetable, int n , int m) {

	if (vegetable.size() <= 0) {
		return;
	}


	int w = vegetable.front().a;
	int h = vegetable.front().b;

	vegetable.pop();
	if (visit[w][h] == 1)
		return;

	if (w == n+1 or h == m+1 or w == 0 or h == 0) {
		return;
	}
	//cout << "tomato[" << w << "][" << h << "] : " << tomato[w][h] << endl;


	visit[w][h] = 1;

	for (int i = 0; i < 4; i++) {
		if (visit[w + directions[i][0]][h + directions[i][1]] == 0 && tomato[w + directions[i][0]][h + directions[i][1]] == 0 and w+directions[i][0] != n+1 and w+directions[i][0] != 0 and h+directions[i][1] != m+1 and h+directions[i][1] != 0) {
			node temp;
			tomato[w + directions[i][0]][h + directions[i][1]] = tomato[w][h] +1;
			temp.a = w + directions[i][0];
			temp.b = h + directions[i][1];
			vegetable.push(temp);
			answer = max(answer, tomato[w+directions[i][0]][h+directions[i][1]]);
		//	cout << "tomato[" << w+directions[i][0] << "][" << h+directions[i][1] << "] : " << tomato[w + directions[i][0]][h + directions[i][1]];
		//	cout << " answer : " << answer << endl;
		}
	}
	//cout << "Å»Ãâ : " << endl;
	return;
}

int main() {

	int m, n;
	cin >> m >> n;

	queue<node> vegetable;
	int total = n*m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				node temp;
				temp.a = i;
				temp.b = j;
				vegetable.push(temp);
				//visit[i][j] = 1;

			}
			else if (tomato[i][j] == -1) {
				visit[i][j] = 1;
			}
		}
	}


	while(vegetable.size()>0){
		BFS(vegetable, n, m);
		if (vegetable.size() == 0)
			break;
		//cout << "vegetable : "<<vegetable.front().a << " " << vegetable.front().b << endl;
		//cout << "vegetable.size() : " << vegetable.size() << endl;
	}

	int temp_max = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp_max = max(temp_max, tomato[i][j]);
			if (tomato[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
		//	cout << tomato[i][j] << " ";
		}
		//cout << endl;
	}


	cout << temp_max-1 << endl;

	return 0;
}