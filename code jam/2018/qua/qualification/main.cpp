#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, string> Case;


int ifPossible(Case single_case){
    string str = single_case.second;
    int count = 0;
    for (int i = 0; i<str.size(); i++) {
        if (str[i] == 'S') count++;
    }
    //all is C
    if (count == 0) {
        return 0;
    } else {
        int res = count;
        //impossible
        if(res > single_case.first) return -1;
        //possible
        return 1;
    }
}

int countTotal(string s) {
    int sum=0;
    int single_sum=1;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'C') single_sum *= 2;
        if (s[i] == 'S') sum += single_sum;
    }
    return sum;
}
Case changeOrder(Case single_case) {
    string program = single_case.second;

    int c_index, s_index = program.size();
    for(int i = program.size()-1; i>0; i--) {
        if (program[i] =='S') {
            s_index = i;
            if (i>=1 && program[i-1] == 'C') {
                c_index = i-1;
                break;
            }
        }
    }
    if (c_index != program.size() && s_index != program.size()) {
        program[c_index] ='S';
        program[s_index] ='C';
        single_case.second = program;
    }
    //c_index ==  program.size() all is S
    //s_index ==  program.size() all is C, impossible to occur here
    return single_case;
}


int getMin(Case single_case) {
    int ans= ifPossible(single_case);
    if (ans == 1) {
        int res = countTotal(single_case.second);
        int count = 0;
        while(res > single_case.first) {
            single_case = changeOrder(single_case);
            count++;
            res = countTotal(single_case.second);
        }
        ans = count;
    }
    return ans;
}


int main() {
//    freopen("input_file_name.in","r",stdin);
//    freopen("output_file_name.out","w",stdout);

    int case_num;
    cin >> case_num;
    vector<Case> cases;
    for(int i=0; i<case_num; i++) {
        int total_damage;
        string program;
        cin>>total_damage>>program;
        cases.push_back(Case(total_damage, program));
    }
    for(int i=0; i<case_num; i++) {
        int ans = getMin(cases[i]);
        cout <<"Case #" << i+1 <<": ";
        if(ans!=-1) {
            cout<<ans<<endl;
        } else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
