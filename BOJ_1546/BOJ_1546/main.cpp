#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	float total = 0;
	int n;
	cin >> n;
	vector<float> final_score;
	float float_a = 0;
	for (int i = 0; i < n; i++) {
		cin >> float_a;
		final_score.push_back(float_a);
	}
	int max_score = 0;
	max_score = *max_element(final_score.begin(), final_score.end());
	for (int i = 0; i < n; i++) {
		final_score[i] = (float)(final_score[i] / max_score) * 100;
		total += final_score[i];
	}
	cout <<(float)total / n << endl;

	return 0;
}