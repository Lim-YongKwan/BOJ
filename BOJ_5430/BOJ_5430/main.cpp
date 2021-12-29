#include<iostream>
#include<string>
#include<limits>
#include<vector>
using namespace std;


int main() {

	int testcase;
	cin >> testcase;
	
	for (int T = 1; T <= testcase; T++) {

		
		string s; //RDD, RDRDR을 받아주는 string 변수.
		cin >> s;
		
		int n = 0;	//숫자가 몇개가 들어올지를 세는 변수.
		cin >> n;
		
		if (n == 0) {
			string string_temp;
			cin >> string_temp;
			if (s.find("D") == string::npos) {
				cout << "[]" << endl;
				continue;
			}
			else {
				cout << "error" << endl;
				continue;
			}

		}

		vector<int> AC;	//숫자를 넣어줄 변수.

		char temp;
		int int_temp=0;

		//AC 벡터에 넣어주기.[1,1,1,1] 이라면 [은 temp가 받고 1은 int_temp가 받아서 AC벡터에 패스한다.

		for (int i = 0; i <= 2 * n;i++) {
			if (i% 2 == 0) {
				cin >> temp;
			}
			else if(i % 2 == 1)
			{
				cin >> int_temp;
				AC.push_back(int_temp);
			
			}
		}
		

		//AC/에 숫자가 들어있다.

		int num = 0; //R을 세는 숫자.
		int count = 0; //D를 한 숫자.

		int count_front = 0;//앞부분의 수를 세는 변수.
		

		//벡터의 뒷부분과 앞부분을 D에 따라서 지우는 부분.

		for (int i = 0; i < s.length(); i++) {

			if (s[i] == 'R') {	//만약 R이면 num값을 올린다.
				num++;
			}
			else if (s[i] == 'D') {	//만약에 D이면서
				count++;	//D가 숫자보다 많다면 break.
				if (count > n)
					break;
				if (num % 2 == 1) {	//R이 홀수라면
					AC.pop_back();	//뒤에거를 빼주자.
				}
				else if (num % 2 == 0) { //R이 짝수라면
					AC[count_front] = -1;	//앞의 숫자를 -1로 바꾸자.
					count_front++;	//앞의 숫자의 위치를 파악할 count_front 변수.
				}
			}
		}

		if (count > n) {	//만약에 D가 숫자보다 크다면
			cout << "error" << endl;	//error 출력후 다음 테스트 케이스로 넘겨주기.
			continue;
		}

		int space_num = 0;	//처음 숫자를 제외하고 두번째 숫자부터 ','를 넣기 위해 만든 변수. 마지막에 ','로 끝나는 걸 방지하기 위해서 만들어 줬다. 커서를 이동해서 마지막을 없앨 수 있는 방법을 찾으면 다음부턴 그렇게 쓰자.

		if (num % 2 == 0) { //만일 R이 짝수라면 => 처음부터 출력.
			cout << "[";
			for (int i = 0; i < AC.size(); i ++) {
				if (AC[i] == -1) //만일 숫자가 음수라면 다음 숫자로 넘겨주자.
					continue;
				
				if (space_num > 0)
					cout << ',';
				cout << AC[i];
				space_num++;
			}
			cout << "]";
			cout << endl;

		}
		else if (num % 2 == 1) {	//만일 R이 홀수라면 => 뒤에서부터 출력.
			cout << "[";
			for (int i = AC.size()-1; i >= 0; i --) {
				if (AC[i] == -1)
					continue;
				if (space_num > 0)
					cout << ",";
				cout << AC[i];
				space_num++;
			}
			cout << "]";
			cout << endl;
		}
		
	}

	return 0;
}