#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;


bool BFS_arr[1001][1001] = { 0, }; 
int N, M;

struct BFS_node {
	int first;
	int second;
};

void BFS(queue<BFS_node>& store, int b);

int main() {

	int a;
	int b;
	cin >> a >> b;

	cin >> N >> M;

	int map_first;
	int map_second;


	for (int i = 1; i <= M; i++) {
		cin >> map_first >> map_second;
		BFS_arr[map_first][map_second] = 1;
		BFS_arr[map_second][map_first] = 1;
	}


	if (a == b) {
		cout << 0 << endl;
		return 0;
	}

	queue<BFS_node> store;
	store.push({ a,1});
	int num = 0;
	
	BFS(store,b);

	return 0;
}

void BFS(queue<BFS_node>& store, int b) {
	int a = store.front().first;
	int num = store.front().second;
	//queue값을 빼면서 다시 queue값에 넣기.
	store.pop();
	
	for (int i = 1; i <= N; i++) {
		if (BFS_arr[a][i] == 1) {
			store.push({ i, num+1});
			BFS_arr[a][i] = 0;
			BFS_arr[i][a] = 0;
			if (i == b) {
				cout << num << endl;
				return;
			}
		}
	}

	if (store.size() == 0) {
		cout << "-1" << endl;
		return;
	}
	else if (store.size() != 0) {
		BFS(store, b);
	}
}