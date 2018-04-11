#include <iostream>
using namespace std;

int main() {
    int num_total;
    cin >> num_total;
    for (int i=0; i<num_total; i++) {
        int area;
        cin >> area;

        int length = 1;
        int height = 1;
        bool is_height = true;
        while (height * length < area) {
            if(is_height) {
                height++;
                is_height = false;
            }else {
                length++;
                is_height = true;
            }
        }

        int r_prepared=0, c_prepared=0;
        while(true) {
            int r_provided, c_provided;
            cerr << r_prepared + 2 <<' '<< c_prepared + 2 <<endl;
            cout << r_prepared + 2 <<' '<< c_prepared + 2 <<endl;
            cout.flush();
            r_prepared = (r_prepared + 1 ) % (length-2);
            c_prepared = (c_prepared + 1) % (height-2);

            cin >> r_provided >> c_provided;
            if(r_provided == -1 && c_provided==-1) break;
            if(r_provided == 0 && c_provided== 0) break;
        }
    }

}

