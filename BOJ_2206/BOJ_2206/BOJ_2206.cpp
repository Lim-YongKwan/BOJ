#include<iostream>
#include<queue>
#include<algorithm>
#define endl "\n"

using namespace std;

int maze[1001][1001]; // 미로 지도
int visit[1001][1001][3]; //방문을 했는지 확인 visit[n][m][0] 은 거리 횟수이고 visit[n][m][1] 은 벽을 부셨는지 아닌지 확인용. visit[n][m][2] 는 방문 확인.

struct node {
	int h; // 세로 축
	int w; // 가로 축
};

int directions[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void BFS(queue<node>& explore, int n ,int m) {

	node temp; //queue에서 처음 부분을 가져올 임시 노드
	temp = explore.front(); //처음 queue를 가져온다.
	explore.pop(); //queue의 처음 부분을 가져 왔으니 그대로 빼준다.

	if (temp.w == m+1 or temp.w == 0 or temp.h == 0 or temp.h == n+1) { //혹시 몰라서 해둔건데 안해도 될 것 같애서 주석 처리 했습니다.
		return;
	}
	if (visit[temp.h][temp.w][1] == 2) {
		return;
	}

	if (temp.h == n and temp.w == m) { //만일 maze의 도달점에
		if (maze[n][m] != 0) { //이미 누가 방문했다면
			maze[n][m] = min(maze[n][m],visit[n][m][0]); // 현재값과 비교해서 최솟값으로 바꾸자.
		}
		else { //아직 아무도 안 왔다면
			maze[n][m] = visit[n][m][0]; //현재값으로 바꾸자.
		}
	}

	for (int i = 0; i < 4; i++) { //4번 돌자.
		if (visit[temp.h + directions[i][0]][temp.w + directions[i][1]][2] == 0) { //만일 누가 이미 방문하지 않았고
			if (temp.h + directions[i][0] != n + 1 and temp.h + directions[i][0] != 0 and temp.w + directions[i][1] != m + 1 and temp.w + directions[i][1] != 0) { //범위 안에 있으며
				if (visit[temp.h][temp.w][1] + maze[temp.h + directions[i][0]][temp.w + directions[i][1]] != 2) { // 벽을 2번이상 안 뚫는다면
					node next; // 다음 노드 생성
					next.h = temp.h + directions[i][0]; // 세로 지정
					next.w = temp.w + directions[i][1]; // 가로 지정
					if (visit[next.h][next.w][0] != 0) {
						visit[next.h][next.w][0] = min(visit[next.h][next.w][0], visit[temp.h][temp.w][0] + 1);
					}
					else {
						visit[next.h][next.w][0] = visit[temp.h][temp.w][0] + 1; //거리 측정
					}
					if (visit[next.h][next.w][1] != 0) {
						visit[next.h][next.w][1] = min(visit[next.h][next.w][1], visit[temp.h][temp.w][1] + maze[next.h][next.w]);
					}
					else {
						visit[next.h][next.w][1] = visit[temp.h][temp.w][1] + maze[next.h][next.w]; //벽 부순 횟수 측정
					}
					visit[next.h][next.w][2] = 1;
					explore.push(next); //queue에 넣어주기.
				}
			}
		}
	}



	return;
}

int main() {

	int n, m; //높이와 가로 지정
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // (1,1) 부터 (n,m)까지
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp - '0'; //maze 설정.
		}
	}

	queue<node> explore; //queue 생성.
	node temp; //임시 노드 생성.
	temp.w = 1; //처음 시작은
	temp.h = 1; // (1,1) 부터
	explore.push(temp); // queue에 넣어주자.

	while (explore.size() > 0) { //queue 사이즈가 0 이상일때
		if (explore.size() < 1) //queue 사이즈가 0이 된다면 break.
		{
			break;
		}
		BFS(explore, n, m); //BFS 계속 돌리기.
	}

	if (maze[n][m] == 0) { //만일 도착을 아무도 안 했다면
		cout << -1 << endl; //-1 출력
	}
	else {
		cout << maze[n][m]+1 << endl; //아니라면 도착 지점까지 걸린 거리 출력.
	}

	return 0;
}