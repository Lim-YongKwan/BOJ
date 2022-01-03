#include<iostream>
#include<algorithm>
#include<cstring>
#include<numeric>
#define endl "\n"


using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int m;
	cin >> n;
	cin >> m;

	int relations[55] = { 0, };

	int a;
	int b;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		relations[a] = b;
	}

	int count = 0;
	int total_count = 0;

	int relation_check[55] = { 0, };

	for (int j = 1; j <= n; j++) {
		memset(relation_check, 0, sizeof(relation_check)); //�ʱ�ȭ
		count = 0; //ī��Ʈ �ʱ�ȭ
		for (int i = j; i <= n; i++) { // i�� j���� n����.
			if (relation_check[i] != 0) { //���� �����̼� üũ�� 0�� �ƴ϶��
				continue; //���� ���ڷ�
			}
			if (relations[i] == 0) //���� �����̼��� 0�̶��
				continue; //���� ���ڷ�
			if (relation_check[relations[i]] != 0) //���� �����̼� üũ���� �����̼��� �������� 0�� �ƴ϶��
				continue; //���� ���ڷ�
			relation_check[relations[i]] = 1; //�����̼� üũ[�����̼�i]���� 1
			relation_check[i] = 1; //�����̼� üũ[i] �� 1
			//cout << " ���� ã�� i�� : " << i << " j �� : " << j << endl;
			count += 2; //count 2�� ����.
		}
		total_count = max(total_count, count); 
		//cout << "total count : " << total_count << endl;
	}

	if (total_count < n || m == 0)
		cout << total_count + 1 << endl; //���� ���ڰ� 2�� ����� �ƴ϶�� 
	else
		cout << total_count << endl;

	
	return 0;
}