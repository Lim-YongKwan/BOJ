#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int prime[4000001];
int consecutive[4000000];
void eratos(int n) {
	prime[1] = 1;
	prime[0] = 1;
	for (int i = 2; i*i <=n; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = 1;
			}
		}
	}

	return;
}

int main() {

	int n;
	cin >> n;

	eratos(n);

	int count = 0;

	for (int i = 2; i <= n; i++) {
		if (prime[i] == 0) {
			consecutive[count] = i;
			//cout << consecutive[count] << endl;
			count++;
		}
	}

	int start = 0;
	int end = 0;
	long long total = 0;

	total += consecutive[end];
	end++;
	count = 0;
	while (start < end or start<n or end<n) {
		/*cout << endl;
		cout << "total 값 : " << total << endl;
		cout << "start 위치 : " << start << " end 위치 : " << end << endl;
		cout << "start 값 : " << consecutive[start] << " end 값 : " << consecutive[end] << endl;
		*/


		if (total < n) {
			
			total += consecutive[end];
			end++;
		}
		else if (total >= n) {
			if (total == n)
			{
				count++;
			}
			total -= consecutive[start];
			start++;
		}
		if (start >= end or consecutive[start] == 0 or end > n or start>n) {
			break;
		}
	}

	cout << count << endl;

	return 0;
}