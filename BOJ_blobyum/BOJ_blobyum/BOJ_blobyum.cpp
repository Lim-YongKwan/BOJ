#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;


int dp[100001] = { 0, };

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	int temp = 0;
	int blobyum[100001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> blobyum[i];
	}

	int max_temp = 0;
	int answer = 0;
	int start = 0;
	int end = 0;

	temp = 1;
	while (start<n) {
		max_temp += blobyum[end];
		end++;
		temp++;
		if (temp == k+1) {
			answer = max(answer,max_temp);
			max_temp -= blobyum[start];
			temp --;
			start++;
			//cout << "max �� : " << answer << endl;
			//cout << "start ��ġ : " << start << endl;
		}
		if (end == n ) {
			//cout << "end �ʱ�ȭ : " << end << endl;
			end = 0;
		}
	}

	cout << answer << endl;

	return 0;
}
