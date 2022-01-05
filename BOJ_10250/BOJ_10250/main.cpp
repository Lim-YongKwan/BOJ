#include<iostream>

using namespace std;

int main() {

	int h;
	int w;
	int n;

	int testcase;
	cin >> testcase;

	int first = 0; 
	int last = 0;

	for (int T = 1; T <= testcase; T++) {

		first = 0;
		last = 0;
		//시작은 101

		//2 2 4
		//앞의 숫자 : 4/2 = 2
		//뒤의 숫자 : 몫이 0이라서 2
		//6 12 7
		// 102
		//앞의 숫자 :7/6 = 1
		//뒤의 숫자 : 몫이 1인데 6*1<7 이니 몫을 1개 증가.
		//2 10 1
		//앞의 숫자 : 1/2 = 0
		//뒤의 숫자 : 몫이 1이고 0*2 <1이니 예외 처리하자.
		//2 2 4
		// 202
		// 앞의 숫자 : 4/2 = 2
		//뒤의 숫자 : 몫이 0이라서 2
		//99 99 1
		//앞의 숫자 : 1/ 99 = 0
		// 뒤의 숫자 : 몫이 1이. 0*99<1.....
		//3 10 2
		//201
		//앞의 숫자 : 2/3 = 0
		//뒤의 숫자 : 몫이 2이니 그대로 2

		cin >> h >> w >> n;
		first = n % h;

		first *= 10;

		if (first == 0)
			first=h*10;


		last = n / h;

		if (n > h*last) {
			last++;
		}

		if (last >= 10)
			first /= 10;

		cout << first << last << endl;

	}
	return 0;
}