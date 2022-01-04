#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> replace;

	int a;
	a = sizeof(commands) / sizeof(commands[0]);

	for (int i = 0; i < a; i++) {
		
	}
	return answer;
}

int main() {

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < 4; i++) {
		cout << vec[i] << endl;
	}

	return 0;
}