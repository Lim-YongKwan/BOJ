#include<iostream>

using namespace std;

int main() {

	int hour=0;
	int minute=0;
	cin >> hour >> minute;

	if (minute>=45) {
		cout << hour << " " << minute - 45 << endl;
	}
	else {
		if(hour == 0){
			cout << "23 " << minute + 60 - 45 << endl;
		}
		else {
			cout << hour -1 <<" " << minute + 60 - 45 << endl;
		}
	}

	return 0;
}