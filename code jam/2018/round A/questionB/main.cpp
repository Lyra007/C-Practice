#include <iostream>
#include <vector>
#include <algorithm>
#include<iomanip>

using namespace std;

long double sum_of_all(vector<long double>each_case, long long int begin, unsigned long length) {
    long double sum = 0;
    for(long long int i=begin; i<length; i++) {
        sum += each_case[i];
    }
    return sum;
}

//long double max_of_two(long double a, long double b) {
//    if (a>b) return a;
//    return b;
//}

long long int findMid(long long int begin, long long int end, long double target, vector<long double> each_case) {
    long long int mid = (begin + end)/2;
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

    long long int res = findMid(begin, end, target, each_case);
    return res;
}

long double getExpectedValue(long long int num_in_bag, long long int redip_times, vector<long double>each_case) {
    sort(each_case.begin(), each_case.end());
    long double ep = sum_of_all(each_case, 0, each_case.size())/num_in_bag;
    if (ep<each_case[each_case.size()-1]) {
        while (redip_times) {
            long long int index = findMid(0, each_case.size() - 1, ep, each_case);
            long double sum_of_rest = sum_of_all(each_case, index, each_case.size());
            ep = (sum_of_rest/num_in_bag) + (index/(long double)num_in_bag) * ep;
            redip_times--;
        }
    }
    return ep;

}


int main() {
    freopen("B-large-practice.in","r", stdin);
    freopen("result.out", "w", stdout);

    ios::sync_with_stdio(false);

    long long int test_num;
    cin >> test_num;
    for (long long int i=0; i<test_num; i++){
        long long int num_in_bag, redip_times;
        cin >> num_in_bag >> redip_times;
        long long int tmp = num_in_bag;
        vector<long double> each_case;
        while(tmp) {
            long double ele;
            cin >> ele;
            each_case.push_back(ele);
            tmp--;
        }

        cout << setiosflags(ios::fixed);  //保证setprecision()是设置小数点后的位数。
        long double res = getExpectedValue(num_in_bag, redip_times, each_case);
        cout << "Case #" << i+1 <<": " ;
        cout << setprecision(6)<< res << endl;
    }

    return 0;
}