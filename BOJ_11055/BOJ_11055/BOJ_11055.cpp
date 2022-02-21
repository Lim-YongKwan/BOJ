#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"

using namespace std;

int main() {

	int n;
	cin >> n;

	int temp;

	vector<int> sequence;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}

	vector<long long> DP;

	DP.push_back(sequence[0]); //DP[0]�� sequence[0]

	for (int i = 1; i < n; i++) { //������[0] ���� �� ������ 1���� ����.
		DP.push_back(sequence[i]); //�ش� �������� ���� 0���� �־����� XXXXXXXXXXX 0�� ������ ���� �߻�(3, 105 31 104) �ش� ������ ���� �־�����. 
		for (int j = 0; j < i; j++) { //j�� ��ȯ�ؾ� �ϴ� 0���� i�� ���� ������.
			if (sequence[i] > sequence[j]) { //���� ���� sequence ���� ������ sequecne ������ ũ�ٸ�
				if(DP[i] <= DP[j] + sequence[i]) //���� DP �� �ٲ� DP���� �۴ٸ�
					DP[i] = DP[j] + sequence[i]; // DP �� ����.
			}
		}
	}

	//for (int i = 0; i < n; i++) { // ����� üũ�� ���� ��¹�.
	//	cout << "DP : " << DP[i] << " ";
	//}
	//cout << endl;

	cout << *max_element(DP.begin(), DP.end()) << endl; //���� ū �� ���

	return 0;
}