#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;

int main() {


	int a;
	int b;
	int c;
	vector<int> pytha;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		pytha.push_back(a);
		pytha.push_back(b);
		pytha.push_back(c);
		sort(pytha.begin(), pytha.end());

		if ((pytha[0] * pytha[0] + pytha[1] * pytha[1] == pytha[2] * pytha[2])) {
			cout << "right" << endl;
		}
		else
			cout << "wrong" << endl;
		pytha.clear();
	}


	return 0;
}