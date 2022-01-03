#include <string>
#include<iostream>
#include <vector>
#include<queue>
using namespace std;


int truck_pop(vector<int>& truck_weights, int bridge_length, int weight) {
    queue<int> truck_sum;
    vector<int>::iterator iter;
    iter = truck_weights.begin();

    int total = 0; //�ٸ����� ���� Ʈ���� ���� ����.
    int answer = 0; //answer

    while (true) {

        if (truck_sum.size() == bridge_length) { //���� �ٸ��� Ʈ���� ���� á�ٸ� 
            total -= truck_sum.front(); // �ٸ��� ���Կ��� ���� Ʈ���� ������.
            truck_sum.pop(); //���� ���� Ʈ�� �����ϱ�.
        }
        if (total + *iter <= weight) { //���� ���� Ʈ���� ���� ���� �������ߺ��� �۴ٸ�
            truck_sum.push(*iter); //vector�� ���� ���� ����, ���� Ʈ���� ���� ����.
            total += *iter; //���� ���߿� Ʈ�� �� �߰�.
            iter++; //iterator ���� ���Ͱ����� ����.
            if (iter == truck_weights.end()) { // ���� ������ ������ �����ߴٸ�
                answer++; // ������ Ʈ���� ������ ������ �ѹ� �߰�.
                break; //break.
            }
        }

        else if (total + *iter > weight) { //���� Ʈ�� ���԰� �ٸ��� ������ �Ѿ�ٸ�
            truck_sum.push(0); //0�� �������.
        }

        answer++; //answer ����.

    }

    if (truck_sum.size() >= 1) { //queue�� 1�� �̻� �ִٸ�/ queue �ȿ� �󸶳� �ֵ� ������ ���ڴ� �ٸ� ���̸�ŭ �ǳʾ� ��.
        answer += bridge_length; //�ٸ� ���̸� ��������.
    }

    return answer;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    answer = truck_pop(truck_weights, bridge_length, weight);

    return answer;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    answer = truck_pop(truck_weights, bridge_length, weight);
    cout << "answer : " << answer << endl;
    return answer;
}
int main() {

    int n;
    int w;
    int c;
    cin >> n >> w >> c;

    vector<int> truck;

    for (int i = 0; i < c; i++) {
        int vec;
        cin >> vec;
        truck.push_back(vec);
        
    }
    
    solution(n,w,truck);

    return 0;
}