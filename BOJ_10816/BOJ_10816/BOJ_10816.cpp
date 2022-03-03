#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main() {

	int n;
	vector<int> card;
	vector<int> find_card;
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		card.push_back(temp);
	}
	sort(card.begin(), card.end());

	int search_num;
	cin >> search_num;

	for (int i = 0; i < search_num; i++) {
		cin >> temp;
		find_card.push_back(upper_bound(card.begin(), card.end(), temp)- lower_bound(card.begin(), card.end(), temp));
	}

	for (int i = 0; i < find_card.size(); i++) {
		cout << find_card[i] << " ";
	}



	return 0;
}