#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;


int main() {

	int n;
	cin >> n;

	vector<long long> card;
	long long temp = 0;
	for (int i = 0; i < n; i++){
		cin >> temp;
		card.push_back(temp);
	}

	sort(card.begin(), card.end());

	temp = card[0];
	long long temp_max =0;
	long long max = 0;
	long long max_index = 0;
	
	for (int i = 1; i < n; i++) {
		if (card[i] == temp) {
			temp_max++;
		}
		else if (card[i] != temp) {
			temp_max = 0;
			temp = card[i];
		}
		if (temp_max > max) {
			max = temp_max;
			max_index = i;
		}
	}

	cout << card[max_index] << endl;

	return 0;
}