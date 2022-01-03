#include<iostream>
#include<algorithm>
#include<cstring>
#include<numeric>
#define endl "\n"


using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int m;
	cin >> n;
	cin >> m;

	int relations[55] = { 0, };

	int a;
	int b;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		relations[a] = b;
	}

	int count = 0;
	int total_count = 0;

	int relation_check[55] = { 0, };

	for (int j = 1; j <= n; j++) {
		memset(relation_check, 0, sizeof(relation_check)); //초기화
		count = 0; //카운트 초기화
		for (int i = j; i <= n; i++) { // i는 j부터 n까지.
			if (relation_check[i] != 0) { //만일 릴레이션 체크가 0이 아니라면
				continue; //다음 숫자로
			}
			if (relations[i] == 0) //만일 릴레이션이 0이라면
				continue; //다음 숫자로
			if (relation_check[relations[i]] != 0) //만일 릴레이션 체크에서 릴레이션의 다음값이 0이 아니라면
				continue; //다음 숫자로
			relation_check[relations[i]] = 1; //릴레이션 체크[릴레이션i]값은 1
			relation_check[i] = 1; //릴레이션 체크[i] 는 1
			//cout << " 오류 찾기 i값 : " << i << " j 값 : " << j << endl;
			count += 2; //count 2씩 증가.
		}
		total_count = max(total_count, count); 
		//cout << "total count : " << total_count << endl;
	}

	if (total_count < n || m == 0)
		cout << total_count + 1 << endl; //만일 숫자가 2의 배수가 아니라면 
	else
		cout << total_count << endl;

	
	return 0;
}