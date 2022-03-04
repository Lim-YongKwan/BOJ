#include<iostream>
#include<queue>
#define endl "\n"

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<int>> minor;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (minor.size() > 0) {
				cout << minor.top()<<endl;
				minor.pop();
			}
			else {
				cout << "0" << endl;
			}
		}
		else {
			minor.push(temp);
		}
	}

	return 0;
}