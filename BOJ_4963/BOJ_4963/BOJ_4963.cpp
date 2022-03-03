#include<iostream>
#include<cstring>

using namespace std;

int land[51][51];
int visit[51][51];
int direction[8][2] = { {0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

void BFS(int h, int w) {
	visit[h][w] = 1;
	for (int i = 0; i < 8; i++) {
		if (land[h+direction[i][0]][w + direction[i][1]] == 1 and visit[h+direction[i][0]][w+direction[i][1]] == 0) {
			BFS(h + direction[i][0], w + direction[i][1]);
		}
	}
	return;
}

int main() {

	int w, h;
	while (cin >> w >> h) {
		if (w == 0 and h == 0)
			break;
		for (int i = 0; i < 51; i++) {
			memset(visit[i], 0, sizeof(visit[i]));
			memset(land[i], 0, sizeof(land[i]));
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> land[i][j];
			}
		}
		int count = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visit[i][j] == 0 and land[i][j] == 1) {
					BFS(i,j);
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}