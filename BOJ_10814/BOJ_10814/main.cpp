#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

struct Node {
	int year;
	string name;
	int index;
};

bool sorting(const Node& a,const Node& b) {
	if (a.year == b.year) {
		return a.index < b.index;
	}
	else if (a.year < b.year) {
		return b.year > a.year;
	}
	else
		return false;
}

int main() {

	int n;
	cin >> n;
	
	vector<Node> online;
	
	Node judge;

	for (int i = 0; i < n; i++) {
		cin >> judge.year >> judge.name;
		judge.index = i;
		online.push_back(judge);
	}
	
	sort(online.begin(), online.end(), sorting);
	
	for (auto i : online) {
		cout << i.year << " " << i.name << endl;
	}


	return 0;
}