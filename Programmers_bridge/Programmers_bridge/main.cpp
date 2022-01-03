#include <string>
#include<iostream>
#include <vector>
#include<queue>
using namespace std;


int truck_pop(vector<int>& truck_weights, int bridge_length, int weight) {
    queue<int> truck_sum;
    vector<int>::iterator iter;
    iter = truck_weights.begin();

    int total = 0; //다리위에 현재 트럭의 무게 하중.
    int answer = 0; //answer

    while (true) {

        if (truck_sum.size() == bridge_length) { //만일 다리에 트럭이 가득 찼다면 
            total -= truck_sum.front(); // 다리의 무게에서 앞의 트럭을 빼주자.
            truck_sum.pop(); //제일 앞의 트럭 제거하기.
        }
        if (total + *iter <= weight) { //만일 다음 트럭을 더한 값이 무게하중보다 작다면
            truck_sum.push(*iter); //vector의 다음 수를 넣자, 다음 트럭을 집어 넣자.
            total += *iter; //무게 하중에 트럭 값 추가.
            iter++; //iterator 다음 벡터값으로 조정.
            if (iter == truck_weights.end()) { // 만일 마지막 변수에 도달했다면
                answer++; // 마지막 트럭이 탔으니 동작을 한번 추가.
                break; //break.
            }
        }

        else if (total + *iter > weight) { //만일 트럭 무게가 다리의 하중을 넘어선다면
            truck_sum.push(0); //0을 집어넣자.
        }

        answer++; //answer 증가.

    }

    if (truck_sum.size() >= 1) { //queue가 1개 이상 있다면/ queue 안에 얼마나 있든 마지막 숫자는 다리 길이만큼 건너야 함.
        answer += bridge_length; //다리 길이를 더해주자.
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