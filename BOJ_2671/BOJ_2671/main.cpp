#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

int main() {

	//3가지로 나뉜다.
	//1번째는 100으로
	//2번째는 1
	//3번째는 01
	//100은 뒤가 아무리 길어져도 상관이 없음. 1000/10000/1000000/1000000000
	//1도 아무리 뒤가 길어져도 상관이 없음, 1/11/111/11111/1111111
	//단 100의 뒤에 1이 나와야 한다.
	//01은 1001의 앞이든 1001의 뒤이든 상관이 없다.
	//이상의 조건을 달고 있는한 아무리 반복을 아무리 하여도 상관이 없다.
	
	//10010111 은 false 왜냐하면 이와 같은 경우에는 100101까지는 괜찮으나 그 뒤에 1이 연속으로 올수가 없기 때문이다. 만약 10010101111이었으면 true;
	//100000000001101 은 true 왜냐하면 이와같은 경우에는 가운데 0과 1만 반복되었을 뿐 조건을 어긴 곳이 없다.
	
	string s;
	cin >> s;

	queue<char> submarine;
	for (int i = 0;i<s.length(); i++) {
		submarine.push(s[i]);
	}
	if (s.substr(s.length() - 3, 3) == "100") {
		cout << "NOISE" << endl;
		return 0;
	}


	for (int i = 0; i < s.length(); i++) {
		//1001100
		if (s.substr(i,3) == "100")
		{
			//cout << "100 : "<<i << endl;
			i += 3;
			submarine.pop();
			submarine.pop();
			submarine.pop();
			//1이 나올때까지 0을 계속 지우자.
			while (s[i] == '0') {
				submarine.pop();
				i++;
				
			}
			if (s[i] == '1')
			{
				//100 다음이 1이라면 
				submarine.pop();
				i++;
			}
			else {
				//만일 100다음이 1이 아니라면 NOISE
				cout << "NOISE" << endl;
				return 0;
			}
			while (s[i] == '1') {
				//1001다음에 다시 100이 나올 가능성도 있다.
				if (s.substr(i, 3) == "100")
				{
					//처음으로 돌아가기.
					break;
				}
				//cout<<"1 : " << i << endl;
				submarine.pop();
				i++;
			}
			i--;
		}
		if (s.substr(i, 2) == "01") {
			//지우자.
		//	cout<<"01 : " << i << endl;
			i ++;
			submarine.pop();
			submarine.pop();
		}
		//반복
	}

	if (submarine.size() != 0) {
		cout << "NOISE" << endl;
	}
	else {
		cout << "SUBMARINE" << endl;
	}
	return 0;
}