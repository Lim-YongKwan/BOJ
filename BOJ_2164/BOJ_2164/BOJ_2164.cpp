#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> card;
	int temp;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		card.push(i);
	}

	while (card.size() > 1) {
		card.pop();
		temp = card.front();
		card.pop();
		card.push(temp);
	}
	cout << card.front() << endl;

	return 0;
}