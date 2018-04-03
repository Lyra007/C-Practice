#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double sum_of_all(vector<double>each_case, int begin, unsigned long length) {
    double sum = 0;
    for(int i=begin; i<length; i++) {
        sum += each_case[i];
    }
    return sum;
}

double max_of_two(double a, double b) {
    if (a>b) return a;
    return b;
}

int findMid(int begin, int end, double target, vector<double> each_case) {
    int mid = (begin + end)/2;
    if(each_case[mid] == target) {
        return mid;
    }
    if(target > each_case[mid] && target <= each_case[mid+1]) {
        return mid+1;
    }

    if (each_case[mid] < target) {
        begin = mid;
    } else {
        end = mid;
    }

    int res = findMid(begin, end, target, each_case);
    return res;
}

double getExpectedValue(int num_in_bag, int redip_times, vector<double>each_case) {
    sort(each_case.begin(), each_case.end());
    double ep = sum_of_all(each_case, 0, each_case.size())/num_in_bag;
    if (ep<each_case[each_case.size()-1]) {
        while (redip_times) {
            int index = findMid(0, each_case.size() - 1, ep, each_case);
            double sum_of_rest = sum_of_all(each_case, index, each_case.size());
            ep = (sum_of_rest/num_in_bag) + (index/(double)num_in_bag) * ep;
            redip_times--;
        }
    }
    return ep;

}


int main() {
//    freopen("B-small-practice.in","r", stdin);
//    freopen("result.out", "w", stdout);
//
//    int test_num;
//    cin >> test_num;
//    cout << test_num <<endl;
//    for (int i=0; i<test_num; i++){
//        int num_in_bag, redip_times;
//        cin >> num_in_bag >> redip_times;
//        vector<double> each_case;
//        while(num_in_bag) {
//            double ele;
//            cin >> ele;
//            each_case.push_back(ele);
//            num_in_bag--;
//        }
//
//        double res = getExpectedValue(num_in_bag, redip_times, each_case);
//        cout << "Case #" << i+1 <<": " << res << endl;
//    }
//    fclose(stdout);

    vector<double> each_case = {11,4,7,16,1};
    double res = getExpectedValue(5, 3, each_case);
    cout <<res <<endl;
    return 0;
}