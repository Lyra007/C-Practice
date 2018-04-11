#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int total_case;
	cin >> total_case;

	for(int i = 0; i<total_case; i++) {

		int area;
		cin >> area;
		int height = 3;
		int length = 1;
		bool isHeight = true;
		while (height * length <area) {
			if (isHeight) {
				height++;
				isHeight = false;
			} else {
				length++;
				isHeight = true;

			}
		}

		int r = 0, c = 0;
		int rc, rr;

		while(true) {
			cout << 2 + r <<' '<< 2 + c <<endl;
			cout.flush();
			c = ( 1 + c ) % (height - 2);
			r = ( 1 + r ) % (length - 2);
			cin >> rc >> rr;

			if((rc == 0) && (rr == 0)) break;
			if((rc == -1) && (rc == -1)) return 0;
		}

	}

}


