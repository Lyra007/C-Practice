#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> trouble_Sort(vector<int> single_case) {

    vector<int> odd;
    vector<int> even;
    int n = single_case.size();
    int i=0;
    bool is_odd = true;
    while (n) {
        if (is_odd) {
            odd.push_back(single_case[i]);
            is_odd = false;
        } else {
            even.push_back(single_case[i]);
            is_odd = true;
        }
        i++;
        n--;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    vector<int> res;
    i = 0;
    n = single_case.size();
    while(n>1) {
        res.push_back(odd[i]);
        res.push_back(even[i]);
        n -= 2;
        i++;
    }
    if(n==1) res.push_back(odd[i]);

    return res;
}



int compareTwo(vector<int> single_case) {
    vector<int> trouble= trouble_Sort(single_case);
    sort(single_case.begin(), single_case.end());
    for(int i=0; i<single_case.size(); i++) {
        if (single_case[i] != trouble[i]) return i;
    }
    return -1;
}


int main() {

//    freopen("test","r", stdin);
    int num_case;
    cin >> num_case;
    for(int i=0; i<num_case; i++) {
        int total;
        vector<int> single_case;
        cin >> total;
        while(total) {
            int ele;
            cin >> ele;
            single_case.push_back(ele);
            total--;
        }
        int res = compareTwo(single_case);
        cout << "Case #" << i+1 <<": ";
        if (res ==-1 ) {
            cout << "OK" <<endl;
        } else {
            cout << res << endl;
        }


    }
    return 0;
}