#include<iostream>
#include<string>
#include<limits>
#include<vector>
using namespace std;


int main() {

	int testcase;
	cin >> testcase;
	
	for (int T = 1; T <= testcase; T++) {

		
		string s; //RDD, RDRDR�� �޾��ִ� string ����.
		cin >> s;
		
		int n = 0;	//���ڰ� ��� �������� ���� ����.
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

		vector<int> AC;	//���ڸ� �־��� ����.

		char temp;
		int int_temp=0;

		//AC ���Ϳ� �־��ֱ�.[1,1,1,1] �̶�� [�� temp�� �ް� 1�� int_temp�� �޾Ƽ� AC���Ϳ� �н��Ѵ�.

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
		

		//AC/�� ���ڰ� ����ִ�.

		int num = 0; //R�� ���� ����.
		int count = 0; //D�� �� ����.

		int count_front = 0;//�պκ��� ���� ���� ����.
		

		//������ �޺κа� �պκ��� D�� ���� ����� �κ�.

		for (int i = 0; i < s.length(); i++) {

			if (s[i] == 'R') {	//���� R�̸� num���� �ø���.
				num++;
			}
			else if (s[i] == 'D') {	//���࿡ D�̸鼭
				count++;	//D�� ���ں��� ���ٸ� break.
				if (count > n)
					break;
				if (num % 2 == 1) {	//R�� Ȧ�����
					AC.pop_back();	//�ڿ��Ÿ� ������.
				}
				else if (num % 2 == 0) { //R�� ¦�����
					AC[count_front] = -1;	//���� ���ڸ� -1�� �ٲ���.
					count_front++;	//���� ������ ��ġ�� �ľ��� count_front ����.
				}
			}
		}

		if (count > n) {	//���࿡ D�� ���ں��� ũ�ٸ�
			cout << "error" << endl;	//error ����� ���� �׽�Ʈ ���̽��� �Ѱ��ֱ�.
			continue;
		}

		int space_num = 0;	//ó�� ���ڸ� �����ϰ� �ι�° ���ں��� ','�� �ֱ� ���� ���� ����. �������� ','�� ������ �� �����ϱ� ���ؼ� ����� ���. Ŀ���� �̵��ؼ� �������� ���� �� �ִ� ����� ã���� �������� �׷��� ����.

		if (num % 2 == 0) { //���� R�� ¦����� => ó������ ���.
			cout << "[";
			for (int i = 0; i < AC.size(); i ++) {
				if (AC[i] == -1) //���� ���ڰ� ������� ���� ���ڷ� �Ѱ�����.
					continue;
				
				if (space_num > 0)
					cout << ',';
				cout << AC[i];
				space_num++;
			}
			cout << "]";
			cout << endl;

		}
		else if (num % 2 == 1) {	//���� R�� Ȧ����� => �ڿ������� ���.
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