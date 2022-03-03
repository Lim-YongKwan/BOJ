#include<iostream>
#include<queue>
#include<algorithm>
#define endl "\n"

using namespace std;

int maze[1001][1001]; // �̷� ����
int visit[1001][1001][3]; //�湮�� �ߴ��� Ȯ�� visit[n][m][0] �� �Ÿ� Ƚ���̰� visit[n][m][1] �� ���� �μ̴��� �ƴ��� Ȯ�ο�. visit[n][m][2] �� �湮 Ȯ��.

struct node {
	int h; // ���� ��
	int w; // ���� ��
};

int directions[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void BFS(queue<node>& explore, int n ,int m) {

	node temp; //queue���� ó�� �κ��� ������ �ӽ� ���
	temp = explore.front(); //ó�� queue�� �����´�.
	explore.pop(); //queue�� ó�� �κ��� ���� ������ �״�� ���ش�.

	if (temp.w == m+1 or temp.w == 0 or temp.h == 0 or temp.h == n+1) { //Ȥ�� ���� �صаǵ� ���ص� �� �� ���ּ� �ּ� ó�� �߽��ϴ�.
		return;
	}
	if (visit[temp.h][temp.w][1] == 2) {
		return;
	}

	if (temp.h == n and temp.w == m) { //���� maze�� ��������
		if (maze[n][m] != 0) { //�̹� ���� �湮�ߴٸ�
			maze[n][m] = min(maze[n][m],visit[n][m][0]); // ���簪�� ���ؼ� �ּڰ����� �ٲ���.
		}
		else { //���� �ƹ��� �� �Դٸ�
			maze[n][m] = visit[n][m][0]; //���簪���� �ٲ���.
		}
	}

	for (int i = 0; i < 4; i++) { //4�� ����.
		if (visit[temp.h + directions[i][0]][temp.w + directions[i][1]][2] == 0) { //���� ���� �̹� �湮���� �ʾҰ�
			if (temp.h + directions[i][0] != n + 1 and temp.h + directions[i][0] != 0 and temp.w + directions[i][1] != m + 1 and temp.w + directions[i][1] != 0) { //���� �ȿ� ������
				if (visit[temp.h][temp.w][1] + maze[temp.h + directions[i][0]][temp.w + directions[i][1]] != 2) { // ���� 2���̻� �� �մ´ٸ�
					node next; // ���� ��� ����
					next.h = temp.h + directions[i][0]; // ���� ����
					next.w = temp.w + directions[i][1]; // ���� ����
					if (visit[next.h][next.w][0] != 0) {
						visit[next.h][next.w][0] = min(visit[next.h][next.w][0], visit[temp.h][temp.w][0] + 1);
					}
					else {
						visit[next.h][next.w][0] = visit[temp.h][temp.w][0] + 1; //�Ÿ� ����
					}
					if (visit[next.h][next.w][1] != 0) {
						visit[next.h][next.w][1] = min(visit[next.h][next.w][1], visit[temp.h][temp.w][1] + maze[next.h][next.w]);
					}
					else {
						visit[next.h][next.w][1] = visit[temp.h][temp.w][1] + maze[next.h][next.w]; //�� �μ� Ƚ�� ����
					}
					visit[next.h][next.w][2] = 1;
					explore.push(next); //queue�� �־��ֱ�.
				}
			}
		}
	}



	return;
}

int main() {

	int n, m; //���̿� ���� ����
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // (1,1) ���� (n,m)����
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			maze[i][j] = temp - '0'; //maze ����.
		}
	}

	queue<node> explore; //queue ����.
	node temp; //�ӽ� ��� ����.
	temp.w = 1; //ó�� ������
	temp.h = 1; // (1,1) ����
	explore.push(temp); // queue�� �־�����.

	while (explore.size() > 0) { //queue ����� 0 �̻��϶�
		if (explore.size() < 1) //queue ����� 0�� �ȴٸ� break.
		{
			break;
		}
		BFS(explore, n, m); //BFS ��� ������.
	}

	if (maze[n][m] == 0) { //���� ������ �ƹ��� �� �ߴٸ�
		cout << -1 << endl; //-1 ���
	}
	else {
		cout << maze[n][m]+1 << endl; //�ƴ϶�� ���� �������� �ɸ� �Ÿ� ���.
	}

	return 0;
}