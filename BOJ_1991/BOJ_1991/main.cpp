//#include<iostream>
//
//using namespace std;
//
//struct Node {
//	char data;
//	struct Node* left;
//	struct Node* right;
//}Node;
//
//struct Node* newNode(char item) {
//	struct Node* item;
//	item.key = item;
//}
//
//class preorder {
//	preorder.left;
//	cout << root->data << endl;
//	preorder.right;
//}
//
//
//int main() {
//
//	int n;
//	cin >> n;
//	char a, b, c;
//	for (int i = 0; i < n; i++) {
//		cin >> a >> b >> c;
//
//	}
//
//
//
//	return 0;
//}

#include <string>
#include <vector>
#include<queue>

using namespace std;

int truck_pop(vector<int>& truck_weights, int bridge_length, int weight) {
    queue<int> truck_sum;
    vector<int>::iterator iter;
    iter = truck_weights.begin();

    int total = 0;
    int count = 0;
    int answer = 0;

    for (iter = truck_weights.begin();iter != truck_weights.end();iter++) {

        if (truck_weights.size() == 0) {
            break;
        }

        if (count == bridge_length) {
            count = 0;
        }

        if (truck_sum.size() >= bridge_length || total >= weight) {
            answer += (bridge_length - count);//answer를 증가시키고 
            count = 0;
            truck_sum.pop();
        }

        truck_sum.push(*iter);
        total += truck_sum.front();
        count++;
        answer++;
    }
    if (truck_sum.size() != 0) {
        answer += bridge_length;
    }
    return answer;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int truck = 0;

    answer = truck_pop(truck_weights, bridge_length, weight);

    return answer;
}